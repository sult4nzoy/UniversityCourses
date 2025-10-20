#pragma once
#include "element.h"

class Water : public Element
{
private:
	float xPos;
	float yPos;

public:
	Water(float x, float y);
	std::string getType() override;
	float getX() const;
	float getY() const;
	void drawElement() const override;
	int getWidth() const override;
	int getHeight() const override;
	void Gravity() override;
	void setPosition(float x, float y) override;
	void dontGoBelowFloor(int floorY) override;

	//bool collisionDetection() override;
};