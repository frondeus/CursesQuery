#pragma once

#include <string>
#include <ncurses.h>
#include <unistd.h>
#include <panel.h>
#include <signal.h>

#include "window.h"

class Screen : public Window
{
public:
	Screen();
	~Screen();

	Screen& setColor(short pair, Color foreground, Color background);

	Screen& update();
	Screen& render();
};
