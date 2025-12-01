#pragma once
#include "SDL.h"
#include <string_view>

class Window {
	SDL_Window* window = nullptr;
public:

	Window(int width, int height, std::string_view title, Uint32 flag) {
		window = SDL_CreateWindow(title.data(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flag);

		if (window == nullptr) {

		}
	}

	~Window() noexcept {
		SDL_DestroyWindow(window);
	}

	SDL_Window* get() noexcept {
		return window;
	}
};