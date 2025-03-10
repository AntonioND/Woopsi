#include "label.h"
#include "graphicsport.h"

using namespace WoopsiUI;

Label::Label(s16 x, s16 y, u16 width, u16 height, const WoopsiString& text, GadgetStyle* style) : Gadget(x, y, width, height, style) {
	_hAlignment = TEXT_ALIGNMENT_HORIZ_CENTRE;
	_vAlignment = TEXT_ALIGNMENT_VERT_CENTRE;

	_flags.borderless = true;
	
	_borderSize.top = 3;
	_borderSize.right = 3;
	_borderSize.bottom = 3;
	_borderSize.left = 3;

	_textX = 0;
	_textY = 0;

	setText(text);

	calculateTextPositionHorizontal();
	calculateTextPositionVertical();
}

void Label::drawContents(GraphicsPort* port) {
	if (isEnabled()) {
		port->drawText(_textX, _textY, getFont(), _text, 0, _text.getLength(), getTextColour());
	} else {
		port->drawText(_textX, _textY, getFont(), _text, 0, _text.getLength(), getDarkColour());
	}
}

void Label::drawBorder(GraphicsPort* port) {
	port->drawFilledRect(0, 0, getWidth(), getHeight(), getBackColour());

	// Stop drawing if the gadget indicates it should not have an outline
	if (isBorderless()) return;

	port->drawBevelledRect(0, 0, getWidth(), getHeight(), getShadowColour(), getShineColour());
}

void Label::calculateTextPositionVertical() {

	Rect rect;
	getClientRect(rect);

	switch (_vAlignment) {
		case TEXT_ALIGNMENT_VERT_CENTRE:
			_textY = (rect.height - getFont()->getHeight()) >> 1;
			break;
		case TEXT_ALIGNMENT_VERT_TOP:
			_textY = 0;
			break;
		case TEXT_ALIGNMENT_VERT_BOTTOM:
			_textY = rect.height - getFont()->getHeight();
			break;
	}
}

void Label::calculateTextPositionHorizontal() {

	Rect rect;
	getClientRect(rect);
	
	switch (_hAlignment) {
		case TEXT_ALIGNMENT_HORIZ_CENTRE:
			_textX = (rect.width - getFont()->getStringWidth(_text)) >> 1;
			break;
		case TEXT_ALIGNMENT_HORIZ_LEFT:
			_textX = 0;
			break;
		case TEXT_ALIGNMENT_HORIZ_RIGHT:
			_textX = rect.width - getFont()->getStringWidth(_text);
			break;
	}
}

void Label::setTextAlignmentHoriz(TextAlignmentHoriz alignment) {
	_hAlignment = alignment;
	calculateTextPositionHorizontal();

	markRectsDamaged();
}

void Label::setTextAlignmentVert(TextAlignmentVert alignment) {
	_vAlignment = alignment;
	calculateTextPositionVertical();

	markRectsDamaged();
}

void Label::setText(const WoopsiString& text) {

	markTextRectDamaged();

	_text.setText(text);

	calculateTextPositionHorizontal();

	markTextRectDamaged();

	if (raisesEvents()) {
		_gadgetEventHandler->handleValueChangeEvent(*this);
	}
}

void Label::appendText(const WoopsiString& text) {

	markTextRectDamaged();

	_text.append(text);

	calculateTextPositionHorizontal();

	markTextRectDamaged();

	if (raisesEvents()) {
		_gadgetEventHandler->handleValueChangeEvent(*this);
	}
}

void Label::insertText(const WoopsiString& text, const u32 index) {

	markTextRectDamaged();

	_text.insert(text, index);

	calculateTextPositionHorizontal();

	markTextRectDamaged();

	if (raisesEvents()) {
		_gadgetEventHandler->handleValueChangeEvent(*this);
	}
}

void Label::onResize(u16 width, u16 height) {
	calculateTextPositionHorizontal();
	calculateTextPositionVertical();
}

void Label::onTextChange() {
	calculateTextPositionHorizontal();
	calculateTextPositionVertical();

	if (raisesEvents()) {
		_gadgetEventHandler->handleValueChangeEvent(*this);
	}
}

// Get the preferred dimensions of the gadget
void Label::getPreferredDimensions(Rect& rect) const {
	rect.x = _rect.getX();
	rect.y = _rect.getY();
	rect.width = 0;
	rect.height = 0;

	if (!_flags.borderless) {
		rect.width = _borderSize.left + _borderSize.right;
		rect.height = _borderSize.top + _borderSize.bottom;
	}

	rect.width += getFont()->getStringWidth(_text);
	rect.height += getFont()->getHeight();
}

void Label::setFont(FontBase* font) {
	_style.font = font;

	// Need to recalculate the text position as the font may have changed size
	calculateTextPositionHorizontal();
	calculateTextPositionVertical();

	markRectsDamaged();
}

void Label::setBorderless(bool isBorderless) {
	_flags.borderless = isBorderless;

	calculateTextPositionHorizontal();
	calculateTextPositionVertical();

	markRectsDamaged();
}

void Label::markTextRectDamaged() {

	Rect textRect;
	getClientRect(textRect);

	textRect.y += _textY;
	textRect.height = getFont()->getHeight();

	markRectDamaged(textRect);
}
