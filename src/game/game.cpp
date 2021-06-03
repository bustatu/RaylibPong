#include "game.h"

// Draws FPS
FPSDrawer f;

// Holds the score
ScoreHolder score;

// Left and right player controllers
PlayerController *pLeft = nullptr, *pRight = nullptr;

// Ball handler
Ball *b = nullptr;

// Deletes palettes
void deletePalettes()
{
	// Check if palettes exist and if so, delete
	if(pLeft != nullptr) delete pLeft;
	if(pRight != nullptr) delete pRight;
}

// Creates ball
void createBall()
{
	// Check ball existence
	if(b != nullptr) delete b;

	// Create ball
	b = new Ball(pLeft, pRight);
}

// Creates palettes
void createPalettes()
{
	// Delete old palettes before creating new ones
	deletePalettes();

	// Create palette with default values
	pLeft = new PlayerController();
	pLeft -> setX(5);
	pLeft -> setY(225);
	pLeft -> setKeyDOWN(KEY_S);
	pLeft -> setKeyUP(KEY_W);

	pRight = new PlayerController();
	pRight -> setX(940);
	pRight -> setY(225);
	pRight -> setKeyDOWN(KEY_DOWN);
	pRight -> setKeyUP(KEY_UP);
}

// Resets game state meanwhile keeping the score
void resetState()
{
	createBall();
}

void Init()
{
	// Enable VSYNC
    SetConfigFlags(FLAG_VSYNC_HINT);

	// Create window
    InitWindow(960, 540, "Raylib Pong");

	// Set FPS drawer values
	f.setKey(KEY_F3);

	// Set seed for RNG
	srand(time(NULL));

	// Create stuff
	createPalettes();

	// Reset game state
	resetState();
}

void Update(double dt)
{
	// Update palettes
	pLeft -> update(dt);
	pRight -> update(dt);

	// Update ball
	b -> update(dt);

	if(b -> hasHitEnd != 0)
	{
		if(b -> hasHitEnd == 1) score.incrementLeft();
		else score.incrementRight();

		resetState();
	}

	// Update fps drawer
	f.update();
}

void Draw()
{
	// Set background color
	ClearBackground(BLACK);

	// Draw FPS
	f.draw();

	// Draw score
	score.draw();

	// Draw ball
	b -> draw();

	// Draw palettes
	pLeft -> draw();
	pRight -> draw();
}

void End()
{
	// Make sure the palettes don't exist anymore
	deletePalettes();
}