#include "water.h"

Water::Water(float x, float y) : Element(6, 6, 0, BLUE), xPos(x), yPos(y)
{}

std::string Water::getType()
{
	return "Water";
}

float Water::getX() const
{
	return xPos;
}

float Water::getY() const
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

void Water::setPosition(float x, float y)
{
	xPos = x;
	yPos = y;
}

void Water::dontGoBelowFloor(int floorY)
{
	if (yPos + height > floorY)
	{
		yPos = floorY - height;
	}
}
