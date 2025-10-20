#include "engine.h"

Engine::Engine() 
{
    InitWindow(screenWidth, screenHeight, gameTitle);
    SetTargetFPS(FPS);
}

Engine::~Engine()
{
    CloseWindow();
}

void Engine::DrawFloor() const
{
	DrawRectangle(0, screenHeight - 30, screenWidth, 30, BROWN);
}

float Engine::getMousePositionX()
{
    return static_cast<int>(GetMousePosition().x);
}

float Engine::getMousePositionY()
{
	return static_cast<int>(GetMousePosition().y);
}

void Engine::updateGame()
{
	//skapa sand objekt och lägg i sand vec
	if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
	{
		sand.push_back(Sand(getMousePositionX(), getMousePositionY()));

	}

	//rita sand obejtk
	for (auto const& s : sand)
	{
		s.drawElement();
	}

	//skapa vatten objekt och lägg i water vec
	if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON))
	{
		water.push_back(Water(getMousePositionX(), getMousePositionY()));
	}
	//rita vatten objekt
	for (auto const& w : water)
	{
		w.drawElement();
	}

	//uppdatera sand physics
	for (auto& s : sand)
	{

		if (isPositionBelowEmpty(s.getX(), s.getY()))
		{
			s.Gravity();
		}
		else
		{
			
			int randomDir = rand() % 2;
			// 0 = left, else = right

			if (randomDir == 0) 
			{
				if (isPositionBelowEmpty(s.getX() - 5, s.getY()))
				{
					s.setPosition(s.getX() - 5, s.getY());
				}
				else if (isPositionBelowEmpty(s.getX() + 5, s.getY())) 
				{
					s.setPosition(s.getX() + 5, s.getY()); 
				}
			}
			else {
				if (isPositionBelowEmpty(s.getX() + 5, s.getY())) 
				{
					s.setPosition(s.getX() + 5, s.getY()); 
				}
				else if (isPositionBelowEmpty(s.getX() - 5, s.getY())) 
				{
					s.setPosition(s.getX() - 5, s.getY());
				}
			}
		}

		//collision med golv
		if (s.getY() + s.getHeight() > screenHeight - 30)
		{
			s.dontGoBelowFloor(screenHeight - 30);
		}
	}

	//uppdatera vatten physics
	for (auto& w : water)
	{
		w.Gravity();

		//collision med golv
		if (w.getY() + w.getHeight() > screenHeight - 30)
		{
			w.dontGoBelowFloor(screenHeight - 30);
		}
	}
	displayTexts();
	DrawFloor();
}

bool Engine::isPositionBelowEmpty(float x, float y)
{
	if (!sand.empty()) 
	{
		float elementHeight = sand[0].getHeight();
		float checkY = y + elementHeight;

		for (const auto& s : sand)
		{
			if (x < s.getX() + s.getWidth() &&
				x + s.getWidth() > s.getX() &&
				checkY < s.getY() + s.getHeight() &&
				checkY + s.getHeight() > s.getY())
			{
				return false;
			}
		}
	}
	return true;
}

void Engine::displayTexts()
{
	DrawText(TextFormat("FPS: %d", GetFPS()), 20, 20, 20, WHITE);
	DrawText(TextFormat("Sand: %d", sand.size()), 20, 45, 20, WHITE);
	DrawText(TextFormat("Water: %d", water.size()), 20, 65, 20, WHITE);
}
