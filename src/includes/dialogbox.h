/*
 * DialogBox.h
 *
 *  Created on: 2012-09-08
 *      Author: ajacques
 */

#include "gui_element.h"
#ifndef DIALOGBOX_H_
#define DIALOGBOX_H_

class DialogBox : public GuiElement {

public:
	/* The character/whatever who is talking */
	char* speaker;

	/* The message to put in the dialog box */
	char* message;

	/* The top left corner's position of the box */
	GuiElement element;

	/* The width of the box */
	int width;

	/* The height of the box */
	int height;

	/* Constructor */
	DialogBox(char* _speaker, char* _message, GuiElement _element, int _width, int _height) {
		speaker = _speaker;
		message = _message;
		element = _element;
		width = _width;
		height = _height;
	}

	/* Destructor */
	~DialogBox() {
		if(strlen(speaker) > 1) {
			delete[] speaker;
			speaker = NULL;
		} else {
			delete speaker;
		}
		
		if(strlen(message) > 1) {
			delete[] message;
			message = NULL;
		} else {
			delete message;
		}
	}

};

#endif /* DIALOGBOX_H_ */
