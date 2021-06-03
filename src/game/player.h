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
};

class PlayerController : public Palette
{
	private:
		double speed;
		int keyUP, keyDOWN;

	public:
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

#endif