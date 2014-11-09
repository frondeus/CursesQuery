#include "CursesQuery/screen.h"
#include "UI/ui.h"

#include <vector>

enum class Pair : short
{
	WhiteOnBlack=1,
	RedOnBlack=2
};

int main()
{
	Screen screen; // w konstruktorze inicjuje ncurses, w destruktorze zwalnia.
	UI ui(screen);


	screen.setColor((short)Pair::WhiteOnBlack,Color::White,Color::Black);
	screen.setColor((short)Pair::RedOnBlack,Color::Red,Color::Black);

	Window windows[4] =
	{
		{0,0,screen.width/2,screen.height/2},
		{screen.width/2,0,screen.width/2,screen.height/2},
		{0,screen.height/2,screen.width/2,screen.height/2},
		{screen.width/2,screen.height/2,screen.width/2,screen.height/2},
	};

	for(Window& window: windows)
		window.Panel();

	do
	{
		screen.update().render();

		ui.start();
			windows[0].clear();
			ui.setWindow(windows[0])
				.button("This is button",
					[&windows]()
					{
						windows[1]
						        .print("This is result")
						        .endl()
						        .refresh();
					})
				.label("This is label")
				.button("This is button no 2");
				windows[0].refresh();
		ui.end();
	}while(ui.key != 'q');

	return 0;
}
