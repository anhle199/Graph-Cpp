//
//  TopologicalSorting.cpp
//  Graph
//
//  Created by Le Hoang Anh on 18/12/2020.
//

#include "TopologicalSorting.h"
#include <queue>
#include <stack>

void DFS(const vector<vector<bool>> &adj, vector<bool> &visited, stack<int> &vertices, int v) {
    visited[v - 1] = true;

    for (int i = 0; i < adj[v - 1].size(); i++)
        if (!visited[i] && adj[v - 1][i])
            DFS(adj, visited, vertices, i + 1);

    vertices.push(v);
}

void DFS(const vector<list<int>> &adj, vector<bool> &visited, stack<int> &vertices, int v) {
    stack<int> s;

    s.push(v - 1);
    visited[v - 1] = true;

    while (!s.empty()) {
        int u = s.top();

        list<int>::const_iterator it = adj[u].begin();
        while (it != adj[u].end()) {
            if (!visited[*it])
                break;

            it++;
        }

        if (it == adj[u].end()) {
            s.pop();

            if (u + 1 != v)
                vertices.push(u + 1);
        } else {
            s.push(*it);
            visited[*it] = true;
        }
    }

    vertices.push(v);
}

vector<int> topologicalSorting(const vector<vector<int>> &edges, int countVertices) {
    stack<int> vertices;
    vector<bool> visited(countVertices, false);
//    vector<vector<bool>> adj = DirectedGraph::adjacencyMatrix(edges, countVertices);
    vector<list<int>> adj = DirectedGraph::adjacencyList(edges, countVertices);

    for (int i = 1; i <= countVertices; i++)
        if (!visited[i - 1])
            DFS(adj, visited, vertices, i);

    vector<int> result;

    while (!vertices.empty()) {
        result.push_back(vertices.top());
        vertices.pop();
    }

    return result;
}
