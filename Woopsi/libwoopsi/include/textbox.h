#ifndef _TEXTBOX_H_
#define _TEXTBOX_H_

#include "multilinetextbox.h"
#include "woopsi.h"
#include "woopsikey.h"
#include "woopsistring.h"

namespace WoopsiUI {
	class TextBox : public MultiLineTextBox {
	public:
	    inline TextBox(s16 x, s16 y, u16 width, u16 height, const WoopsiUI::WoopsiString &text, WoopsiUI::GadgetStyle *style = (WoopsiUI::GadgetStyle *)__null)
	        : MultiLineTextBox(x, y, width, height, text, 0, style) {}

	    virtual void processKey(const WoopsiKey& key);
		virtual const WoopsiString& getText();
		virtual void setText(const WoopsiString& text);
	};
}
#endif