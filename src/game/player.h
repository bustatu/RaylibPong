#ifndef PLAYER_H
#define PLAYER_H

// Raylib is used
#include <raylib-cpp.hpp>

class Palette
{
	protected:
		Rectangle mainRect;
		Color color;

	public:
		void draw();

		// Getters and setters
		void setX(double newX) 	{mainRect.x = newX;}
		void setY(double newY) 	{mainRect.y = newY;}
		double getX() 			{return mainRect.x;}
		double getY() 			{return mainRect.y;}
		void setW(double newW) 	{mainRect.width = newW;}
		void setH(double newH) 	{mainRect.height = newH;}
		void setColor(Color c) 	{color = c;}
		bool collides(Rectangle r){return CheckCollisionRecs(mainRect, r);}
};

class PlayerController : public Palette
{
	private:
		double speed;
		int keyUP, keyDOWN;

	public:
		PlayerController()
		{
			setW(15);
			setH(90);
			setSpeed(310);
			setColor(WHITE);
		}
		void update(double delta_time);

		// Getters and setters
		void setKeyUP(int newKeyUP) 			{keyUP 	= newKeyUP;}
		void setKeyDOWN(int newKeyDOWN) 	  	{keyDOWN = newKeyDOWN;}
		void setSpeed(double pixelsPerSecond) 	{speed 	= pixelsPerSecond;}
};

class AIController : public Palette
{
	private:
		double speed;

	public:
		void update(double delta_time);

		// Getters and setters
		void setSpeed(double pixelsPerSecond) 	{speed 	= pixelsPerSecond;}
};

class Ball : public Palette
{
	private:
		double speed;
		double comp_x, comp_y;
		PlayerController *rL, *rR;
	
	public:
		int hasHitEnd = 0;

	public:
		Ball(PlayerController* left, PlayerController* right)
		{
			// Set default values
			setX(470);
			setY(260);
			setW(20);
			setH(20);
			setColor(GRAY);
			setSpeed(311);

			// Save refferences to palettes
			rL = left;
			rR = right;

			// Set random direction
			int deg = rand() % 360;

			// Corrections
			if(deg >= 80 && deg <= 90) deg -= 20;
			else if(deg >= 90 && deg <= 100) deg += 20;
			else if(deg >= 260 && deg <= 270) deg -= 20;
			else if(deg >= 270 && deg <= 280) deg += 20;

			// Assign random angle
			comp_x = sin(1.0 * deg / 180 * PI);
			comp_y = cos(1.0 * deg / 180 * PI);
		}
		void update(double delta_time);

		// Getters and setters
		void setSpeed(double pixelsPerSecond) 	{speed 	= pixelsPerSecond;}	
};

#endif