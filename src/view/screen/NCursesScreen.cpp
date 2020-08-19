#include "NCursesScreen.hpp"
#include "NCursesWindow.hpp"
#include "ncurses.h"
#include <boost/algorithm/string.hpp>

NCursesScreen::NCursesScreen(int text_encoding) {

    initscr();      // initialize NCurses
    start_color();  // allow text and background coloring
    cbreak();	    // pass standard input directly to NCurses
    noecho();       // don't echo keypresses to screen
    nonl();         // don't move cursor to next line on <enter>
}



NCursesScreen::~NCursesScreen(void) {

    this->show_text_cursor();
    
    /** 
        NOTE:   subwindows must be deleted before a parent window can be
                (if that is ever implemented)
    **/
    
    int i = 0;
    
    while (i < this->window_count) {
        delete(this->windows[i]);
        i++;
    }
        
    endwin();   // close NCurses
}


	
NCursesWindow * NCursesScreen::create_window(string window_name, int row_count, int column_count, int x_position, int y_position) {

    if (this->window_count >= __MAX_WINDOWS)
        return nullptr;
        
    if (!this->add_window_name(window_name))
        return nullptr;   // window_name already in use

    try {
    
        this->windows[this->window_count] = new NCursesWindow(row_count, column_count, x_position, y_position);

    } catch (...) {
    
        this->windows[this->window_count] = 0;
        return nullptr;   // could not create window

    }

    this->window_count++;

    if (this->window_count == 1) {
        this->set_active_window(window_name);
    }
    
    return this->windows[this->window_count - 1];
}



int NCursesScreen::add_window_name(string window_name) {
    
    if (window_name.empty())
        return false;

    /**
        Verify window_name is not currently in use
    **/
    int i = 0;
            
    while (i < this->window_count) {

        if (this->window_names[i] == window_name) {
            return false;   // window name already exists
        }
        
        i++;
    }
    
    this->window_names[--i] = window_name;
    return true;
}



int NCursesScreen::window_name_exists(string window_name) {
    
    if (window_name.empty()) 
        return false;
    
    for (int i = 0; i < this->window_count; i++) {
        if (this->window_names[i] == window_name) {
            return true;
        }
    }
    
    return false;
}



int NCursesScreen::set_active_window(string window_name) {

    for (int i = 0; i < this->window_count; i++) {
        if (this->window_names[i] == window_name) {
            this->active_window = i;
            return true;
        }
    }
    
    // window_name does not exist
    return false;
}


/**
    returns active_window if window_name is not supplied 
    else
    returns window of window_name
**/
NCursesWindow * NCursesScreen::get_window(string window_name) {

    // todo: validate this->active_window
    if (window_name.empty())
        return this->windows[this->active_window];
        
    for (int i = 0; i < this->window_count; i++) {
        if (this->window_names[i] == window_name) {
            this->active_window = i;
            return this->windows[this->active_window];
        }
    }
    
    // window_name does not exist
    return nullptr;
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


int NCursesScreen::hide_text_cursor(void) {
    return (curs_set(__CURSOR_HIDDEN) == ERR) ? false : true;
}

int NCursesScreen::show_text_cursor(void) {
    return (curs_set(__CURSOR_VISIBLE) == ERR) ? false : true;
}

int NCursesScreen::hide_mouse_cursor(void) {
    return false;
}

int NCursesScreen::show_mouse_cursor(void) {
    return false;
}


   
void NCursesScreen::enable_mouse_tracking(void) {

    mousemask(ALL_MOUSE_EVENTS, NULL);
}



void NCursesScreen::disable_mouse_tracking(void) {

    mousemask(0, NULL); // device dependent: may hide cursor
}



