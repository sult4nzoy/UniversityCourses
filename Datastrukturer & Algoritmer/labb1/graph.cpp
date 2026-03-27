//
// Created by Omar Sultanzoy on 2026-03-24.
//

#include "graph.h"

#include <queue>

edge_list_t Graph::getConnectedVertexes(node_id_t vertexId, edge_list_t allEdges) {
    edge_list_t neighbors;
    for (const auto &e : allEdges) {
        if (e.n1 == vertexId) {
            neighbors.push_back(e);
        }
    }
    return neighbors;
}

void Graph::dfs(adjacency_list_t graph, node_id_t startVertex) {
    std::stack<node_id_t> stack;
    std::map<node_id_t, bool> visited;
    for (auto const &[id, edge] : graph.first) {
        visited[id] = false;
    }
    stack.push(startVertex);
    std::cout << "Algoritmen startas från nod: " << startVertex << std::endl;
    while (!stack.empty()) {
        node_id_t currentVertex = stack.top();
        stack.pop();
        if (!visited[currentVertex]) {
            visited[currentVertex] = true;
            std::cout << "Besöker nod: " << currentVertex << ", " << graph.first.at(currentVertex) << std::endl;
            edge_list_t connectedVertexes = getConnectedVertexes(currentVertex, graph.second);
            for (const auto &e : connectedVertexes) {
                if (!visited[e.n2]) {
                    stack.push(e.n2);
                }
            }
        }
    }
}

void Graph::bfs(adjacency_list_t graph, node_id_t vertexId) {
    std::queue<node_id_t> queue;
    std::map<node_id_t, bool> visited;
    for (auto const &[id, name] : graph.first) {
        visited[id] = false;
    }
    visited[vertexId] = true;
    queue.push(vertexId);
    std::cout << "Algoritmen startas från nod: " << vertexId << std::endl;
    while (!queue.empty()) {
        node_id_t currentVertex = queue.front();
        queue.pop();
        std::cout << "Besöker nod: " << currentVertex << ", " << graph.first.at(currentVertex) << std::endl;
        edge_list_t connectedVertexes = getConnectedVertexes(currentVertex, graph.second);
        for (const auto &e : connectedVertexes) {
            if (!visited[e.n2]) {
                visited[e.n2] = true;
                queue.push(e.n2);
            }
        }
    }
}

void Graph::dijkstras(adjacency_list_t graph, node_id_t startVertex) {
    
}
