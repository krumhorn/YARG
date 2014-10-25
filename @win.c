#include<ncurses.h>

typedef struct {
	char face;
	int x;
	int y;
} mobile; 

void mvmob(mobile *mob, int _y, int _x) {
	mvaddch(mob->y, mob->x, ' ');
	mob->x += _x;
	mob->y += _y; /*so that -y=downscreen, +y=upscreen*/
	mvaddch(mob->y, mob->x, mob->face);
	refresh();
}

void dmob(mobile *mob) {
	mvaddch(mob->x, mob->y, mob->face);
	refresh();
}

int main(int argc, char *argv[]) {
	char ch;
	initscr();
	clear();
	noecho();
	cbreak();
	//keypad(stdscr, TRUE);
	mobile hero = {'@', 5, 5};
	mobile *hptr = &hero;
	dmob(hptr);
	while((ch = getch()) != 'q') {
		switch (ch) {
			case 'w':
				mvmob(hptr, -1, 0);
				break;
			case 'a':
				mvmob(hptr, 0, -1);
				break;
			case 's':
				mvmob(hptr, 1, 0);
				break;
			case 'd':
				mvmob(hptr, 0, 1);
				break;
}
	}
	endwin();
	return 0;
}
