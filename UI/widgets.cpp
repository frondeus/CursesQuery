#include "../CursesQuery/screen.h"
#include "ui.h"


UI& UI::label(std::string text)
{
	wnd()
		.print(text)
		.character(' ');
	return *this;
}

UI& UI::button(std::string text, std::function<void()> callback)
{
	int id = ++idCount;
	setFocus(id);

	if(focus == id) wnd().set(Attribute::Reverse);
	wnd()
		.set(Attribute::Bold)
		.print(text)
		.unset(Attribute::Bold);

	if(focus == id) wnd().unset(Attribute::Reverse);

	if(focus == id && clickKey && callback != nullptr) callback();

	wnd().character(' ');
	return *this;
}
