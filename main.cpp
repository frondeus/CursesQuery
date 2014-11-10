#include "game.h"

int main()
{
	Screen screen; // w konstruktorze inicjuje ncurses, w destruktorze zwalnia.
	UI ui(screen);
	Game game(screen,ui);

	screen.setColor((short)Pair::WhiteOnBlack,Color::White,Color::Black);
	screen.setColor((short)Pair::RedOnBlack,Color::Red,Color::Black);


	do
	{
		screen.update().render();
		ui.start();
			game.loop();
		ui.end();
	}while(ui.key != 'q');

	return 0;
}
