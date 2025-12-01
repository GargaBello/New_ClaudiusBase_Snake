#pragma once

#include <string>
#include <vector>
#include "Player.h"
#include "Renderer.h"
#include "SDL_Resource.h"



class Game
{
	
private:
	int width = 1250;
	int height = 700;

	std::string_view title = "Snake";

	Player player;
	Apple apple;


public:
	//Teemu Code Begin.

	// float timer; <- can be used in delta time
	// float updateInterval; <- check Game.h

	Game();

	int get_width();
	int get_height();
	std::string_view get_title();

	void Update(double dt, Renderer renderer);
	void Init();
	void Render(Renderer renderer);
	void Shut();
	void OnKeyDown(SDL_Keycode key);
	
};