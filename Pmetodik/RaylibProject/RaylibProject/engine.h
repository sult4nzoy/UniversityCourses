#pragma once
#include "raylib.h"
#include "element.h"
#include "sand.h"
#include "water.h"
#include <string>
#include <iostream>
#include <vector>
#include <memory>


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

    template<typename T>
    std::vector<T*> getElementsOfType();


private:
    const char* gameTitle = "Sand Box Engine";
    int FPS = 120;
    int screenWidth = 1200;
    int screenHeight = 700;
    std::vector<std::unique_ptr<Element>> elements;
};