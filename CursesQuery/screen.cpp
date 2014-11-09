#include "screen.h"

int nh,nw;

void resizeHandler(int sig)
{
     getmaxyx(stdscr, nh, nw);
}

Screen::Screen()
{
	posX = posY = 0;

	initscr();
	raw();
	noecho();
	cbreak();
	//keypad(stdscr, true);

	signal(SIGWINCH, resizeHandler);
	getmaxyx(stdscr,nh,nw);
	height = nh;
	width = nw;

	if(has_colors())
	{
		start_color();
		init_pair( (short int)Color::Red, COLOR_RED, COLOR_BLACK );
	}
	else
		printw("Warning: Output without colors \n");

	pointer = stdscr;
}

Screen::~Screen()
{
	endwin();
}

Screen& Screen::setColor(short pair, Color foreground, Color background)
{
	init_pair( pair, (short)foreground, (short)background );

	return *this;
}


Screen& Screen::update()
{
	width = nw;
	height = nh;
	update_panels();
	return *this;
}

Screen & Screen::render()
{
	doupdate();
	return *this;
}
