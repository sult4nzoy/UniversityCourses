//
// Created by Omar Sultanzoy on 2026-03-24.
//

#include "graph.h"

edge_list_t Graph::getConnectedVertexes(node_id_t vertexId, const edge_list_t& allEdges) {
    edge_list_t neighbors;
    for (const auto &e : allEdges) {
        if (e.n1 == vertexId) {
            neighbors.push_back(e);
        }
    }
    return neighbors;
}

bool Graph::dfs(adjacency_list_t graph, node_id_t startVertex) {
    std::stack<node_id_t> container;
    std::map<node_id_t, bool> visited;
    int visitedCount = 0;
    container.push(startVertex);
    while (!container.empty()) {
        node_id_t currentVertex = container.top();
        container.pop();
        if (!visited[currentVertex]) {
            visited[currentVertex] = true;
            visitedCount++;
            edge_list_t neighbors = getConnectedVertexes(currentVertex, graph.second);
            for (const auto &e : neighbors) {
                if (!visited[e.n2]) {
                    container.push(e.n2);
                }
            }
        }
    }
    return visitedCount == graph.first.size();
}

bool Graph::bfs(adjacency_list_t graph, node_id_t startVertex) {
    std::queue<node_id_t> container;
    std::map<node_id_t, bool> visited;
    int visitedCount = 0;
    container.push(startVertex);
    while (!container.empty()) {
        node_id_t currentVertex = container.front();
        container.pop();
        if (!visited[currentVertex]) {
            visited[currentVertex] = true;
            visitedCount++;
            edge_list_t neighbors = getConnectedVertexes(currentVertex, graph.second);
            for (const auto &e : neighbors) {
                if (!visited[e.n2]) {
                    container.push(e.n2);
                }
            }
        }
    }
    return visitedCount == graph.first.size();
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
        node_id_t currNode = pq.top().second;
        pq.pop();
        if (currentDistance > distance[currNode]) {
            continue;
        }
        for (const auto &e : getConnectedVertexes(currNode, graph.second)) {
            node_id_t NextNode = e.n2;
            weight_t weight = e.weight;
            if (distance[currNode] + weight < distance[NextNode]) {
                distance[NextNode] = distance[currNode] + weight;
                parent[NextNode] = currNode;
                pq.push(node{distance[NextNode], NextNode});
            }
        }
    }
    return {distance, parent};
}
