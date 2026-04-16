//
// Created by Omar Sultanzoy on 2026-03-24.
//

#ifndef LABB1_DFS_H
#define LABB1_DFS_H
#include "reader.h"

using node = std::pair<weight_t, node_id_t>;
using nodeContainer = std::vector<node>;
using nodeComparer = std::greater<node>;
using path = std::pair<std::map<node_id_t, weight_t>, std::vector<node_id_t>>;

class Graph {
public:

    edge_list_t getConnectedVertexes(node_id_t vertexId, edge_list_t allEdges);
    bool dfs(adjacency_list_t graph, node_id_t startVertex);
    bool bfs(adjacency_list_t graph, node_id_t startVertex);
    path dijkstras(adjacency_list_t graph, node_id_t startVertex);
};



#endif //LABB1_DFS_H