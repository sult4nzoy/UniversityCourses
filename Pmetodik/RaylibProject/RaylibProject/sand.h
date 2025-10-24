#pragma once
#include "element.h"

class Sand : public Element{

private:
	int xPos;
	int yPos;

public:
	Sand(int x, int y);
	std::string getType() override;
	int getX() const;
	int getY() const;
	void drawElement() const override;
	int getWidth() const override;
	int getHeight() const override;
	void Gravity() override;
	void setPosition(int x, int y) override;
	void dontGoBelowFloor(int floorY) override;
	Color randomColor();
	//bool collisionDetection() override;
};