#include <iostream>
#include <curses.h>
#include <unistd.h>

int main(void){
	initscr();
	cbreak();
	noecho();
	sleep(2);
	endwin();
	return 0;
}
