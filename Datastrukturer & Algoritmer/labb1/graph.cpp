//
// Created by Omar Sultanzoy on 2026-03-24.
//

#include "graph.h"

edge_list_t Graph::getConnectedVertexes(node_id_t vertexId, edge_list_t allEdges) {
    edge_list_t neighbors;
    for (const auto &e : allEdges) {
        if (e.n1 == vertexId) {
            neighbors.push_back(e);
        }
    }
    return neighbors;
}

bool Graph::dfs(adjacency_list_t graph, node_id_t startVertex) {
    std::stack<node_id_t> stack;
    std::map<node_id_t, bool> visited;
    stack.push(startVertex);
    std::cout << "Algoritmen startas från nod: " << startVertex << std::endl;
    while (!stack.empty()) {
        node_id_t currentVertex = stack.top();
        stack.pop();
        if (!visited[currentVertex]) {
            visited[currentVertex] = true;
            std::cout << "Besöker nod: " << currentVertex << ", " << graph.first.at(currentVertex) << std::endl;
            edge_list_t connectedVertexesToCurrentVertex = getConnectedVertexes(currentVertex, graph.second);
            for (const auto &e : connectedVertexesToCurrentVertex) {
                if (!visited[e.n2]) {
                    stack.push(e.n2);
                }
            }
        }
    }
    return graph.second.size() == stack.size();
}

bool Graph::bfs(adjacency_list_t graph, node_id_t startVertex) {
    std::queue<node_id_t> queue;
    std::map<node_id_t, bool> visited;
    visited[startVertex] = true;
    queue.push(startVertex);
    std::cout << "Algoritmen startas från nod: " << startVertex << std::endl;
    while (!queue.empty()) {
        node_id_t currentVertex = queue.front();
        queue.pop();
        std::cout << "Besöker nod: " << currentVertex << ", " << graph.first.at(currentVertex) << std::endl;
        edge_list_t connectedVertexesToCurrentVertex = getConnectedVertexes(currentVertex, graph.second);
        for (const auto &e : connectedVertexesToCurrentVertex) {
            if (!visited[e.n2]) {
                visited[e.n2] = true;
                queue.push(e.n2);
            }
        }
    }
    return graph.second.size() == queue.size();
}


path Graph::dijkstras(adjacency_list_t graph, node_id_t startVertex) {
    std::map<node_id_t, weight_t> distance;
    std::vector<node_id_t> parent(graph.first.size());
    for (const auto &[nodeId, name] : graph.first) {
        distance[nodeId] = std::numeric_limits<weight_t>::infinity();
    }
    distance[startVertex] = 0;
    std::priority_queue<node, nodeContainer, nodeComparer> pq;
    pq.push(node{0.0, startVertex});
    while (!pq.empty()) {
        weight_t currentDistance = pq.top().first;
        node_id_t u = pq.top().second;
        pq.pop();

        if (currentDistance > distance[u]) {
            continue;
        }

        for (const auto &e : getConnectedVertexes(u, graph.second)) {
            node_id_t v = e.n2;
            weight_t weight = e.weight;
            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                parent[v] = u;
                pq.push(node{distance[v], v});
            }
        }
    }
    return {distance, parent};
}
