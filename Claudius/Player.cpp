#include "Player.h"
#include <cmath>
#include <iostream>



void Player::Update(double dt)
{
	OutOfBounds(snakePosX, snakePosY);

	for (int i = 0; i < playerScore; i++)
	{
		
	}
}

void Player::PlayerMove(SDL_Keycode key) noexcept
{
	key == SDLK_RIGHT ? snakePosX + SnakeMovementSpeed
		: key == SDLK_LEFT ? snakePosX - SnakeMovementSpeed
		: key == SDLK_UP ? snakePosY + SnakeMovementSpeed
		: key == SDLK_DOWN ? snakePosY - SnakeMovementSpeed : 0;
}

void Player::OutOfBounds(int x, int y) noexcept
{
	if (x < 0) { x = 0; }
	if (x > width) { x = width; }
	if (y < 0) { y = 0; }
	if (y > height) { y = height; }
}


