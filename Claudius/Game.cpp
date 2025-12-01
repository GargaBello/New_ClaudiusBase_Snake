// 2019-12-05 Teemu Laiho

#include "Game.h"
#include "RenderManager.h"
#include <iostream>


Game::Game()
{

	
}

int Game::get_width()
{
	return width;
}

int Game::get_height()
{
	return height;
}

std::string_view Game::get_title()
{
	return title;
}

void Game::Update(double dt, Renderer renderer)
{
	player.Update(dt);

	// Player collide on apple.
	if (snakePosX == applePosX && snakePosY == applePosY)
	{
		playerScore++;
		apple.GetNewRandomPos(applePosX, applePosY);

	}

	Render(renderer);
}

void Game::Render(Renderer renderer)
{
	SDL_SetRenderDrawColor(renderer.get(), 0, 0, 0, 0);
	SDL_RenderClear(renderer.get());

	
	SDL_RenderPresent(renderer.get());
	
	SDL_Delay(1000 / 20); //<- "Framerate".
}

void Game::OnKeyDown(SDL_Keycode key)
{
	player.PlayerMove(key);
}

