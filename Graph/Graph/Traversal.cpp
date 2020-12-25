//
//  Traversal.cpp
//  Graph
//
//  Created by Le Hoang Anh on 17/12/2020.
//

#include "Traversal.h"

void DFS(const vector<vector<bool> > &adj, vector<bool> &visited, int v) {
    if (v < 1 || v > adj.size() || adj.size() != visited.size())
        return;

    if (!visited[v - 1]) {
        cout << v << "  ";
        visited[v - 1] = true;

        for (int i = 0; i < adj.size(); i++)
            if (adj[v - 1][i] && !visited[i])
                DFS(adj, visited, i + 1);
    }
}

void DFS(const vector<list<int> > &adj, vector<bool> &visited, int v) {
    if (v < 1 || v > adj.size() || adj.size() != visited.size())
        return;

    stack<int> st;

    st.push(v - 1);
    visited[v - 1] = true;
    cout << v << "  ";

    while (!st.empty()) {
        int u = st.top();

        list<int>::const_iterator it = adj[u].begin();
        while (it != adj[u].end()) {
            if (visited[*it])
                ++it;
            else {
                cout << *it + 1 << "  ";
                visited[*it] = true;
                st.push(*it);
                
                u = *it;
                it = adj[u].begin();
            }
        }

        st.pop();
    }
}

void BFS(const vector<vector<bool> > &adj, vector<bool> &visited, int v) {
    if (v < 1 || v > adj.size() || adj.size() != visited.size())
        return;

    size_t countVertices = adj.size();
    queue<int> q;

    q.push(v - 1);
    visited[v - 1] = true;
    cout << v << "  ";

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < countVertices; i++) {
            if (adj[u][i] && !visited[i]) {
                // process...
                cout << i + 1 << "  ";

                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void BFS(const vector<list<int> > &adj, vector<bool> &visited, int v) {
    if (v < 1 || v > adj.size() || adj.size() != visited.size())
        return;

    queue<int> q;

    q.push(v - 1);
    visited[v - 1] = true;
    cout << v << "  ";

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // auto is list<int>::iterator.
        for (auto it = adj[u].begin(); it != adj[u].end(); it++) {
            if (!visited[*it]) {
                // process...
                cout << *it + 1 << "  ";

                q.push(*it);
                visited[*it] = true;
            }
        }
    }
}

void traversalEntireGraph(const vector<vector<bool> > &adj, Algorithms algorithmName) {
    size_t countVertices = adj.size();
    vector<bool> visited(countVertices, false);

    if (algorithmName == DEPTH_FIRST_SEARCH) {
        for (int i = 1; i <= countVertices; i++)
        if (!visited[i - 1])
            DFS(adj, visited, i);
    } else if (algorithmName == BREADTH_FIRST_SEARCH) {
        for (int i = 1; i <= countVertices; i++)
        if (!visited[i - 1])
            BFS(adj, visited, i);
    }
}

void traversalEntireGraph(const vector<list<int> > &adj, Algorithms algorithmName) {
    size_t countVertices = adj.size();
    vector<bool> visited(countVertices, false);

    if (algorithmName == DEPTH_FIRST_SEARCH) {
        vector<list<int> > adjList = adj;
        for (int i = 1; i <= countVertices; i++)
            if (!visited[i - 1])
                DFS(adjList, visited, i);
    } else if (algorithmName == BREADTH_FIRST_SEARCH) {
        for (int i = 1; i <= countVertices; i++)
        if (!visited[i - 1])
            BFS(adj, visited, i);
    }
}
