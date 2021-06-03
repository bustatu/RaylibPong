#ifndef GAME_H
#define GAME_H

// All headers used
#include <raylib-cpp.hpp>
#include <time.h>

// Game-related headers
#include "player.h"

// Main init function
void Init();

// Main update function
void Update(double delta_time = 0);

// Main drawing function
void Draw();

// Main end function
void End();

// Holds scores and draws middle line
class ScoreHolder
{
	private:
		int left = 0, right = 0;
		int lineCount = 50;
	
	public:
		void incrementLeft() {left++;}
		void incrementRight() {right++;}
		void draw();
};

// Draws FPS
class FPSDrawer
{
	private:
		bool toggle = false;
		int key;

	public:
		void setKey(int newKey) {key = newKey;}
		void update()
		{
			if(IsKeyPressed(key))
				toggle = !toggle;
		}
		void draw()
		{
			if(toggle)
				DrawFPS(0, 0);
		}
};

#endif