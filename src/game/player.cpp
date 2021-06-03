#include "player.h"

#pragma region Palette functions

void Palette::draw()
{
	DrawRectangleRounded(mainRect, 0, 1, color);
}

#pragma endregion

#pragma region Player functions

void makePositionValid(Rectangle *rect)
{
	if(rect -> x < 0) rect -> x = 0;
	if(rect -> y < 0) rect -> y = 0;
	if(rect -> x + rect -> width > 960) rect -> x = 960 - rect -> width;
	if(rect -> y + rect -> height > 540) rect -> y = 540 - rect -> height;
}

void PlayerController::update(double dt)
{
	// Update coordonates
	setY(getY() + dt * speed * (IsKeyDown(keyDOWN) - IsKeyDown(keyUP)));

	// If input is invalid (IE: moves palette offscreen), make it valid
	makePositionValid(&mainRect);
}

#pragma endregion

#pragma region AI functions

#pragma endregion