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

int Engine::getMousePositionX()
{
	return static_cast<int>(GetMousePosition().x);
}

int Engine::getMousePositionY()
{
	return static_cast<int>(GetMousePosition().y);
}

void Engine::updateGame()
{
	//skapa sand objekt och lägg i sand vec
	if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
	{
		int mouseX = getMousePositionX();
		int mouseY = getMousePositionY();

		mouseX = (mouseX / 5) * 5;
		mouseY = (mouseY / 5) * 5;
		sand.push_back(Sand(mouseX, mouseY));
	}

	//skapa vatten objekt och lägg i water vec
	if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON))
	{
		int mouseX = getMousePositionX();
		int mouseY = getMousePositionY();

		mouseX = int(mouseX / 5) * 5;
		mouseY = int(mouseY / 5) * 5;
		water.push_back(Water(mouseX, mouseY));
	}

	// vattenhöjd
	int waterLevelRise = static_cast<int>((water.size() / 100) * 20); // 20 pixlar rise per 100 objekt

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
				if (isPositionBelowEmpty(s.getX() - 5, s.getY()))  // Check BELOW left position
				{
					s.setPosition(s.getX() - 5, s.getY());  // Move left only
				}
				else if (isPositionBelowEmpty(s.getX() + 5, s.getY()))  // Check BELOW right position
				{
					s.setPosition(s.getX() + 5, s.getY());  // Move right only
				}
			}
			else
			{
				if (isPositionBelowEmpty(s.getX() + 5, s.getY()))  // Check BELOW right position
				{
					s.setPosition(s.getX() + 5, s.getY());  // Move right only
				}
				else if (isPositionBelowEmpty(s.getX() - 5, s.getY()))  // Check BELOW left position
				{
					s.setPosition(s.getX() - 5, s.getY());  // Move left only
				}
			}
		}

		//collision med golv 
		if (s.getY() + s.getHeight() > screenHeight - 30)
		{
			s.setPosition(s.getX(), screenHeight - 30);
		}
	}

	//uppdatera vatten physics
	for (auto& w : water)
	{
		w.Gravity();

		//collision med golv
		if (w.getY() + w.getHeight() > screenHeight - 30)
		{
			w.setPosition(w.getX(), screenHeight - 30);
		}
	}

	// Draw water level background
	if (waterLevelRise > 0)
	{
		DrawRectangle(0, screenHeight - 30 - waterLevelRise, screenWidth, waterLevelRise, BLUE);
	}

	//rita vatten objekt
	for (auto const& w : water)
	{
		w.drawElement();
	}

	//rita sand obejtk
	for (auto const& s : sand)
	{
		s.drawElement();
	}

	displayTexts();
	DrawFloor();
}

bool Engine::isPositionBelowEmpty(int x, int y)
{
	int checkY = y + 5;

	// Check floor collision first
	if (checkY + 5 > screenHeight - 30) return false;

	for (auto const& s : sand)
	{
		if (s.getX() == x && s.getY() == checkY)
		{
			return false;
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