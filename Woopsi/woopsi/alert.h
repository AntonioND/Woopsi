#ifndef _ALERT_H_
#define _ALERT_H_

#include <nds.h>
#include "amigawindow.h"

using namespace std;

class Button;

class Alert : public AmigaWindow {
public:
	Alert(s16 x, s16 y, u16 width, u16 height, char* title, char* text, FontBase* font = NULL);
	virtual ~Alert();

	virtual bool release(s16 x, s16 y);

protected:
	Button* _button;
};

#endif
