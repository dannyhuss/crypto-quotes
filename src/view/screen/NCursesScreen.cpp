#include "NCursesScreen.hpp"

// opens up access to various bool checks within ncurses like 'is_nodelay(const WINDOW *win)'
#define NCURSES_OPAQUE



NCursesScreen::NCursesScreen(void) {

	

    initscr();
    start_color();
    cbreak();	
    noecho();
    nonl();
 
    
 
    keypad(game_window, TRUE);	
}



NCursesScreen::~NCursesScreen(void) {

    curs_set(CURSOR_VISIBLE);
    delwin(game_window);
    endwin();
}


	
int NCursesScreen::create_window(string window_name, int row_count, int column_count, int x_position, int y_position) {

    this->window_names[
    this->windows[window_count] = newwin(row_count, column_count, y_position, x_position);
    this->window_count++;
}




void NCursesScreen::load_color_scheme(void) {

	if (has_colors()) {
	    init_pair(1,  2, 0);
	    init_pair(2,  7, 0);	    
	    init_pair(3,  8, 0);	    
	    init_pair(4,  9, 0);	    
	    init_pair(5, 10, 0);	    
	    init_pair(6, 14, 0);
    }
}



void NCursesScreen::use_color_pair(string color_pair) {


}
 


int NCursesScreen::input_buffer_mode(int mode) {
    
    if (mode != 0) 
        mode = 1;
    
   	nodelay(this->game_window, mode);
}



/**
    Clears the input buffer of both keyboard AND mouse presses
**/
void NCursesScreen::clear_input_buffer(void) {

    input_buffer_mode(DIRECT_ACCESS);

	while (wget_wch(this->game_window) != ERR); // clear input buffer

	input_buffer_mode(WAIT_FOR_KEYPRESS);
}



// todo: mouse, keyboard or both?
int NCursesScreen::key_pressed(int type) {

    wint_t *key; // wint_t type is defined by NCurses
    
    input_buffer_mode(DIRECT_ACCESS);

	int no_key_was_pressed = (wget_wch(this->game_window, key) == ERR)
	
	input_buffer_mode(WAIT_FOR_KEYPRESS);
	
	if (no_key_was_pressed)
	    return false;
    // else
   	unget_wch(key);	    
	return true;
}



int NCursesScreen::hide_text_cursor {
    return (curs_set(CURSOR_HIDDEN) == ERR) ? false : true;
}

int NCursesScreen::show_text_cursor {
    return (curs_set(CURSOR_VISIBLE) == ERR) ? false : true;
}

int NCursesScreen::hide_mouse_cursor {
    return false;
}

int NCursesScreen::show_mouse_cursor {
    return false;
}


   
int NCursesScreen::enable_mouse_tracking(void) {

    mousemask(ALL_MOUSE_EVENTS, NULL);
}



int NCursesScreen::disable_mouse_tracking(void) {

    mousemask(0, NULL); // device dependent: may hide cursor
}
