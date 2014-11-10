#include "screen.h"

Window::Window(int x, int y, int w, int h) :
		posX(x), posY(y), width(w), height(h), panel(nullptr), parent(false)
{
	bPointer = newwin(h,w,y,x);
	pointer = derwin(bPointer,h-2,w-2,1,1);
	makeBorder();
}

Window::Window(Window& parent, int x, int y, int w, int h) :
		posX(x), posY(y), width(w), height(h),  panel(nullptr), parent(true)
{
	bPointer = derwin(parent.pointer,h,w,y+1,x+1);
	pointer = derwin(bPointer,h-2,w-2,1,1);
	makeBorder();
}
Window::~Window()
{
    delwin(pointer);
    delwin(bPointer);
}

void Window::makeBorder()
{
    box(bPointer,0,0);
    keypad(pointer, true);
    nodelay(pointer, true);
}

Window& Window::Panel()
{
	panel = new_panel(bPointer);
	return *this;
}

Window& Window::refresh()
{
	touchwin(pointer);
	wrefresh(pointer);
	return *this;
}

Window& Window::pos(int x, int y)
{
	wmove(pointer,y,x);
	return *this;
}

Window& Window::wait(int delay)
{
	usleep(delay * 10000);
	return *this;
}

Window& Window::move(int x, int y)
{
	posX = x;
	posY = y;
	if(!parent)
		mvwin(pointer,y,x);
	else
		mvderwin(pointer,y,x);
	return *this;
}
