#include "screen.h"

Window& Window::print(std::string text, bool delay)
{
	if (!delay)
		wprintw(pointer,text.c_str());
	else
	{
		for (char &c : text)
		{
			waddch(pointer,c);
			wrefresh(pointer);
			usleep(10 * 10000);
		}
	}
	return *this;
}

Window& Window::character(char c)
{
	waddch(pointer,c);
	return *this;
}

Window& Window::string(std::string str)
{
	waddstr(pointer,str.c_str());
	return *this;
}

Window& Window::endl()
{
	waddch(pointer,'\n');
	return *this;
}

Window& Window::line(Direction dir)
{
	if(dir == Direction::Horizontal)
	{
		whline(pointer, ACS_HLINE, 1000);
	}
	else
	{
		wvline(pointer,ACS_VLINE,height);
	}
	return *this;
}
//------------


Window& Window::clear()
{
	wclear(pointer);
	return *this;
}

Window& Window::set(Attribute a)
{
	wattron(pointer,a);
	return *this;
}

Window& Window::unset(Attribute a)
{
	wattroff(pointer,a);
	return *this;
}

Window& Window::color(short c)
{
	wattron(pointer,COLOR_PAIR(c));
	return *this;
}
