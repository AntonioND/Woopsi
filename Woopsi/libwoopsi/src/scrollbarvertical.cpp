#include "scrollbarvertical.h"
#include "button.h"
#include "slidervertical.h"
#include "woopsi.h"
#include "woopsitimer.h"

using namespace WoopsiUI;

ScrollbarVertical::ScrollbarVertical(s16 x, s16 y, u16 width, u16 height, GadgetStyle* style) : Gadget(x, y, width, height, style) {

	_flags.borderless = true;

	_buttonHeight = 10;

	// Create the children
	_slider = new SliderVertical(0, 0, width, height - (_buttonHeight << 1));
	_slider->setGadgetEventHandler(this);

	GadgetBorderSize borderSize;
	borderSize.top = 1;
	borderSize.right = 1;
	borderSize.bottom = 1;
	borderSize.left = 1;

	_upButton = new Button(0, height - (_buttonHeight << 1), width, _buttonHeight, GLYPH_ARROW_UP, &_style);
	_upButton->setGadgetEventHandler(this);
	_upButton->setBorderSize(borderSize);
	_upButton->setFont(getGlyphFont());

	_downButton = new Button(0, height - _buttonHeight, width, _buttonHeight, GLYPH_ARROW_DOWN, &_style);
	_downButton->setGadgetEventHandler(this);
	_downButton->setBorderSize(borderSize);
	_downButton->setFont(getGlyphFont());

	// Create timer
	_scrollTimeout = 10;

	_timer = new WoopsiTimer(_scrollTimeout, true);
	_timer->setGadgetEventHandler(this);

	addGadget(_slider);
	addGadget(_upButton);
	addGadget(_downButton);
	addGadget(_timer);
}

const s16 ScrollbarVertical::getMinimumValue() const {
	return _slider->getMinimumValue();
}

const s16 ScrollbarVertical::getMaximumValue() const {
	return _slider->getMaximumValue();
}

const s32 ScrollbarVertical::getValue() const {
	return _slider->getValue();
}

const s16 ScrollbarVertical::getPageSize() const {
	return _slider->getPageSize();
}

void ScrollbarVertical::setMinimumValue(const s16 value) {
	_slider->setMinimumValue(value);
}

void ScrollbarVertical::setMaximumValue(const s16 value) {
	_slider->setMaximumValue(value);
}

void ScrollbarVertical::setValue(const s32 value) {
	_slider->setValue(value);
}

void ScrollbarVertical::setPageSize(s16 pageSize) {
	_slider->setPageSize(pageSize);
}

void ScrollbarVertical::handleActionEvent(Gadget &source) {
	if (&source == _timer) {
		if (_upButton->isClicked()) {

			// Move the grip up
			_slider->setValue(_slider->getValue() - _slider->getMinimumStep());
		} else if (_downButton->isClicked()) {

			// Move the grip down
			_slider->setValue(_slider->getValue() + _slider->getMinimumStep());
		}

		if (raisesEvents()) {
			_gadgetEventHandler->handleValueChangeEvent(*this);
		}
	}
}

void ScrollbarVertical::handleValueChangeEvent(Gadget &source) {
	if (&source == _slider && raisesEvents()) {
		_gadgetEventHandler->handleValueChangeEvent(*this);
	}
}

void ScrollbarVertical::handleClickEvent(Gadget &source, const WoopsiPoint &point) {
	if (&source == _upButton) {

		// Start the timer
		_timer->start();

		// Move the grip up
		_slider->setValue(_slider->getValue() - _slider->getMinimumStep());

		if (raisesEvents()) {
			_gadgetEventHandler->handleValueChangeEvent(*this);
		}

	} else if (&source == _downButton) {

		// Start the timer
		_timer->start();

		// Move the grip down
		_slider->setValue(_slider->getValue() + _slider->getMinimumStep());

		if (raisesEvents()) {
			_gadgetEventHandler->handleValueChangeEvent(*this);
		}
	}
}

void ScrollbarVertical::handleReleaseEvent(Gadget &source, const WoopsiPoint &point) {
	if ((&source == _upButton) || (&source == _downButton)) {

		// Stop the timer
		_timer->stop();
	}
}

void ScrollbarVertical::handleReleaseOutsideEvent(Gadget &source, const WoopsiPoint &point) {
	if ((&source == _upButton) || (&source == _downButton)) {

		// Stop the timer
		_timer->stop();
	}
}

void ScrollbarVertical::onResize(u16 width, u16 height) {

	// Remember current values
	s16 value = getValue();
	bool events = getRaisesEvents();

	// Disable event raising
	setRaisesEvents(false);

	// Resize and move children
	_slider->resize(width, height - (_buttonHeight << 1));
	_upButton->moveTo(0, _slider->getHeight());
	_downButton->moveTo(0, _slider->getHeight() + _buttonHeight);

	// Set back to current value
	setValue(value);

	// Reset event raising
	setRaisesEvents(events);
}
