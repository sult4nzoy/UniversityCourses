//
// Created by Omar Sultanzoy on 2026-03-24.
//

#ifndef LABB1_DFS_H
#define LABB1_DFS_H
#include "reader.h"
#include <stack>


class Graph {

    private:


    public:

    edge_list_t getConnectedVertexes(node_id_t vertexId, edge_list_t allEdges);

    void dfs(adjacency_list_t graph, node_id_t startVertex); //algoritmen tar emot en "karta" och en startpunkt
    void bfs(adjacency_list_t graph, node_id_t startVertex); //algoritmen tar emot en "karta" och en startpunkt
    void dijkstras(adjacency_list_t graph, node_id_t startVertex);

};


#endif //LABB1_DFS_H