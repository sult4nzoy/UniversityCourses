/*
    Namn: Omar Sultanzoy
    Kurs: Objektbaseradprogrammering i C++
    Kursansvarig: Jimmy Åhlander
    Aktuellt datum: 2025-05-18
    Betyg som jag siktar på: E
*/

#include "maze.h"

maze::maze(int x, int y) // konstruktor, för att initialisera pekarna och för att stoppa in noder i twoDGrid
{
    entryNode = nullptr;
    exitNode = nullptr;

    std::vector<node *> tempVec;

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            node *tempNode = new node();
            tempNode->x = i;
            tempNode->y = j;
            tempVec.push_back(tempNode);
        }
        twoDGrid.push_back(tempVec);
        tempVec.clear();
    }
}

maze::~maze() // destruktor för att ta bort alla noder innan programmet avslutas
{
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            delete twoDGrid[x][y];
        }
    }
}

node *maze::getNode(int x, int y) // för att hämta en specifik nod
{
    return twoDGrid[x][y];
}

void maze::setEntryAndExitPoint() // för att sätta start och slut nod
{
    entryNode = getNode(0, 0);
    exitNode = getNode(width - 1, height - 1);
}

void maze::setNodesUnvisited() // för att iterera igenom twoDGrid och sätta alla noder till unvisited
{
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            node *current = getNode(x, y);
            current->visited = false;
        }
    }
}

void maze::dfs()
{
    setNodesUnvisited();

    node *N = entryNode;
    N->visited = true;
    std::stack<node *> S;
    S.push(N);

    while (!S.empty())
    {
        N = S.top();
        std::vector<node *> unvisitedNeighbors = getUnvisitedNeighbors(N);

        if (!unvisitedNeighbors.empty())
        {
            int randomDir = rand() % unvisitedNeighbors.size();

            node *G = unvisitedNeighbors[randomDir];

            G->visited = true;
            directionToNode(N, G);
            S.push(G);
        }
        else
        {
            S.pop();
        }
    }
}

std::vector<node *> maze::getUnvisitedNeighbors(node *currentNode)
{
    std::vector<node *> neighbors;

    int x = currentNode->x;
    int y = currentNode->y;

    if (x > 0)
    {
        if (!getNode(x - 1, y)->visited) // vänster
        {
            neighbors.push_back(getNode(x - 1, y));
        }
    }
    if (x < width - 1)
    {
        if (!getNode(x + 1, y)->visited) // höger
        {
            neighbors.push_back(getNode(x + 1, y));
        }
    }
    if (y > 0)
    {
        if (!getNode(x, y - 1)->visited) // upp
        {
            neighbors.push_back(getNode(x, y - 1));
        }
    }
    if (y < height - 1)
    {
        if (!getNode(x, y + 1)->visited) // ner
        {
            neighbors.push_back(getNode(x, y + 1));
        }
    }

    return neighbors;
}
void maze::directionToNode(node *currentNode, node *nextNode) // öppna väggen mellan currentNode och nextNode
{
    int xDiff = currentNode->x - nextNode->x;
    int yDiff = currentNode->y - nextNode->y;

    if (xDiff == 1)
    {
        currentNode->upDownLeftRight[2] = true;
        nextNode->upDownLeftRight[3] = true;
    }
    else if (xDiff == -1)
    {
        currentNode->upDownLeftRight[3] = true;
        nextNode->upDownLeftRight[2] = true;
    }
    else if (yDiff == 1)
    {
        currentNode->upDownLeftRight[0] = true;
        nextNode->upDownLeftRight[1] = true;
    }
    else if (yDiff == -1)
    {
        currentNode->upDownLeftRight[1] = true;
        nextNode->upDownLeftRight[0] = true;
    }
}

void maze::visualizeMaze()
{
    int visHeight = height * 2 + 1;
    int visWidth = width * 2 + 1;

    for (int x = 0; x < visWidth; x++)
    {
        for (int y = 0; y < visHeight; y++)
        {

            if (x == 1 && y == 0) // sätta entry och exit point
            {

                std::cout << "S";
                continue;
            }
            else if (x == 13 && y == 14)
            {

                std::cout << "E";
                continue;
            }

            if (x == 0 || y == 0 || x == visWidth - 1 || y == visHeight - 1) // alla borders
            {

                std::cout << "#";
                continue;
            }

            if (x % 2 == 1 && y % 2 == 1) // om vi är på en nodposition (båda udda)
            {
                std::cout << " ";
            }

            else if (x % 2 == 0 && y % 2 == 1) // mellan två noder horisontellt (x jämn, y udda) allstå en vägg eller väg
            {
                int nodeX = x / 2;
                int nodeY = y / 2;
                node *leftNode = getNode(nodeX - 1, nodeY);

                if (leftNode->upDownLeftRight[3]) // right
                {
                    std::cout << " ";
                }
                else
                {
                    std::cout << "#";
                }
            }

            else if (x % 2 == 1 && y % 2 == 0) // mellan två noder vertikalt (x udda, y jämn)
            {
                int nodeX = x / 2;
                int nodeY = y / 2;
                node *topNode = getNode(nodeX, nodeY - 1);

                if (topNode->upDownLeftRight[1]) // down
                {
                    std::cout << " ";
                }
                else
                {
                    std::cout << "#";
                }
            }

            else // Hörn eller väggar (x jämn, y jämn)
            {
                std::cout << "#";
            }
        }
        std::cout << std::endl;
    }
}