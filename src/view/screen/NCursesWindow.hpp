#ifndef __NCURSESWINDOW_HPP
#define __NCURSESWINDOW_HPP

#include "ncurses.h"
#include <boost/algorithm/string.hpp>

using namespace std;

class NCursesWindow {
    public:
        NCursesWindow(int row_count, int column_count, int x_position, int y_position);
        ~NCursesWindow();
        void input_buffer_access_mode(int mode);
        void clear_input_buffer(void);
        int key_pressed(void);
    private:
        WINDOW *window;
        int row_count;
        int column_count;
        int x_position;
        int y_position;
};

#endif
