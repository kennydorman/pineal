//============================================================================
// Name				: pineal.cpp
// Author			: kdorman (kenny.dorman@gmail.com)
// Version		 :
// Copyright	 : GPL2 + CC BY-NC-SA
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <iostream>
using std::string;
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>

#include <allegro5/allegro_primitives.h>

#include "includes/system.h"
#include "includes/position.h"
#include "includes/gui_element.h"
#include "includes/game_map.h"

const char* APP_FONT = "/usr/share/fonts/truetype/ubuntu-font-family/Ubuntu-R.ttf";

int main ( void ) {
	// Game engine initialisation
	SystemEngine system_engine = SystemEngine( );
	GameMap* game_map = new GameMap( "untitled.tmx" );

	if (!system_engine.error) {
		// Game Loop
		system_engine.start_timer();
		while (!system_engine.done) {
			ALLEGRO_EVENT ev;
			al_wait_for_event(system_engine.event_queue, &ev);

			system_engine.parse_event(&ev);

			if ( system_engine.redraw && al_is_event_queue_empty(system_engine.event_queue) ) {
				al_clear_to_color(al_map_rgb(0,0,0));
				system_engine.player->draw();
				system_engine.draw();

				system_engine.redraw = false;
			}

		}
		// End crap : not really important
		ALLEGRO_FONT *font24 = al_load_font(APP_FONT, 24, 0);
		ALLEGRO_FONT *font36 = al_load_font(APP_FONT, 36, 0);
		ALLEGRO_FONT *font18 = al_load_font(APP_FONT, 18, 0);

		al_clear_to_color(al_map_rgb(0,0,0));

		al_draw_text(font24, al_map_rgb(255, 0, 255), 50, 50, 0, "Hello World, this is 24 point");
		al_draw_text(font36, al_map_rgb(255, 127, 127), 640 / 2, 480 / 2, ALLEGRO_ALIGN_CENTRE, "This is Centered and 36 point");
		al_draw_text(font18, al_map_rgb(15, 240, 18), 620, 350, ALLEGRO_ALIGN_RIGHT, "This is right aligned and 18 point");

		int screen_w = al_get_display_width(system_engine.display);
		int screen_h = al_get_display_height(system_engine.display);

		al_draw_textf(font18, al_map_rgb(255, 255, 255), screen_w/2, 400, ALLEGRO_ALIGN_CENTRE,
			"TEXT with variable output (textf): Screen width and height = %i / %i" , screen_w, screen_h);

//		al_draw_line(100, 100, system.display_height - 100, 100, al_map_rgb(255, 0, 0), 1);
//		al_draw_line(50, 200, system.display_height - 50, 200, al_map_rgb(0, 0, 255), 5);
//		al_draw_line(0, 300, system.display_height, 300, al_map_rgb(255, 0, 255), 10);
//		al_draw_line(50, 50, 50, 400, al_map_rgb(0, 255, 0), 3);
//		al_draw_line(50, 200, system.display_height - 50, 400, al_map_rgb(0, 0, 255), 5);

		al_flip_display();

		// Destroy ALL the things
		al_destroy_font( font18 );
		al_destroy_font( font24 );
		al_destroy_font( font36 );
		al_destroy_display( system_engine.display );
		delete game_map;
	}

	return 0;
}
