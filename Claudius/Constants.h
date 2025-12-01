#pragma once
#include "SDL.h"
#include <string_view>


static constexpr int Rect_tile = 10;
static constexpr int SnakeColour[4] = { 0, 255, 0, 0 };
static constexpr int TailColour[4] = { 100, 255, 0, 0 };
static constexpr int AppleColour[4] = { 255, 0, 0, 0 };
static constexpr int SnakeMovementSpeed = 10;
static constexpr int width = 1250;
static constexpr int height = 700;

static constexpr std::string_view title = "Snake";

static int snakePosX = 0;
static int snakePosY = 0;
static int applePosY = 0;
static int applePosX = 0;

static int playerScore = 0;



