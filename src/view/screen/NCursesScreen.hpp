#ifndef __NCURSESSCREEN_HPP
#define __NCURSESSCREEN_HPP


#define __MAX_WINDOWS 50

class NCursesScreen {
    public:
        NCursesScreen();
        ~NCursesScreen();
    private:
        WINDOW *windows[__MAX_WINDOWS];
        string window_name[__MAX_WINDOWS];
        int window_count;
        int active_window;
}

#endif
