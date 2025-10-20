#pragma once
#include "element.h"

class Sand : public Element{

private:
	int xPos;
	int yPos;

public:
	Sand(int x, int y);
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