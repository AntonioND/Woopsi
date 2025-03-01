// Includes
#include "colourpickerapp.h"
#include "woopsiheaders.h"
#include "debug.h"

void ColourPickerApp::startup() {

	// Create screen
	AmigaScreen* screen = new AmigaScreen("Test Screen", true, true);
	woopsiApplication->addGadget(screen);

	// Add colour picker
	_colourpicker = new ColourPicker(0, 0, 150, 100, "Colour Picker", woopsiRGB(31, 20, 10));
	_colourpicker->setGadgetEventHandler(this);
	screen->addGadget(_colourpicker);
}

void ColourPickerApp::shutdown() {

	// Call base shutdown method
	Woopsi::shutdown();
}

void ColourPickerApp::handleActionEvent(Gadget& source) {
	// Short version of the event handler since we know that only one gadget can
	// possibly call this

	u16 colour = _colourpicker->getColour();
	u16 r = colour & 0x1F;
	u16 g = (colour >> 5) & 0x1F;
	u16 b = (colour >> 10) & 0x1F;

	Debug::printf("RGB: %d, %d, %d", r, g, b);
}
