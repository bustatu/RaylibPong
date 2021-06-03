#include "player.h"

void makePositionValid(Rectangle *rect)
{
	if(rect -> x < 0) rect -> x = 0;
	if(rect -> y < 0) rect -> y = 0;
	if(rect -> x + rect -> width > 960) rect -> x = 960 - rect -> width;
	if(rect -> y + rect -> height > 540) rect -> y = 540 - rect -> height;
}

#pragma region Palette and ball functions

void Palette::draw()
{
	DrawRectangleRounded(mainRect, 0, 1, color);
}

void Ball::update(double dt)
{
	setX(getX() + comp_x * dt * speed);
	setY(getY() + comp_y * dt * speed);

	makePositionValid(&mainRect);
	if(mainRect.y == 0 || mainRect.y == 540 - mainRect.height) comp_y = -comp_y, speed += 5;
	if(rL -> collides(mainRect) || rR -> collides(mainRect))
	{
		comp_x = -comp_x;
		speed += 5;
	}
	if(mainRect.x == 0) hasHitEnd = 2;
	if(mainRect.x == 960 - mainRect.width) hasHitEnd = 1;
}

#pragma endregion

#pragma region Player and AI functions

void PlayerController::update(double dt)
{
	// Update coordonates
	setY(getY() + dt * speed * (IsKeyDown(keyDOWN) - IsKeyDown(keyUP)));

	// If input is invalid (IE: moves palette offscreen), make it valid
	makePositionValid(&mainRect);
}

#pragma endregion