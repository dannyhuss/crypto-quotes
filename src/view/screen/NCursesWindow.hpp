#ifndef __NCURSESWINDOW_HPP
#define __NCURSESWINDOW_HPP



class NCursesWindow {
    public:
        NCursesWindow();
        ~NCursesWindow();
    private:
        WINDOW *window;
}

#endif
