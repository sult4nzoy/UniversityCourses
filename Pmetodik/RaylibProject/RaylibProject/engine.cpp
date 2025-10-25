#include "engine.h"

Engine::Engine()
{
	InitWindow(screenWidth, screenHeight, gameTitle);
	SetTargetFPS(FPS);
}

Engine::~Engine()
{
	sand.clear();
	water.clear();
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
	//rensa vec om spelaren trycker R
	if (IsKeyPressed(KEY_R))
	{
		sand.clear();
		water.clear();
	}

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
	int waterLevelRise = static_cast<int>((water.size() / 50) * 20); // 20 pixlar rise per 50 objekt
	int currentWaterLevel = screenHeight - 30 - waterLevelRise;

	//uppdatera sand physics
	for (auto& s : sand)
	{
		bool isInWater = s.getY() >= currentWaterLevel;

		if (isPositionBelowEmpty(s.getX(), s.getY()))
		{
			if (isInWater)
			{
				s.slowDownGravity();
			}
			else
			{
				s.updateGravity(5);
			}

			s.Gravity();
		}
		else
		{
			s.updateGravity(5);

			int randomDir = rand() % 2;
			// 0 = vänster, else = höger

			if (randomDir == 0)
			{
				if (isPositionBelowEmpty(s.getX() - 5, s.getY()))  // kolla diagonalt vänster ned
				{
					s.setPosition(s.getX() - 5, s.getY());  // gå vänster
				}
			}
			else
			{
				if (isPositionBelowEmpty(s.getX() + 5, s.getY()))  // kolla diagonalt höger ned
				{
					s.setPosition(s.getX() + 5, s.getY());  // gå höger
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

	// höj vattnet, waterLevelRise bestämmer höjden
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
	DrawText(TextFormat("FPS: %d", GetFPS()), 1080, 15, 20, WHITE);
	DrawText(TextFormat("Sand: %d", sand.size()), 1080, 45, 20, WHITE);
	DrawText(TextFormat("Water: %d", water.size()), 1080, 75, 20, WHITE);
	DrawText(TextFormat("Press R to delete sand and water"), 20, 15, 20, WHITE);
	DrawText(TextFormat("Press MouseButton1 to spawn sand"), 20, 45, 20, WHITE);
	DrawText(TextFormat("Press MouseButton2 to spawn water"), 20, 75, 20, WHITE);
}