#include "game.h"

// Left and right player controllers
PlayerController *pLeft = nullptr, *pRight = nullptr;

// Deletes palettes
void deletePalettes()
{
	// Check if palettes exist and if so, delete
	if(pLeft != nullptr) delete pLeft;
	if(pRight != nullptr) delete pRight;	
}

// Resets game state meanwhile keeping the score
void resetState()
{
	// Delete old palettes before creating new ones
	deletePalettes();

	// Create palette with default values
	pLeft = new PlayerController();
	pLeft -> setX(5);
	pLeft -> setY(225);
	pLeft -> setW(15);
	pLeft -> setH(90);
	pLeft -> setSpeed(400);
	pLeft -> setColor(WHITE);
	pLeft -> setKeyDOWN(KEY_S);
	pLeft -> setKeyUP(KEY_W);

	pRight = new PlayerController();
	pRight -> setX(940);
	pRight -> setY(225);
	pRight -> setW(15);
	pRight -> setH(90);
	pRight -> setSpeed(400);
	pRight -> setColor(WHITE);
	pRight -> setKeyDOWN(KEY_DOWN);
	pRight -> setKeyUP(KEY_UP);
}

void Init()
{
	// Enable VSYNC
    SetConfigFlags(FLAG_VSYNC_HINT);

	// Create window
    InitWindow(960, 540, "Raylib Pong");

	// Reset game state
	resetState();
}

void Update(double dt)
{
	// Update palettes
	pLeft -> update(dt);
	pRight -> update(dt);

	// Update titlebar to show FPS
	SetWindowTitle(("Raylib Pong (FPS:" + std::to_string(int(1.0 / dt)) + ")").c_str());
}

void Draw()
{
	// Set background color
	ClearBackground(BLACK);

	// Draw palettes
	pLeft -> draw();
	pRight -> draw();
}

void End()
{
	// Make sure the palettes don't exist anymore
	deletePalettes();
}