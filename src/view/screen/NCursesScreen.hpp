#ifndef __NCURSESSCREEN_HPP
#define __NCURSESSCREEN_HPP

#include "NCursesWindow.hpp"

#define __MAX_WINDOWS 50

#define __CURSOR_HIDDEN 0
#define __CURSOR_VISIBLE 1

using namespace std;

class NCursesScreen {
    public:
        NCursesScreen(int text_encoding);
        ~NCursesScreen();
        NCursesWindow * create_window(string window_name, int row_count, int column_count, int x_position, int y_position);
        int add_window_name(string window_name);
        int window_name_exists(string window_name);
        int set_active_window(string window_name);
        NCursesWindow * get_window(string window_name = "");
        void load_color_scheme(void);
        void use_color_pair(string color_pair);
        int hide_text_cursor(void);
        int show_text_cursor(void);
        int hide_mouse_cursor(void);
        int show_mouse_cursor(void);  
        void enable_mouse_tracking(void);
        void disable_mouse_tracking(void);
    private:
        NCursesWindow *windows[__MAX_WINDOWS];
        string window_names[__MAX_WINDOWS];
        int window_count;
        int active_window;
};

#endif
