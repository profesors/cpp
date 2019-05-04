#include <curses.h>
#include <iostream>

using namespace std;

int main(void){
	int a;
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	int h_size = LINES, w_size{COLS};
	getmaxyx(stdscr, h_size, w_size);
	WINDOW *w = newwin(stdscr, h_size, w_size);
	cin >> a;
	endwin();
}
