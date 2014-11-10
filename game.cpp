#include "game.h"


Human::Human() : name("John Kowalsky")
{
	addTag("HUMAN");
	addTag("CURSED");
}

Game::Game(Screen& s, UI& u): ui(u), screen(s)
{
	windows.push_back(std::shared_ptr<Window>(new Window(0,0,screen.width/2,screen.height/2)));
	windows.push_back(std::shared_ptr<Window>(new Window(screen.width/2,0,screen.width/2,screen.height/2)));
	windows.push_back(std::shared_ptr<Window>(new Window(0,screen.height/2,screen.width/2,screen.height/2)));
	windows.push_back(std::shared_ptr<Window>(new Window(screen.width/2,screen.height/2,screen.width/2,screen.height/2)));

	for(auto& window: windows)
		window->Panel();

	new Human();
}

void Game::humanLook(Window& wnd)
{
	auto humans = Tag::getOrCreate("HUMAN");
	for(auto obj: humans->objects)
	{
		std::shared_ptr<Human> human = std::dynamic_pointer_cast<Human>(obj);
		ui.label(human->name);
	}
}

void Game::loop()
{
	windows[0]->pos(0,0);
	ui.setWindow(*windows[0])

		.beginLayout(UI::Layout::Horizontal)
			.label("Humans")
		.endLayout();
	windows[0]->line(Direction::Horizontal).pos(0,2);

	auto humans = Tag::getOrCreate("HUMAN");
	auto normals = Tag::getOrCreate("CURSED");
	auto humanNormals = join(humans->objects,normals->objects);

	for(auto obj: humanNormals)
	{
		std::shared_ptr<Human> human = std::dynamic_pointer_cast<Human>(obj);
		ui.beginLayout(UI::Layout::Horizontal)
			.label(human->name);
		ui.endLayout();
	}

	windows[0]->refresh();

}



