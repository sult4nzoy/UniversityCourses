#include "sand.h"

Sand::Sand(int x, int y) : Element(5, 5, 0, randomColor()), xPos(x), yPos(y)
{
}

std::string Sand::getType()
{
	return "Sand";
}

int Sand::getX() const
{
	return xPos;
}

int Sand::getY() const
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

void Sand::setPosition(int x, int y)
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

Color Sand::randomColor()
{
	Color yellow = YELLOW;
	Color lightYellow = {245, 218, 39, 255};
	Color darkYellow = {245, 187, 39, 255};
	Color randomColors[3] = {yellow, lightYellow, darkYellow};
	int randomIndex = rand() % 3;
	return randomColors[randomIndex];
}
