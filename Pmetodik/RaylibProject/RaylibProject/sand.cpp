#include "sand.h"

Sand::Sand(int x, int y) : Element(5, 5, 0, YELLOW), xPos(x), yPos(y)
{
}

std::string Sand::getType()
{
	return "Sand";
}

float Sand::getX() const
{
	return xPos;
}

float Sand::getY() const
{
	return yPos;;
}

void Sand::drawElement() const
{
	DrawRectangle(xPos, yPos, width, height, color);
}

int Sand::getWidth() const
{
	return width;
}

int Sand::getHeight() const
{
	return height;
}

void Sand::Gravity()
{
	yPos += velocity + 5;
}

void Sand::setPosition(float x, float y)
{
	xPos = x;
	yPos = y;
}


void Sand::dontGoBelowFloor(int floorY)
{
	if (yPos + height > floorY)
	{
		yPos = floorY - height;
	}
}