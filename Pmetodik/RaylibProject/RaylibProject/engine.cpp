#include "engine.h"

Engine::Engine()
{
	InitWindow(screenWidth, screenHeight, gameTitle);
	SetTargetFPS(FPS);
}

Engine::~Engine()
{
	elements.clear();
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
    if (IsKeyPressed(KEY_R))
    {
        elements.clear();
    }

    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
    {
        int mouseX = getMousePositionX();
        int mouseY = getMousePositionY();
        mouseX = (mouseX / 5) * 5;
        mouseY = (mouseY / 5) * 5;
        elements.push_back(std::make_unique<Sand>(mouseX, mouseY));
    }

    if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON))
    {
        int mouseX = getMousePositionX();
         int mouseY = getMousePositionY();
        mouseX = (mouseX / 5) * 5;
        mouseY = (mouseY / 5) * 5;
        elements.push_back(std::make_unique<Water>(mouseX, mouseY));
    }

    //räknar ut antal vatten objekt
    auto waters = getElementsOfType<Water>();
    size_t waterLevelRise = (waters.size() / 50) * 20;
    int currentWaterLevel = screenHeight - 30 - static_cast<int>(waterLevelRise);

    //sand physics
    for (Sand* sand : getElementsOfType<Sand>()) 
    {
        bool isInWater = sand->getY() >= currentWaterLevel;

        if (isPositionBelowEmpty(sand->getX(), sand->getY())) 
        {
            if (isInWater) 
            {
                sand->slowDownGravity();
            }
            else 
            {
                sand->updateGravity(5);
            }
            sand->Gravity();
        }
        else 
        {
            sand->updateGravity(5);

            int randomDir = rand() % 2;

            if (randomDir == 0) 
            {
                if (isPositionBelowEmpty(sand->getX() - 5, sand->getY())) 
                {
                    sand->setPosition(sand->getX() - 5, sand->getY());
                }
            }
            else 
            {
                if (isPositionBelowEmpty(sand->getX() + 5, sand->getY())) 
                {
                    sand->setPosition(sand->getX() + 5, sand->getY());
                }
            }
        }

		//golv kollission
        if (sand->getY() + sand->getHeight() > screenHeight - 30) 
        {
            sand->setPosition(sand->getX(), screenHeight - 30);
        }
    }

    //vatten physics
    for (Water* water : getElementsOfType<Water>())
    {
        water->Gravity();

		//golv kollission
        if (water->getY() + water->getHeight() > screenHeight - 30) 
        {
            water->setPosition(water->getX(), screenHeight - 30);
        }
    }

    if (waterLevelRise > 0) 
    {
        DrawRectangle(0, screenHeight - 30 - static_cast<int>(waterLevelRise),
            screenWidth, static_cast<int>(waterLevelRise), BLUE);
    }

    for (auto const& e : elements) 
    {
        e->drawElement();
    }

    displayTexts();
    DrawFloor();
}

bool Engine::isPositionBelowEmpty(int x, int y)
{
	int checkY = y + 5;

	for (auto const& element : elements)
	{
		if (element->getX() == x && element->getY() == checkY)
		{
			return false;
		}
	}
	return true;
}

void Engine::displayTexts()
{
	DrawText(TextFormat("FPS: %d", GetFPS()), 980, 15, 20, WHITE);
	DrawText(TextFormat("Total elements : %d", elements.size()), 980, 45, 20, WHITE);
	DrawText(TextFormat("Press R to reset"), 20, 15, 20, WHITE);
	DrawText(TextFormat("MB1 to spawn sand"), 20, 45, 20, WHITE);
	DrawText(TextFormat("MB2 to spawn water"), 20, 75, 20, WHITE);
}

template<typename T>
std::vector<T*> Engine::getElementsOfType() 
{
    std::vector<T*> result;
    for (auto& e : elements) 
    {
        if (T* type = dynamic_cast<T*>(e.get())) 
        {
            result.push_back(type);
        }
    }
    return result;
}