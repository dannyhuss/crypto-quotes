#ifndef __NCURSESSCREEN_HPP
#define __NCURSESSCREEN_HPP



class NCursesScreen {
    public:
        NCursesScreen();
        ~NCursesScreen();
    private:
        WINDOW *windows[100];
        int window_count;
        int active_window;
}

#endif
