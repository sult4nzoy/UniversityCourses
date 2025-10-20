#pragma once
#include "raylib.h"
#include "element.h"
#include "sand.h"
#include "water.h"
#include <string>
#include <iostream>
#include <vector>


class Engine
{
public:

	Engine();
	~Engine();
    void DrawFloor() const;
    float getMousePositionX();
	float getMousePositionY();
    void updateGame();
    bool isPositionBelowEmpty(float x, float y);
    void displayTexts();

private:
    const char* gameTitle = "Sand Box Engine";
    int FPS = 120;
    int screenWidth = 1200;
    int screenHeight = 700;
    std::vector<Sand> sand;
	std::vector<Water> water;
};