#include "listbox.h"
#include "graphicsport.h"
#include "fontbase.h"

ListBox::ListBox(s16 x, s16 y, u16 width, u16 height, FontBase* font) : ScrollingPanel(x, y, width, height, 0, font) {
	_selectedIndex = -1;
	_outline = OUTLINE_IN;
	_flags.draggable = true;
	_flags.doubleClickable = true;
	_optionPadding = 2;
}

void ListBox::addOption(const char* text, const u32 value, const u16 normalTextColour, const u16 normalBackColour, const u16 selectedTextColour, const u16 selectedBackColour) {
	
	// Create new memory for string
	char* newText = new char[strlen(text) + 1];
	
	// Copy text
	strcpy(newText, text);
	
	// Create new option
	ListBoxOption* newOption = new ListBoxOption;
	newOption->text = newText;
	newOption->value = value;
	newOption->normalTextColour = normalTextColour;
	newOption->normalBackColour = normalBackColour;
	newOption->selectedTextColour = selectedTextColour;
	newOption->selectedBackColour = selectedBackColour;
	
	// Add to option array
	_options.push_back(newOption);
	
	// Get client area
	Rect clientRect;
	getClientRect(clientRect);

	// Need to adjust canvas size?
	s32 newCanvasHeight = (_options.size() * (_font->getHeight() + (_optionPadding << 1))) - 1;
	if (newCanvasHeight > _canvasHeight) _canvasHeight = newCanvasHeight;
}

void ListBox::addOption(const char* text, const u32 value) {
	addOption(text, value, _shadowColour, _backColour, _shadowColour, _highlightColour);
}

void ListBox::draw(Rect clipRect) {

	GraphicsPort* port = newInternalGraphicsPort(clipRect);
	
	port->drawFilledRect(0, 0, _width, _height, _backColour);
	
	// TODO: Optimise this so that it limits its drawing to the clip rect's dimensios
	// (at present it draws the entire gadget, although 99% of this drawing is clipped out)
	
	// Precalc values for option draw loop
	s16 optionHeight = _font->getHeight() + (_optionPadding << 1);
	s32 topOption = -_canvasY / optionHeight;
	s16 y = _canvasY + (topOption * optionHeight);
	s32 i = topOption;

	// Loop through all options drawing each one
	while ((i < _options.size()) & (y < _height)) {
		
		// Is the option selected?
		if (_selectedIndex == i) {
			
			// Draw background
			if (_options[i]->selectedBackColour != _backColour) {
				port->drawFilledRect(0, y, _width, optionHeight, _options[i]->selectedBackColour);
			}
		
			// Draw text
			port->drawText(_optionPadding, y + _optionPadding, _font, _options[i]->text, _options[i]->selectedTextColour);
		} else {
			
			// Draw background
			if (_options[i]->normalBackColour != _backColour) {
				port->drawFilledRect(0, y, _width, optionHeight, _options[i]->normalBackColour);
			}
			
			// Draw text
			port->drawText(_optionPadding, y + _optionPadding, _font, _options[i]->text, _options[i]->normalTextColour);
		}
		
		i++;
		y += optionHeight;
	}
	
	// Draw outline
	port->drawBevelledRect(0, 0, _width, _height);

	delete port;
}

void ListBox::setSelectedIndex(const s32 index) {
	_selectedIndex = index;
	draw();
	
	raiseValueChangeEvent();
}

bool ListBox::click(s16 x, s16 y) {
	if (Gadget::click(x, y)) {
		
		// Calculate which gadget was clicked
		s32 newSelectedIndex = (-_canvasY + (y - getY())) / (_font->getHeight() + (_optionPadding << 1));
		
		// Are we setting or unsetting?
		if (newSelectedIndex == _selectedIndex) {
			
			// Unselecting
			setSelectedIndex(-1);
		} else {
		
			// Selecting
			setSelectedIndex(newSelectedIndex);
		}
		
		return true;
	}
	
	return false;
}
