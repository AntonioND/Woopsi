#include "woopsi.h"
#include "screen.h"
#include "woopsifuncs.h"
#include "fontbase.h"
#include "font.h"
#include "sysfont.h"
#include "contextmenu.h"

// Instantiate singleton
Woopsi* Woopsi::singleton = NULL;

// Initialise static system font
FontBase* Woopsi::_systemFont = NULL;

// Initialise static VBL listener vector
DynamicArray<Gadget*> Woopsi::_vblListeners;

// Initialise static deletion queue
DynamicArray<Gadget*> Woopsi::_deleteQueue;

// Initialise VBL counter
u32 Woopsi::_vblCount = 0;

Woopsi::Woopsi(FontBase* font) : Gadget(0, 0, SCREEN_WIDTH, TOP_SCREEN_Y_OFFSET + SCREEN_HEIGHT, GADGET_BORDERLESS, font) {
	_lidClosed = false;
	_parent = NULL;
	_clickedGadget = NULL;
	_flags.clicked = false;
	_flags.visible = true;
	_activeGadget = NULL;

	if (font == NULL) {
		_font = getSystemFont();
	}

	// Create context menu
	_contextMenu = new ContextMenu(_font);
	addGadget(_contextMenu);
	_contextMenu->hide();

	singleton = this;
}

Woopsi::~Woopsi() {
	deleteSystemFont();
	_font = NULL;
	singleton = NULL;
	_contextMenu = NULL;
}

// Add a new screen
Screen* Woopsi::newScreen(char* title) {

	// Create a new screen
	Screen* newScreen = new Screen(title, _font);
	addGadget(newScreen);
	newScreen->focus();

	return newScreen;
}

void Woopsi::play() {
	vbl();
	handleStylus();
	handleKeys();
	handleLid();
}

bool Woopsi::vbl() {

	// Increase vbl counter
	_vblCount++;

	// VBL
	for (u8 i = 0; i < _vblListeners.size(); i++) {
		_vblListeners[i]->vbl();
	}

	// Delete any queued gadgets
	processDeleteQueue();

	return true;
}

void Woopsi::draw(Gadget::Rect clipRect) {
	clear(clipRect);
}

void Woopsi::setActiveGadget(Gadget* gadget) {
	if (_activeGadget != gadget) {
		// Deactivate the active screen
		if (_activeGadget != NULL) {
			_activeGadget->blur();
		}

		_activeGadget = gadget;
	}
}

// Process all stylus input
void Woopsi::handleStylus() {
	if (Stylus.Newpress) {
		if (Pad.Held.L || Pad.Held.R) {
			shiftClick(Stylus.X, Stylus.Y);
		} else {
			click(Stylus.X, Stylus.Y);
		}
	} else if (Stylus.Held) {
		drag(Stylus.X, Stylus.Y, Stylus.Vx, Stylus.Vy);
	} else if (_flags.clicked) {
		release(Stylus.X, Stylus.Y);
	}
}

bool Woopsi::click(s16 x, s16 y) {

	_flags.clicked = true;

	// Work out which gadget was clicked
	for (s16 i = _gadgets.size() - 1; i > -1; i--) {
		if (_gadgets[i]->click(x, y)) {

			// Do we need to close the context menu?
			if ((_gadgets[i] != _contextMenu) && (_contextMenu->isVisible())) {
				_contextMenu->hide();
				_contextMenu->reset();
			}

			return true;
		}
	}

	return false;
}

bool Woopsi::shiftClick(s16 x, s16 y) {

	_flags.clicked = true;

	// Close the existing context menu
	if (_contextMenu->isVisible()) {
		_contextMenu->hide();
		_contextMenu->reset();
	}

	// Work out which gadget was clicked
	for (s16 i = _gadgets.size() - 1; i > -1; i--) {
		if (_gadgets[i]->shiftClick(x, y)) {
			return true;
		}
	}

	return false;
}

bool Woopsi::drag(s16 x, s16 y, s16 vX, s16 vY) {
	if (_clickedGadget != NULL) {
		_clickedGadget->drag(x, y, vX, vY);

		return true;
	}

	return false;
}

bool Woopsi::release(s16 x, s16 y) {

	if (_flags.clicked) {

		// Avoid using the unreliable "Stylus.Released" variable
		_flags.clicked = false;

		// Release clicked gadget
		if (_clickedGadget != NULL) {
			_clickedGadget->release(x, y);
		}

		return true;
	}

	return false;
}

