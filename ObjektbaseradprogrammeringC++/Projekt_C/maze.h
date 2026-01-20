/*
    Namn: Omar Sultanzoy
    Kurs: Objektbaseradprogrammering i C++
    Kursansvarig: Jimmy Åhlander
    Aktuellt datum: 2025-05-18
    Betyg som jag siktar på: E
*/

#include <iostream>
#include <stack>
#include <vector>
#include <limits>

struct node
{
    int x, y;
	bool upDownLeftRight[4] = {false, false, false, false}; // upp, ner, vänster, höger
    bool visited = false;
    bool solved = false;
};


class maze
{

public:

    maze(int x, int y);
    ~maze();
    node* getNode(int x, int y);
    void setEntryAndExitPoint(); 
    void dfs();
    std::vector<node*> getUnvisitedNeighbors(node* currentNode); 
    void directionToNode(node* currentNode, node* nextNode);
    void visualizeMaze();
    void setNodesUnvisited();
    
private:

    int height = 7;
    int width = 7;
    std::vector<std::vector<node*>> twoDGrid;
    node* entryNode;
    node* exitNode;

};
