#pragma once
#include "element.h"

class Water : public Element
{

public:
	Water(int x, int y);
	int getX() const;
	int getY() const;
	void drawElement() const override;
	int getWidth() const override;
	int getHeight() const override;
	void Gravity() override;
	void setPosition(int x, int y) override;
};