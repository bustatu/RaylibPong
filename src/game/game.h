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

std::string convertResult(int result)
{
	if(result <= 9)
		return "0" + std::to_string(result);
	return std::to_string(result);
}

// Holds scores and draws middle line
class ScoreHolder
{
	private:
		int left = 0, right = 0;
		int lineCount = 50;
	
	public:
		void incrementLeft() {left++;}
		void incrementRight() {right++;}
		void draw()
		{
			std::string output = convertResult(left);
			DrawText(output.c_str(), 240 - MeasureText(output.c_str(), 100) / 2, 10, 100, WHITE);
			output = convertResult(right);
			DrawText(output.c_str(), 720 - MeasureText(output.c_str(), 100) / 2, 10, 100, WHITE);

			// Draw middle lines
			for(int i = 0; i < 2 * lineCount; i+=2)
				DrawRectangle(479, (270.0 / lineCount) * i, 2, 270.0 / lineCount, WHITE);
		}
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