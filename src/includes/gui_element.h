/*
 * GuiElement.h
 *
 *  Created on: 2012-09-07
 *      Author: kdorman
 */

#include "position.h"
#ifndef GUIELEMENT_H_
#define GUIELEMENT_H_

/**
 * Base element for all GUI elements
 */
class GuiElement {
	public:
		/**
		 * Position of the element
		 */
		Position position;
		/**
		 * Empty constructor
		 */
		GuiElement() {};
		/**
		 * Constructor with starting possition
		 */
		GuiElement( Position* _position ) {
			position.setPosition(_position);
		}
		/**
		 * Empty destructor
		 */
		virtual ~GuiElement() {}
		/**
		 * Move element to Position
		 */
		void moveTo (Position* _position) {
			position.setPosition(_position);
		}
		/**
		 * move element to textual position
		 * currently only works with "center"
		 */
		void moveTo (char* _position) {
			int screen_w = al_get_display_width(al_get_current_display());
			int screen_h = al_get_display_height(al_get_current_display());
			if (_position ==  "center") {
				position.setX( screen_w / 2 );
				position.setY( screen_h / 2 );
			}
		}
		/**
		 * Move element to position
		 * @param double _X - X position
		 * @param double _Y - Y position
		 */
		void moveTo (double _X, double _Y) {
			position.setX(_X);
			position.setY(_Y);
		}
		/**
		 * Move element by the param value
		 * @param double _delta_X - X delta position change
		 * @param double _delta_Y - Y delta position change
		 */
		void move (double _delta_X, double _delta_Y){
			position.setX (position.getX() + _delta_X);
			position.setY (position.getY() + _delta_Y);
		}
		/**
		 * Draw element here it's a magenta 30 pixel box
		 */
		void draw ( void ) {
			al_draw_filled_rectangle(
					position.getX(),
					position.getY(),
					position.getX() + 30,
					position.getY() + 60,
					al_map_rgb(255,255,255));
			al_draw_filled_rectangle(
					position.getX()+8,
					position.getY()+8,
					position.getX() + 12,
					position.getY() + 12,
					al_map_rgb(0,0,0));
			al_draw_filled_rectangle(
					position.getX()+18,
					position.getY()+8,
					position.getX() + 28,
					position.getY() + 12,
					al_map_rgb(0,0,0));
		}
};

#endif /* GUIELEMENT_H_ */
