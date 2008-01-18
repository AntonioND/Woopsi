#include "slidervertical.h"

SliderVertical::SliderVertical(s16 x, s16 y, u16 width, u16 height) : Gadget(x, y, width, height, GADGET_DRAGGABLE) {
	_outline = OUTLINE_IN;

	// Create grip
	_grip = new SliderVerticalGrip(1, 1, width - 2, 10);
	_grip->setEventHandler(this);
	addGadget(_grip);
}

SliderVertical::~SliderVertical() {
	delete _grip;
}

const s16 SliderVertical::getMinimumValue() const {
	return _minimumValue;
}

const s16 SliderVertical::getMaximumValue() const {
	return _maximumValue;
}

const s16 SliderVertical::getValue() const {
	// Calculate the current value represented by the top of the grip
	return ((_maximumValue - _minimumValue) * (_grip->getY() - _parent->getY())) / _height;
}

void SliderVertical::setMinimumValue(const s16 value) {
	_minimumValue = value;
}

void SliderVertical::setMaximumValue(const s16 value) {
	_maximumValue = value;
}

void SliderVertical::setValue(const s16 value) {

	// Convert the value to co-ordinates using fixed-point fractional values
	// for accuracy
	s32 pixelValue = ((_maximumValue << 8) - (_minimumValue << 8)) / _height;
	s16 newGripY = (value << 8) / pixelValue;

	// Move the grip
	_grip->moveTo(0, newGripY);
}

void SliderVertical::draw() {
	Gadget::draw();
}

void SliderVertical::draw(Rect clipRect) {
	GraphicsPort* port = newInternalGraphicsPort(clipRect);

	// Draw background
	port->drawFilledRect(0, 0, _width, _height, _darkColour);

	// Draw outline
	port->drawBevelledRect(0, 0, _width, _height);

	delete port;
}

bool SliderVertical::click(s16 x, s16 y) {
	if (_flags.enabled) {
		if (checkCollision(x, y)) {
			_clickedGadget = NULL;

			// Work out which gadget was clicked
			for (s16 i = _gadgets.size() - 1; i > -1; i--) {
				if (_gadgets[i]->click(x, y)) {
					break;
				}
			}

			// Did we click a gadget?
			if (_clickedGadget == NULL) {

				// Move the grip
				s16 newGripY;

				// Which way should the grip move?
				if (y > _grip->getY()) {
					// Move grip down
					newGripY = (_grip->getY() - getY()) + _grip->getHeight();
				} else {
					// Move grip up
					newGripY = (_grip->getY() - getY()) - _grip->getHeight();
				}

				// Get client rect for this gadget
				Rect rect;
				getClientRect(rect);

				// Adjust y value so that it does not exceed boundaries of gutter
				if (newGripY < rect.y) {
					newGripY = rect.y;
				} else if (newGripY + _grip->getHeight() > rect.height) {
					newGripY = (rect.height - _grip->getHeight()) + 1;
				}

				// Move the grip
				_grip->moveTo(0, newGripY);

				// Handle click on gutter
				Gadget::click(x, y);
			}

			return true;
		}
	}

	return false;
}

bool SliderVertical::release(s16 x, s16 y) {
	if (_clickedGadget != NULL) {

		// Release clicked gadget
		_clickedGadget->release(x, y);

		return true;
	} else if (_flags.clicked) {

		// Handle release on window
		Gadget::release(x, y);

		return true;
	}

	return false;
}

bool SliderVertical::drag(s16 x, s16 y, s16 vX, s16 vY) {
	// Handle child dragging
	if (_clickedGadget != NULL) {
		return _clickedGadget->drag(x, y, vX, vY);
	}

	return false;
}

bool SliderVertical::handleEvent(const EventArgs& e) {

	// Handle grip events
	if ((e.gadget == _grip) && (e.gadget != NULL)) {
		if ((e.type == EVENT_DRAG) || (e.type == EVENT_MOVE)) {

			// Grip has moved
			raiseValueChangeEvent();

			return true;
		}
	}

	return false;
}