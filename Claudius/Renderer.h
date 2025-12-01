#pragma once
#include "SDL.h"
#include "Window.h"

class Renderer {
private:
	SDL_Renderer* renderer = nullptr;
public:
	Renderer(Window window, Uint32 flag) noexcept {
		renderer = SDL_CreateRenderer(window.get(), -1, flag);
	}

	~Renderer() {
		SDL_DestroyRenderer(renderer);
	}

	SDL_Renderer* get() noexcept {
		return renderer;
	}

};