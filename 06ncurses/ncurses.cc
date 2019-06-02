#include <iostream> // std
#include <mutex>
#include <ncurses.h> // ncurses
#include <thread>
#include <unistd.h> // sleep

using namespace std;

int MAX_X, MAX_Y;
mutex mtx;
struct Screen {
    int c{0};  // Counter
    WINDOW *w; // Window
};
Screen s[3];	// Array of Screen (struct)

// https://www.viget.com/articles/c-games-in-ncurses-using-multiple-windows/

// Read a string from the keyboard using NCurses
string read_string_from_keyboard(WINDOW *w)
{
    char my_char_array[128];
    wscanw(w, "%s", my_char_array);
    string my_string = string(my_char_array);
    return my_string;
}

void init_curses()
{
    initscr();
    getmaxyx(stdscr, MAX_Y, MAX_X);
    s[1].w = newwin(MAX_Y, MAX_X / 2, 0, 0);
    s[2].w = newwin(MAX_Y, MAX_X / 2, 0, MAX_X / 2 + 1);
    curs_set(0); // Hide cursor
    scrollok(s[1].w, TRUE);
    scrollok(s[2].w, TRUE);
}

void do_work(int id)
{
    for (int i{0}; i != 100; ++i) {
        s[id].c++;
        string str = "I am " + to_string(id) + "." + to_string(s[id].c);
        mtx.lock();		// Mutual exclusion begins
        wprintw(s[id].w, "%s\n", str.c_str());
        wrefresh(s[id].w);
        mtx.unlock();	// Mutual exclusion ends
        usleep(10000 * id);
    }
}

int main(void)
{
    init_curses();
    thread t1(do_work, 1);
    thread t2(do_work, 2);
    t1.join();
    t2.join();
    wgetch(s[1].w);
    endwin();
    return 0;
}
