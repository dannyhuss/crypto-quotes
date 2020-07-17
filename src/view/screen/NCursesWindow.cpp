#include "NCursesWindow.hpp"

// opens up access to various bool checks within ncurses like 'is_nodelay(const WINDOW *win)'
#ifndef NCURSES_OPAQUE
#define NCURSES_OPAQUE
#endif

#define __WAIT_FOR_KEYPRESS 0
#define __DIRECT_ACCESS 1



NCursesWindow::NCursesWindow(int row_count, int column_count, int x_position, int y_position) {
    this->window = newwin(row_count, column_count, y_position, x_position)
    
    if (!this->window)
        throw new std::exception("Could not create window");
    
    this->row_count = row_count;
    this->column_count = column_count;
    this->x_position = x_position;
    this->y_position = y_position;
        
    keypad(this->window, TRUE);  // enable easy recognition of multibyte special characters
}

NCursesWindow::~NCursesWindow(void) {

}


int NCursesWindow::input_buffer_mode(int mode) {
    
    if (mode != 0) 
        mode = 1;
    
   	nodelay(this->window, mode);
}



/**
    Clears the input buffer of both keyboard AND mouse presses
**/
void NCursesWindow::clear_input_buffer(void) {

    this->input_buffer_mode(__DIRECT_ACCESS);

	while (wget_wch(this->window) != ERR); // clear input buffer

	this->input_buffer_mode(__WAIT_FOR_KEYPRESS);
}



// todo: mouse, keyboard or both?
int NCursesWindow::key_pressed(void) {

    wint_t *key; // wint_t type is defined by NCurses
    
    this->input_buffer_mode(__DIRECT_ACCESS);

	int no_key_was_pressed = (wget_wch(this->window, key) == ERR)
	
	this->input_buffer_mode(__WAIT_FOR_KEYPRESS);
	
	if (no_key_was_pressed)
	    return false;
    // else
   	unget_wch(key); // put keypress back into buffer
	return true;
}



