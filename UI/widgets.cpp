#include "../CursesQuery/screen.h"
#include "ui.h"


UI& UI::label(std::string text)
{
	_startLayout();
		wnd().print(text);
	_endLayout();

	return *this;
}

UI& UI::button(std::string text, std::function<void()> callback)
{
	int id = ++idCount;
	setFocus(id);

	_startLayout();
		if(focus == id) wnd().set(Attribute::Reverse);
		wnd()
			.set(Attribute::Bold)
			.print(text)
			.unset(Attribute::Bold);
		if(focus == id) wnd().unset(Attribute::Reverse);
	_endLayout();

	if(focus == id && clickKey && callback != nullptr) callback();

	return *this;
}
