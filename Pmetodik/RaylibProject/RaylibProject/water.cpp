#include "water.h"

Water::Water(int x, int y) : Element(x, y, 20, 20, 0, BLUE)
{}

int Water::getX() const
{
	return xPos;
}

int Water::getY() const
{
	return yPos;;
}

void Water::drawElement() const
{
	DrawRectangle(xPos, yPos, width, height, color);
}

int Water::getWidth() const
{
	return width;
}

int Water::getHeight() const
{
	return height;
}

void Water::Gravity()
{
	yPos += velocity + 5;
}

void Water::setPosition(int x, int y)
{
	xPos = x;
	yPos = y;
}



