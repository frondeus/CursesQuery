#include "../CursesQuery/screen.h"
#include "ui.h"

UI::UI(Screen& screen)
{
	window = &screen;
	focus = 0;
}

UI& UI::setWindow(Window& wnd)
{
	window = &wnd;
	return *this;
}

void UI::start()
{
	idCount = 0;
	nextKey = (key == 5);
	clickKey = (key == 10);

}

void UI::end()
{
	key = 0;
	if(focus != 0)
		wnd().get(key);
}

Window& UI::wnd()
{
	return *window;
}

void UI::setFocus(int id)
{
	if(focus == 0)
		focus = id;
	if(focus == id && nextKey)
	{
		focus = 0;
		nextKey = false;
	}
}
//-------



