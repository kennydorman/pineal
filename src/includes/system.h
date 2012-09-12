/*
 * system.h
 *
 *  Created on: 2012-09-09
 *      Author: kdorman
 */

#ifndef SYSTEM_H_
#define SYSTEM_H_

#include <stdio.h>
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>

#include "position.h"
#include "gui_element.h"

/**
 * System Engine for global game domination.
 */
class SystemEngine {
	public:
		ALLEGRO_DISPLAY *display;
		ALLEGRO_MONITOR_INFO *monitor_info;
		ALLEGRO_EVENT_QUEUE *event_queue;
		ALLEGRO_TIMER *timer;
		enum KEYS {UP, DOWN, LEFT, RIGHT};
		bool done,
			redraw,
			error,
			keys[];
		int display_width;
		int display_height;
		int FPS;
		double speed_multiplier;
		GuiElement* player;

		/**
		 * Initialisation of the game egine and creation of principal assets
		 */
		SystemEngine ( void ) {
			FPS = 30;
			speed_multiplier = 1;
			keys[0] = keys[1] = keys[2] = keys[3] = false;
			done = redraw = error = false;

			bool al_system_init = al_init();

			if(!al_system_init) {
				al_show_native_message_box( al_get_current_display(), "Error", "Error", "failed to initialize allegro!", "It's dead Jim...", ALLEGRO_MESSAGEBOX_ERROR );
			}
			display = al_create_display(1280, 720);
			/* this creates a bug ?
			al_get_monitor_info(al_get_num_video_adapters()-1, monitor_info);
			display_width = monitor_info->x2 - monitor_info->x1 - 30;
			display_height = monitor_info->y2 - monitor_info->y1 - 30;
			//*/
//			display_width = 1280;
//			display_height = 720;

			// Init game elements
			//display = al_create_display(width, height);
			event_queue = al_create_event_queue();
			timer = al_create_timer(1.0 / FPS);

			if(!display) {
				al_show_native_message_box( al_get_current_display(), "Error", "Error", "Failed to initialize display!", "It's dead Jim...", ALLEGRO_MESSAGEBOX_ERROR );
				error = true;
				return;
			}

			al_init_font_addon();
			al_init_ttf_addon();
			al_init_primitives_addon();
			al_install_keyboard();

			// Register game events
			al_register_event_source(event_queue, al_get_keyboard_event_source());
			al_register_event_source(event_queue, al_get_display_event_source(display));
			al_register_event_source(event_queue, al_get_timer_event_source(timer));


			player = new GuiElement( );
			player->moveTo( "center" );
			player->draw( );
			al_flip_display();
		}

		/**
		 * Start the game timer
		 * @return void
		 */
		void start_timer ( void ) {
			al_start_timer(timer);
		}

		/**
		 * parse normal events (for the game loop)
		 * @param ALLEGRO_EVENT ev - Allegro event to parse
		 * @return void
		 */
		void parse_event(ALLEGRO_EVENT * ev) {

			if(ev->type == ALLEGRO_EVENT_KEY_DOWN) {
				switch(ev->keyboard.keycode) {
					case ALLEGRO_KEY_W:
					case ALLEGRO_KEY_UP:
						keys[UP] = true;
						break;
					case ALLEGRO_KEY_S:
					case ALLEGRO_KEY_DOWN:
						keys[DOWN] = true;
						break;
					case ALLEGRO_KEY_D:
					case ALLEGRO_KEY_RIGHT:
						keys[RIGHT] = true;
						break;
					case ALLEGRO_KEY_A:
					case ALLEGRO_KEY_LEFT:
						keys[LEFT] = true;
						break;
					case ALLEGRO_KEY_LSHIFT:
					case ALLEGRO_KEY_RSHIFT:
						speed_multiplier = 3;
						break;
				}
			} else if(ev->type == ALLEGRO_EVENT_KEY_UP) {
				switch(ev->keyboard.keycode) {
					case ALLEGRO_KEY_W:
					case ALLEGRO_KEY_UP:
						keys[UP] = false;
						break;
					case ALLEGRO_KEY_S:
					case ALLEGRO_KEY_DOWN:
						keys[DOWN] = false;
						break;
					case ALLEGRO_KEY_D:
					case ALLEGRO_KEY_RIGHT:
						keys[RIGHT] = false;
						break;
					case ALLEGRO_KEY_A:
					case ALLEGRO_KEY_LEFT:
						keys[LEFT] = false;
						break;
					case ALLEGRO_KEY_LSHIFT:
					case ALLEGRO_KEY_RSHIFT:
						speed_multiplier = 1;
						break;
					case ALLEGRO_KEY_ESCAPE:
						done = true;
						break;
				}
			} else if(ev->type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
				done = true;
			} else if(ev->type == ALLEGRO_EVENT_TIMER) {
				player->move(
							(keys[RIGHT] * speed_multiplier * 10) - (keys[LEFT] * speed_multiplier * 10),
							(keys[DOWN] * speed_multiplier * 10) - (keys[UP] * speed_multiplier * 10)
						);

				redraw = true;
			}
		}

		/**
		 * Main system draw
		 */
		void draw ( void ) {
			al_flip_display();
		}
};

#endif /* SYSTEM_H_ */
