#include "scrollbarhorizontal.h"
#include "button.h"
#include "sliderhorizontal.h"
#include "woopsi.h"
#include "woopsitimer.h"

using namespace WoopsiUI;

ScrollbarHorizontal::ScrollbarHorizontal(s16 x, s16 y, u16 width, u16 height, FontBase* font) : Gadget(x, y, width, height, GADGET_BORDERLESS) {
	
	_buttonWidth = 10;

	// Create the children
	_slider = new SliderHorizontal(0, 0, width - (_buttonWidth << 1), height);
	_slider->addGadgetEventHandler(this);

	_leftButton = new Button(width - (_buttonWidth << 1), 0, _buttonWidth, height, GLYPH_ARROW_LEFT, _font);
	_leftButton->addGadgetEventHandler(this);

	_rightButton = new Button(width - _buttonWidth, 0, _buttonWidth, height, GLYPH_ARROW_RIGHT, _font);
	_rightButton->addGadgetEventHandler(this);

	// Create timer
	_scrollTimeout = 10;

	_timer = new WoopsiTimer(_scrollTimeout, true);
	_timer->addGadgetEventHandler(this);

	addGadget(_slider);
	addGadget(_leftButton);
	addGadget(_rightButton);
	addGadget(_timer);
}

const s16 ScrollbarHorizontal::getMinimumValue() const {
	return _slider->getMinimumValue();
}

const s16 ScrollbarHorizontal::getMaximumValue() const {
	return _slider->getMaximumValue();
}

const s16 ScrollbarHorizontal::getValue() const {
	return _slider->getValue();
}

const s16 ScrollbarHorizontal::getPageSize() const {
	return _slider->getPageSize();
}

void ScrollbarHorizontal::setMinimumValue(const s16 value) {
	_slider->setMinimumValue(value);
}

void ScrollbarHorizontal::setMaximumValue(const s16 value) {
	_slider->setMaximumValue(value);
}

void ScrollbarHorizontal::setValue(const s16 value) {
	_slider->setValue(value);
}

void ScrollbarHorizontal::setPageSize(s16 pageSize) {
	_slider->setPageSize(pageSize);
}

void ScrollbarHorizontal::draw(Rect clipRect) {
}

void ScrollbarHorizontal::handleActionEvent(const GadgetEventArgs& e) {

	// Check which gadget fired the event
	if (e.getSource() == _timer) {

		// Which gadget is clicked?
		if (_leftButton->isClicked()) {

			// Move the grip left
			_slider->setValue(_slider->getValue() - _slider->getValuesPerPixel());
		} else if (_rightButton->isClicked()) {

			// Move the grip right
			_slider->setValue(_slider->getValue() + _slider->getValuesPerPixel());
		}
	}
}

void ScrollbarHorizontal::handleValueChangeEvent(const GadgetEventArgs& e) {
	if (e.getSource() == _slider) {
		raiseValueChangeEvent();
	}
}

void ScrollbarHorizontal::handleClickEvent(const GadgetEventArgs& e) {

	if (e.getSource() == _leftButton) {

		// Start the timer
		_timer->start();

		// Move the grip left
		_slider->setValue(_slider->getValue() - _slider->getValuesPerPixel());

	} else if (e.getSource() == _rightButton) {

		// Start the timer
		_timer->start();

		// Move the grip right
		_slider->setValue(_slider->getValue() + _slider->getValuesPerPixel());
	}
}

void ScrollbarHorizontal::handleReleaseEvent(const GadgetEventArgs& e) {

	if ((e.getSource() == _leftButton) || (e.getSource() == _rightButton)) {

		// Stop the timer
		_timer->stop();
	}
}

void ScrollbarHorizontal::handleReleaseOutsideEvent(const GadgetEventArgs& e) {

	if ((e.getSource() == _leftButton) || (e.getSource() == _rightButton)) {

		// Stop the timer
		_timer->stop();
	}
}

void ScrollbarHorizontal::jumpGrip(u8 direction) {
	_slider->jumpGrip(direction);
}

bool ScrollbarHorizontal::resize(u16 width, u16 height) {

	// Remember current values
	s16 value = getValue();
	bool resized = false;
	bool events = raisesEvents();
	bool drawing = _flags.drawingEnabled;

	// Hide and disable drawing
	erase();
	_flags.drawingEnabled = false;

	// Disable event raising
	setRaisesEvents(false);

	if (Gadget::resize(width, height)) {

		// Resize and move children
		_slider->resize(width - (_buttonWidth << 1), height);
		_leftButton->moveTo(_slider->getWidth(), 0);
		_rightButton->moveTo(_slider->getWidth() + _buttonWidth, 0);

		// Set back to current value
		setValue(value);

		resized = true;
	}

	// Show and reset drawing
	_flags.drawingEnabled = drawing;
	redraw();

	// Reset event raising
	setRaisesEvents(events);

	return resized;
}
