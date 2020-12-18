//
//  SpanningTrees.cpp
//  Graph
//
//  Created by Le Hoang Anh on 18/12/2020.
//

#include "SpanningTrees.h"

void BFS(const vector<list<int> > &adj, vector<bool> &visited, int v, vector<vector<int> > &tree) {
    if (v < 1 || v > adj.size() || adj.size() != visited.size())
        return;

    queue<int> q;

    q.push(v - 1);
    visited[v - 1] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // auto is list<int>::iterator.
        for (auto it = adj[u].begin(); it != adj[u].end(); it++) {
            if (!visited[*it]) {
                tree.push_back({u + 1, *it + 1});

                q.push(*it);
                visited[*it] = true;
            }
        }
    }
}

vector<vector<int> > spanningTree(const vector<vector<int> > edges, int vertices) {
    vector<vector<int> > tree;
    vector<bool> visited(vertices, false);
    vector<list<int> > adj = adjacencyList(edges, vertices);

    for (int i = 1; i < vertices; i++)
        if (!visited[i - 1])
            BFS(adj, visited, i, tree);

    return tree;
}
