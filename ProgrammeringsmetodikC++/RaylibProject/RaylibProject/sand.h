#pragma once
#include "element.h"

class Sand : public Element{

public:
	Sand(int x, int y);
	int getX() const override;
	int getY() const override;
	void drawElement() const override;
	int getWidth() const override;
	int getHeight() const override;
	void Gravity() override;
	void setPosition(int x, int y) override;
	Color randomColor();
	void slowDownGravity();
	void updateGravity(int velocity);
};