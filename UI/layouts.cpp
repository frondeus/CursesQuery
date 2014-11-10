#include "../CursesQuery/screen.h"
#include "ui.h"

void UI::_startLayout()
{
}

void UI::_endLayout()
{

	if(layout.top() == Layout::Vertical)
		wnd().endl();
	else if(layout.top() == Layout::Horizontal)
		wnd().character(' ');
}
