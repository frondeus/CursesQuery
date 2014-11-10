#pragma once

enum class Attribute : int
{
	Normal = A_NORMAL,
	Standout = A_STANDOUT,
	Underline = A_UNDERLINE,
	Reverse = A_REVERSE,
	Blink = A_BLINK,
	Dim = A_DIM,
	Bold = A_BOLD,
	Protect = A_PROTECT,
	Invisible = A_INVIS,
	AltCharset = A_ALTCHARSET,
	CharText = A_CHARTEXT
};

enum class Color : short int
{
	Black = 0,
	Red,
	Green,
	Yellow,
	Blue,
	Magneta,
	Cyan,
	White = 7
};

enum class Direction
{
	Vertical,
	Horizontal
};

class Window
{
public:
	int posX;
	int posY;
	int width;
	int height;

	//Core
	Window(int x = 0, int y = 0, int w = 10, int h = 10);
	Window(Window& parent, int x = 0, int y = 0, int w = 10, int h = 10);

	~Window();
	void makeBorder();

	Window& Panel();
	Window& refresh();
	Window& move(int x, int y);
	Window& pos(int x, int y);
	Window& wait(int delay);

	//output
	Window& print(std::string text, bool delay = false);
	Window& character(char c);
	Window& string(std::string str);
	Window& endl();
	Window& line(Direction dir);

	Window& clear();
	Window& set(Attribute a);
	Window& unset(Attribute a);
	Window& color(short c);

	//input
	Window& get();
	Window& get(char& c);
protected:
	WINDOW* pointer;
	WINDOW* bPointer;
	PANEL* panel;
	bool parent;
};

