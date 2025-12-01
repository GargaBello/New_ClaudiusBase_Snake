#pragma once

#include "SDL.h"

class SDL_Resource {
public:
	SDL_Resource() noexcept {
		SDL_Init(SDL_INIT_EVERYTHING);
	}

	~SDL_Resource() {
		SDL_Quit();
	}
};