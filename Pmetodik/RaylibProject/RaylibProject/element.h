#pragma once
#include "raylib.h"
#include <string>

class Element {

protected:
	int xPos;
	int yPos;
	int width;
	int height;
	int velocity;
	Color color;


public:
	Element(int x, int y, int width, int height, int velocity, Color color);
	virtual void drawElement() const = 0;
	virtual int getWidth() const = 0;
	virtual int getHeight() const = 0;
	virtual void Gravity() = 0;
	virtual void setPosition(int x, int y) = 0;
	virtual int getX() const = 0;
	virtual int getY() const = 0;

};