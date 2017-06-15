#pragma once
#include <SDL.h>

class Display {

public:
	Display(const char *title, int width, int height);
	~Display();

	bool init();
	void update();
	void clear();
	void render();
	bool isOpen();
	void destroy();
public:
	static SDL_Window *window_;
	static SDL_Renderer *renderer_;

private:
	const char *title_;
	int width_;
	int height_;

	bool is_open_;

};

