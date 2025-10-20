#pragma once
#include "raylib.h"
#include <string>

class Element {

protected:
	int width;
	int height;
	float velocity;
	Color color;


public:
	Element(int width, int height, float velocity, Color color);
	virtual std::string getType() = 0;
	virtual void drawElement() const = 0;
	virtual int getWidth() const = 0;
	virtual int getHeight() const = 0;
	virtual void Gravity() = 0;
	virtual void setPosition(float x, float y) = 0;
	virtual void dontGoBelowFloor(int floorY) = 0;



	//virtual bool collisionDetection() = 0;

};

//när sand touchar vatten, så ska sand velocity bli segare så att "sanden faller mindre" i vattnet.