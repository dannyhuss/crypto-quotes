#include "NCursesWindow.hpp"
#include "ncurses.h"
#include <boost/algorithm/string.hpp>

// opens up access to various bool checks within ncurses like 'is_nodelay(const WINDOW *win)'
#ifndef NCURSES_OPAQUE
#define NCURSES_OPAQUE
#endif

#define __PAUSE_FOR_INPUT 0
#define __NO_PAUSING_FOR_INPUT 1



NCursesWindow::NCursesWindow(int row_count, int column_count, int x_position, int y_position) {
    this->window = newwin(row_count, column_count, y_position, x_position);
    
    if (!this->window)
        throw std::exception();
    
    this->row_count = row_count;
    this->column_count = column_count;
    this->x_position = x_position;
    this->y_position = y_position;
        
    keypad(this->window, TRUE);  // enable easy recognition of multibyte special characters
}

NCursesWindow::~NCursesWindow(void) {
    delwin(this->window);   // free memory for window
}



/**
 *  Alters how NCurses retrieves keypresses: 
 *    * pause program execution to wait for a keypress when
 *      the buffer is empty (__PAUSE_FOR_INPUT)
 *    * never pause execution when checking for a keypress
 *      (__NO_PAUSING_FOR_INPUT)          
**/
void NCursesWindow::input_buffer_access_mode(int mode) {
    
    if (mode != __PAUSE_FOR_INPUT) 
        mode = __NO_PAUSING_FOR_INPUT;
    
   	nodelay(this->window, mode);
}



/**
    Clears the input buffer of both keyboard AND mouse presses
**/
void NCursesWindow::clear_input_buffer(void) {

    wint_t *key;
    
    this->input_buffer_access_mode(__NO_PAUSING_FOR_INPUT);

	while (wget_wch(this->window, key) != ERR); // clear input buffer

	this->input_buffer_access_mode(__PAUSE_FOR_INPUT);
}



// todo: mouse, keyboard or both?
int NCursesWindow::key_pressed(void) {

    wint_t *key;
    
    this->input_buffer_access_mode(__NO_PAUSING_FOR_INPUT);

	int no_key_was_pressed = (wget_wch(this->window, key) == ERR);
	
	this->input_buffer_access_mode(__PAUSE_FOR_INPUT);
	
	if (no_key_was_pressed)
	    return false;
    // else
   	unget_wch(*key); // push keypress back onto buffer
	return true;
}



