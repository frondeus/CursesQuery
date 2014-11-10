#pragma once

#include "CursesQuery/screen.h"
#include "UI/ui.h"

#include <set>
#include <map>
#include <memory>
#include <vector>

#include "tag.h"

enum class Pair : short
{
	WhiteOnBlack=1,
	RedOnBlack=2
};



class Human: public GameObject
{
public:
	Human();

	std::string name;
};

class Game
{
public:
	Game(Screen& s,UI& u);
	void loop();
	void humanLook(Window& wnd);

protected:
	UI& ui;
	Screen& screen;
	std::vector<std::shared_ptr<Window>> windows;
};
