#pragma once		// #pragma once == Compile this file once.

#include "Constants.h"
#include "SDL.h"
#include <random>


struct RenderManager;

class Entity {
private:
	int x_position = 0,
		y_position = 0;

	

public:

	int get_x_pos();
	int get_y_pos();
	int get_rect_side();
	char get_colour();

	int set_x_pos(int x);
	int set_y_pos(int y);
	char set_colour(int r, int g, int b, int a);
};

class Player : Entity {
private:
	int starting_x = 300;
	int starting_y = 300;

	
public:
	
	Player() noexcept {
		snakePosX = starting_x;
		snakePosY = starting_y;
	}

	void Update(double dt);
	void PlayerMove(SDL_Keycode key) noexcept;
	void OutOfBounds(int x, int y) noexcept;

	
};

class Tail : Entity {
private:

public:

	Tail();
};

class Apple : Entity {
private:
	int starting_x_pos = (rand() % 125) * 10;
	int starting_y_pos = (rand() % 70) * 10;

public:


	Apple() noexcept {
		applePosX = starting_x_pos;
		applePosY = starting_y_pos;
	}

	void GetNewRandomPos(int x, int y) noexcept {
		applePosX = (rand() % 125) * 10;
		applePosY = (rand() % 70) * 10;
	}
};

//struct Player
//{
//	struct PlayerPart
//	{
//		Transform trans;
//		Color color;
//		Rectangle rect;
//	};
//
//	//Static == belongs to the class, not the object of the class.
//	static const int player_size = 50;
//	PlayerPart parts[player_size];
//	
//	Transform trans;
//	Color color;
//	Rectangle rect;
//	void OnKeyDown();
//	void Initialize();
//	void Render(RenderManager& renderManager);				// A reference or pointer doesn't need to be #include, just a forward declare.
//	void Update(double dt);
//	void ResetPlayer();
//
//	int size = 10;
//	const float movement_speed = 10.0f;
//	const float starting_x = 300.0f;
//	const float starting_y = 300.0f;
//
//	bool moving_right = false;
//	bool moving_left = false;
//	bool moving_up = false;
//	bool moving_down = false;
//	bool new_snake = false;
//
//	float x_array_difference[player_size] = {};
//	float y_array_difference[player_size] = {};
//
//	int player_score = 0;
//};

//struct Apple
//{
//
//	Apple();
//	void Render(RenderManager& renderManager);
//	void Initialize(unsigned int width, unsigned int height);
//
//	Rectangle rect;
//	Color color;
//	Transform trans;
//
//	bool new_apple = false;
//};