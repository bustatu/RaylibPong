#ifndef GAME_H
#define GAME_H

// Raylib is used
#include <raylib-cpp.hpp>

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

// Holds scores
class ScoreHolder
{
	private:
		int left = 0, right = 0;
	
	public:
		void incrementLeft() {left++;}
		void incrementRight() {right++;}
};

#endif