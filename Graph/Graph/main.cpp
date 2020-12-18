//
//  main.cpp
//  Graph
//
//  Created by Le Hoang Anh on 17/12/2020.
//

#include "Traversal.h"
#include "SpanningTrees.h"
#include "ShortestPath.h"
#include "TopologicalSorting.h"

vector<vector<bool>> adjacencyMatrix(const vector<vector<int>> &graph, int countVertices) {
    vector<vector<bool>> adj;

    if (countVertices > 0) {
        adj.resize(countVertices, vector<bool>(countVertices, false));

        for (int i = 0; i < graph.size(); i++) {
            adj[graph[i][0] - 1][graph[i][1] - 1] = true;
            adj[graph[i][1] - 1][graph[i][0] - 1] = true;
        }
    }

    return adj;
}

vector<list<int>> adjacencyList(const vector<vector<int>> &graph, int countVertices) {
    vector<list<int>> adj;

    if (countVertices > 0) {
        adj.resize(countVertices);

        for (int i = 0; i < graph.size(); i++) {
            adj[graph[i][0] - 1].push_back(graph[i][1] - 1);
            adj[graph[i][1] - 1].push_back(graph[i][0] - 1);
        }
    }

    return adj;
}

int main() {
    vector<vector<int>> graph = {
        {1, 2}, {1, 9}, {2, 3}, {2, 5}, {2, 10},
        {3, 4}, {3, 6}, {3, 11}, {4, 7}, {4, 12},
        {7, 8}
    };

    vector<vector<bool>> adjMatrix = adjacencyMatrix(graph, 12);
    vector<list<int>> adjList = adjacencyList(graph, 12);

    cout << "DFS: ";
    traversalEntireGraph(adjMatrix, DEPTH_FIRST_SEARCH);
    cout << endl;

    cout << "DFS: ";
    traversalEntireGraph(adjList, DEPTH_FIRST_SEARCH);
    cout << endl;

    return 0;
}
