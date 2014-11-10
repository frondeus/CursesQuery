#include "../CursesQuery/screen.h"
#include "ui.h"

UI::UI(Screen& screen)
{
	window = &screen;
	focus = last = 0;
	layout.push(Layout::Vertical);
}

UI& UI::setWindow(Window& wnd)
{
	window = &wnd;
	return *this;
}

UI& UI::beginLayout(enum Layout l)
{
	layout.push(l);
	return *this;
}

UI& UI::endLayout()
{
	layout.pop();
	_endLayout();
	return *this;
}

void UI::start()
{
	idCount = 0;
	nextKey = (key == 5) || (key == 2);
	previousKey = (key == 4) || (key == 3);
	clickKey = (key == 10);

}

void UI::end()
{
	key = 0;
	//if(focus != 0)
	wnd().wait(5);
		wnd().get(key);
	if(key == ERR) key = 0;
}

Window& UI::wnd()
{
	return *window;
}

void UI::setFocus(int id)
{
	if(focus == 0)
		focus = id;
	if(focus == id)
	{
		if(nextKey)
		{
			focus = 0;
			nextKey = false;
		}
		else if(previousKey)
		{
			focus = last;
			previousKey = false;
		}
	}
	last = id;
}
//-------



