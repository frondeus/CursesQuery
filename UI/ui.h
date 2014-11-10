#pragma once
#include <sstream>
#include <functional>
#include <stack>

class UI
{
public:
	char key;
	enum class Layout
	{
		Vertical,
		Horizontal
	};


	UI(Screen& screen);

	UI& setWindow(Window& wnd);
	UI& beginLayout(Layout l);
	UI& endLayout();

	void start();
	void end();

	UI& label(std::string text);
	UI& button(std::string text, std::function<void()> callback = nullptr);

protected:

	Window& wnd();
	void setFocus(int id);
	void _startLayout();
	void _endLayout();

	Window* window;
	std::stack<Layout> layout;

	int idCount;
	int focus;
	int last;

	bool nextKey;
	bool previousKey;
	bool clickKey;
};

template<typename T>
std::string toString(const T &t) {
	std::ostringstream os;
	os << t;
	return os.str();
}

template<typename T>
T fromString(const std::string &str) {
	std::istringstream is(str);
	T t;
	is >> t;
	return t;
}
