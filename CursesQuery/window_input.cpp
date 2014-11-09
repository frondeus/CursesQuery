#include "screen.h"

Window& Window::get()
{
	wgetch(pointer);
	return *this;
}

Window& Window::get(char& c)
{
	c = wgetch(pointer);
	return *this;
}