// Process all key input
void Woopsi::handleKeys() {
	if (_activeGadget != NULL) {
		if (Pad.Newpress.A) {
			_activeGadget->keyPress(KEY_CODE_A);
		} else if (Pad.Released.A) {
			_activeGadget->keyRelease(KEY_CODE_A);
		}

		if (Pad.Newpress.B) {
			_activeGadget->keyPress(KEY_CODE_B);
		} else if (Pad.Released.B) {
			_activeGadget->keyRelease(KEY_CODE_B);
		}

		if (Pad.Newpress.X) {
			_activeGadget->keyPress(KEY_CODE_X);
		} else if (Pad.Released.X) {
			_activeGadget->keyRelease(KEY_CODE_X);
		}

		if (Pad.Newpress.Y) {
			_activeGadget->keyPress(KEY_CODE_Y);
		} else if (Pad.Released.Y) {
			_activeGadget->keyRelease(KEY_CODE_Y);
		}

		if (Pad.Newpress.L) {
			_activeGadget->keyPress(KEY_CODE_L);
		} else if (Pad.Released.L) {
			_activeGadget->keyRelease(KEY_CODE_L);
		}

		if (Pad.Newpress.R) {
			_activeGadget->keyPress(KEY_CODE_R);
		} else if (Pad.Released.R) {
			_activeGadget->keyRelease(KEY_CODE_R);
		}

		if (Pad.Newpress.Up) {
			_activeGadget->keyPress(KEY_CODE_UP);
		} else if (Pad.Released.Up) {
			_activeGadget->keyRelease(KEY_CODE_UP);
		}

		if (Pad.Newpress.Down) {
			_activeGadget->keyPress(KEY_CODE_DOWN);
		} else if (Pad.Released.Down) {
			_activeGadget->keyRelease(KEY_CODE_DOWN);
		}

		if (Pad.Newpress.Left) {
			_activeGadget->keyPress(KEY_CODE_LEFT);
		} else if (Pad.Released.Left) {
			_activeGadget->keyRelease(KEY_CODE_LEFT);
		}

		if (Pad.Newpress.Right) {
			_activeGadget->keyPress(KEY_CODE_RIGHT);
		} else if (Pad.Released.Right) {
			_activeGadget->keyRelease(KEY_CODE_RIGHT);
		}

		if (Pad.Newpress.Start) {
			_activeGadget->keyPress(KEY_CODE_START);
		} else if (Pad.Released.Start) {
			_activeGadget->keyRelease(KEY_CODE_START);
		}

		if (Pad.Newpress.Select) {
			_activeGadget->keyPress(KEY_CODE_SELECT);
		} else if (Pad.Released.Select) {
			_activeGadget->keyRelease(KEY_CODE_SELECT);
		}
	}
}

void Woopsi::handleLid() {

	// Check for lid closed event
	if (woopsiLidClosed() && !_lidClosed) {

		// Lid has just been closed
		_lidClosed = true;

		// Run lid closed on all gadgets
		for (u8 i = 0; i < _gadgets.size(); i++) {
			_gadgets[i]->lidClosed();
		}

	} else if (!woopsiLidClosed() && _lidClosed) {

		// Lid has just been opened
		_lidClosed = false;

		// Run lid opened on all gadgets
		for (u8 i = 0; i < _gadgets.size(); i++) {
			_gadgets[i]->lidOpened();
		}
	}
}

bool Woopsi::swapGadgetDepth(Gadget* gadget) {
	// Do we have more than one screen?
	if (_gadgets.size() > 1) {

		u8 gadgetSource = getGadgetIndex(gadget);
		u8 gadgetDest = 0;

		// Raise or lower?
		if (gadgetSource < _gadgets.size() - 1) {
			// Raise
			gadgetDest = gadgetSource + 1;
		} else {
			// Lower
			gadgetDest = 0;
		}

		if (gadgetSource != gadgetDest) {
			eraseGadget(gadget);

			// Swap
			Gadget* tmp = _gadgets[gadgetSource];
			_gadgets[gadgetSource] = _gadgets[gadgetDest];
			_gadgets[gadgetDest] = tmp;

			// Invalidate from the top screen down
			_gadgets[_gadgets.size() - 1]->invalidateVisibleRectCache();
			invalidateLowerGadgetsVisibleRectCache(_gadgets[_gadgets.size() - 1]);

			// Redraw the bottom screen
			//Rect rect;
			//rect.x = 0;
			//rect.y = 0;
			//rect.width = SCREEN_WIDTH;
			//rect.height = SCREEN_HEIGHT;
			//eraseRect(rect);

			gadget->draw();

			return true;
		}
	}

	return false;
}

