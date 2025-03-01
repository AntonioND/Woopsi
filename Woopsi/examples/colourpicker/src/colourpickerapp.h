#ifndef _COLOURPICKERAPP_TEST_H_
#define _COLOURPICKERAPP_TEST_H_

#include "woopsi.h"
#include "gadgeteventhandler.h"
#include "colourpicker.h"

using namespace WoopsiUI;

class ColourPickerApp : public Woopsi, public GadgetEventHandler {
public:
	void handleActionEvent(Gadget& source);

private:
	ColourPicker* _colourpicker;

	void startup();
	void shutdown();
};

#endif
