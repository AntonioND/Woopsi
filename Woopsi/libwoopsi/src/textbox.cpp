#include "textbox.h"
#include "woopsikey.h"

using namespace WoopsiUI;

void TextBox::processKey(const WoopsiKey &key) {
	switch (key.getKeyType()) {
	case WoopsiKey::KEY_BACKSPACE:
		if (!_cursorPos) {
			return;
		}

		// Delete the character in front of the cursor
		removeText(_cursorPos - 1, 1);
		break;

	case WoopsiKey::KEY_RETURN:
		// Close the keyboard
		woopsiApplication->hideKeyboard();

		// Fire an action event
		if (raisesEvents()) {
			_gadgetEventHandler->handleActionEvent(*this);
		}
		break;

	default:
		if (key.getValue()) {
			// Not modifier; append value
			insertTextAtCursor(key.getValue());
		}
		break;
	}
}

const WoopsiString &TextBox::getText() {
	return _document->getText();
}

void TextBox::setText(const WoopsiString &text) {

	_document->setText(text);

	cullTopLines();
	limitCanvasHeight();
	jumpToTextBottom();

	markRectsDamaged();

	if (raisesEvents()) {
		_gadgetEventHandler->handleValueChangeEvent(*this);
	}
}
