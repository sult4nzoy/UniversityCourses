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
    int getMousePositionX();
	int getMousePositionY();
    void updateGame();
    bool isPositionBelowEmpty(int x, int y);
    void displayTexts();


private:
    const char* gameTitle = "Sand Box Engine";
    int FPS = 120;
    int screenWidth = 1200;
    int screenHeight = 700;
    std::vector<Sand> sand;
	std::vector<Water> water;
};