bool Woopsi::flipScreens(Gadget* gadget) {

	// Only flip if there is more than one screen
	if (_gadgets.size() > 1) {
		// Locate the top gadget
		Gadget* topGadget = NULL;

		for (u8 i = 0; i < _gadgets.size(); i++) {
			if ((_gadgets[i]->isVisible()) && (!_gadgets[i]->isDeleted())) {
				if (_gadgets[i]->getPhysicalScreenNumber() == 1) {
					topGadget = _gadgets[i];
					break;
				}
			}
		}

		// Did we find it?
		if (topGadget != NULL) {

			// Is the top gadget the current gadget?
			if (gadget == topGadget) {
				// Get a pointer to the highest gadget in the bottom screen
				// that isn't the top gadget
				for (s16 i = _gadgets.size() - 1; i > -1; i--) {
					if (gadget != _gadgets[i]) {
						gadget = _gadgets[i];
						break;
					}
				}
			}

			topGadget->setVisible(false);

			// Move to top of stack
			topGadget->raiseToTop();

			topGadget->setVisible(true);

			// Move to bottom screen
			((Screen*)topGadget)->flipToBottomScreen();
		}
		
		// Move the requested gadget to the top screen
		((Screen*)gadget)->flipToTopScreen();
		
		return true;
	}

	return false;
}

// Erase a rectangular area of the screen
void Woopsi::eraseRect(Rect rect) {

	// Create pointer to a vector to store the invalid rectangles
	DynamicArray<Rect>* invalidRectangles = new DynamicArray<Rect>();

	if (invalidRectangles != NULL) {
		 
		// Add rectangle into the vector
		invalidRectangles->push_back(rect);

		// Refresh children
		for (s16 i = _gadgets.size() - 1; i > -1 ; i--) {
			if (invalidRectangles->size() > 0) {
				_gadgets[i]->redrawDirty(invalidRectangles, NULL);
			} else {
				break;
			}
		}

		// Refresh screen
		for (u8 i = 0; i < invalidRectangles->size(); i++) {
			if (invalidRectangles->size() > 0) {
				clear(invalidRectangles->at(i));
			} else {
				break;
			}
		}

		// Tidy up
		delete invalidRectangles;
	}
}

// Return a pointer to the static system font
FontBase* Woopsi::getSystemFont() {

	// Create font instance if it does not exist yet
	if (_systemFont == NULL) {
		_systemFont = new Font(sysfont_Bitmap, 256, 50, 8, 10, 64543);
	}

	return _systemFont;
}

// Delete the static font
void Woopsi::deleteSystemFont() {
	if (_systemFont != NULL) {
		delete _systemFont;
		_systemFont = NULL;
	}
}

// Add a gadget to the list of gadgets that receive VBL events
void Woopsi::registerForVBL(Gadget* gadget) {

	// Ensure gadget is not already in the list
	for (u8 i = 0; i < _vblListeners.size(); i++) {
		if (_vblListeners[i] == gadget) {
			return;
		}
	}

	_vblListeners.push_back(gadget);
}

// Remove a gadget from the VBL list
void Woopsi::unregisterFromVBL(Gadget* gadget) {
	
	// Locate gadget in the list
	for (u8 i = 0; i < _vblListeners.size(); i++) {
		if (_vblListeners[i] == gadget) {
			_vblListeners.erase(_vblListeners.begin() + i);
			return;
		}
	}
}


// Delete all gadgets in the queue
void Woopsi::processDeleteQueue() {

	if (_deleteQueue.size() > 0) {

		for (u8 i = 0; i < _deleteQueue.size(); i++) {
			_deleteQueue[i]->destroy();
		}

		_deleteQueue.clear();
	}
}

void Woopsi::addToDeleteQueue(Gadget* gadget) {

	// Ensure that gadget is no longer receiving VBL events
	unregisterFromVBL(gadget);

	// Ensure gadget's children are no longer receiving VBL events
	gadget->unregisterChildrenFromVBL();

	_deleteQueue.push_back(gadget);
}

u32 Woopsi::getVBLCount() {
	return _vblCount;
}

// Close a child
void Woopsi::closeChild(Gadget* gadget) {
	if (gadget != NULL) {

		// Ensure gadget knows it is being closed
		if (!gadget->isDeleted()) {
			gadget->close();
		}

		// Do we need to make another gadget active?
		if (_activeGadget == gadget) {
			_activeGadget = NULL;
		}

		// Unset clicked gadget if necessary
		if (_clickedGadget == gadget) {
			_clickedGadget = NULL;
		}

		// Decrease decoration count if necessary
		if (gadget->isDecoration()) {
			_decorationCount--;
		}

		moveChildToDeleteQueue(gadget);
	}
}

// Hide a child
void Woopsi::hideChild(Gadget* gadget) {
	if (gadget != NULL) {

		// Ensure gadget knows it is being closed
		if (gadget->isVisible()) {
			gadget->hide();
		}

		// Do we need to make another gadget active?
		if (_activeGadget == gadget) {
			_activeGadget = NULL;
		}

		// Unset clicked gadget if necessary
		if (_clickedGadget == gadget) {
			_clickedGadget = NULL;
		}

		// Decrease decoration count if necessary
		if (gadget->isDecoration()) {
			_decorationCount--;
		}

		moveChildToHiddenList(gadget);
	}
}

const u32 Woopsi::getContextMenuValue() const {
	return _contextMenu->getValue();
}
