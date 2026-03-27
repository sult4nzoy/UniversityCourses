#include "graph.h"
#include "reader.h"

int main() {

    std::string fileName = "C:/Users/Omar Sultanzoy/Desktop/UniversityCourses/Datastrukturer & Algoritmer/labb1/edges";

    auto data = parse_file(fileName);

    if (data.first.empty()) {
        std::cout << "Filen är tom"<< std::endl;
    }
/*

    std::cout << "Antal noder: " << meta.size() << std::endl;
    for (const auto& [node_id_t, name ] : meta) {
        std::cout << "Node ID: " << node_id_t << ", name: " << name << std::endl;
    }
    std::cout << "_______________________________________" << std::endl;

    for (const auto& e : edge) {
        std::cout << "Start node: " << e.n1 << ", end node: " << e.n2 << ", weight: "
        << e.weight << ", description: " << e.description<< std::endl;
    }
    */

    Graph graph;
    //graph.dfs(data, 0);
    graph.bfs(data, 0);
    return 0;
}