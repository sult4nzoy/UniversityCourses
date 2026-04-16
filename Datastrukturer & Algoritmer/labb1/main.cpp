#include <algorithm>

#include "graph.h"
#include "reader.h"
std::ostream& operator<<(std::ostream& os, const std::vector<node_id_t>& route) {
    os << route[0];
    for (size_t i = 1; i < route.size(); i++) {
        os << " -> " << route[i];
    }
    return os;
}


int main() {
    std::system("chcp 65001");
    std::string fileName = "C:/Users/Omar Sultanzoy/Desktop/UniversityCourses/Datastrukturer & Algoritmer/labb1/edges";

    auto data = parse_file(fileName);

    if (data.first.empty()) {
        std::cout << "Filen är tom"<< std::endl;
    }
    Graph graph;
    std::cout << "1. DFS" << std::endl;
    std::cout << "2. BFS" << std::endl;
    std::cout << "3. Dijkstras" << std::endl;
    std::cout << "Val: ";
    int choice;
    int startingNode = 0;
    std::cin>> choice;
    switch (choice) {
        case 1: {
           bool connected =  graph.dfs(data, startingNode);
            if (connected) {
                std::cout << "alla noder besökt, den är sammanhängande" << std::endl;
            }
            else {
                std::cout << "alla noder ej besökt, den är ej sammanhängande" << std::endl;
            }
            break;
        }
        case 2: {
            bool connected = graph.bfs(data, startingNode);
            if (connected) {
                std::cout << "alla noder besökt, den är sammanhängande" << std::endl;
            }
            else {
                std::cout << "alla noder ej besökt, den är ej sammanhängande" << std::endl;
            }
            break;
        }
        case 3: {
            int startNode, targetNode;
            std::cout << "Startnod: ";
            std::cin >> startNode;
            std::cout << "Slutnod: ";
            std::cin >> targetNode;

            path res = graph.dijkstras(data, startNode);

            std::vector<node_id_t> route;
            node_id_t curr = targetNode;

            while (curr != startNode) {
                route.push_back(curr);
                curr = res.second[curr];
            }
            route.push_back(startNode);
            std::reverse(route.begin(), route.end());

            std::cout << "Kortaste väg: " << route << std::endl;
            std::cout << "Distans: " << res.first[targetNode] << std::endl;
            break;
        }
        default: std::cout << "fel indata" << std::endl;
            break;
    }
    return 0;
}

//Nackstavägen nod 24 -> Förrådet nod 37
//Resultat = Kortaste väg: 24 -> 23 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 10 -> 28 -> 37, Distans: 1726.18

//L319 nod 46 -> D025 nod 47
//Resultat = Kortaste väg: 46 -> 44 -> 30 -> 20 -> 10 -> 28 -> 47, Distans: 479.65

//Universitetet nod 20 -> Biteline västra nod 19
//Resultat = Kortaste väg: 20 -> 10 -> 8 -> 7 -> 6 -> 5 -> 4 -> 3 -> 19, Distans: 1207.5