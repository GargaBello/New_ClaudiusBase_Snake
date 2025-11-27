#pragma once

#include <string>
#include <vector>
#include "Apple.h"
#include "Player.h"

/*
*/

struct RenderManager;


class Game
{
	Player playerOne;
	Apple apple;



public:
	//Teemu Code Begin.

	// float timer; <- can be used in delta time
	// float updateInterval; <- check Game.h

	int width;
	int height;

	Game();
	~Game();
	bool Enter(int& width, int& height, std::string& title);
	void Update(double dt);
	void Render(RenderManager& rendererManager);
	void OnKeyDown();
	
};