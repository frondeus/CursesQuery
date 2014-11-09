#pragma once
#include <sstream>
#include <functional>

class UI
{
public:
	char key;

	UI(Screen& screen);

	UI& setWindow(Window& wnd);

	void start();
	void end();

	UI& label(std::string text);
	UI& button(std::string text, std::function<void()> callback = nullptr);

protected:

	Window& wnd();
	void setFocus(int id);

	Window* window;


	int idCount;
	int focus;

	bool nextKey;
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
