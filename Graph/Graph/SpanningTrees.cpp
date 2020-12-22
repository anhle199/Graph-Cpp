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

vector<vector<int> > spanningTree(const vector<vector<int> > edges, int vertices, bool directed) {
    vector<vector<int> > tree;
    vector<bool> visited(vertices, false);
    vector<list<int> > adj;

    if (directed)
        adj = DirectedGraph::adjacencyList(edges, vertices);
    else
        adj = UndirectedGraph::adjacencyList(edges, vertices);

    for (int i = 1; i < vertices; i++)
    if (!visited[i - 1])
        BFS(adj, visited, i, tree);

    return tree;
}

list<WeightedEdge>::const_iterator findMinWeight(const list<WeightedEdge> &edges, const vector<bool> &visited) {
    list<WeightedEdge>::const_iterator minEdge = edges.begin();
    list<WeightedEdge>::const_iterator edge = edges.begin();

    if (edge != edges.end()) {
        while (minEdge != edges.end() && (visited[minEdge->start] && visited[minEdge->end]))
            ++minEdge;

        if (minEdge == edges.end())
            return edges.end();

        edge = minEdge;
        ++edge;
        while (edge != edges.end()) {
            if ((!visited[edge->start] || !visited[edge->end]) && edge->weight < minEdge->weight)
                minEdge = edge;

            ++edge;
        }
    }

    return minEdge;
}

list<WeightedEdge>::const_iterator min(const list<WeightedEdge>::const_iterator &edge1, const list<WeightedEdge>::const_iterator &edge2, const list<WeightedEdge>::const_iterator &edge3) {
    if (edge1->weight <= edge2->weight)
        return (edge1->weight <= edge3->weight) ? edge1 : edge3;

    return (edge2->weight <= edge3->weight) ? edge2 : edge3;
}

vector<WeightedEdge> Prim(const vector<list<WeightedEdge> > &adj, vector<bool> &visited) {
    vector<WeightedEdge> mst;

    if (!adj.empty()) {
        int i = 0;
        while (adj[i].empty())
            ++i;

        auto edge = findMinWeight(adj[i], visited);
        mst.push_back(*edge);
        visited[edge->start] = visited[edge->end] = true;

        while (mst.size() < adj.size() - 1) {
            list<WeightedEdge>::const_iterator minEdge;

            for (const WeightedEdge &edge : mst) {
                auto it = findMinWeight(adj[edge.start], visited);
                if (it != adj[edge.start].end()) {
                    minEdge = it;
                    break;
                }

                it = findMinWeight(adj[edge.end], visited);
                if (it != adj[edge.end].end()) {
                    minEdge = it;
                    break;
                }
            }

            for (const WeightedEdge &edge : mst) {
                auto it = findMinWeight(adj[edge.start], visited);
                if (it != adj[edge.start].end() && it->weight < minEdge->weight)
                    minEdge = it;

                it = findMinWeight(adj[edge.end], visited);
                if (it != adj[edge.end].end() && it->weight < minEdge->weight)
                    minEdge = it;
            }

            mst.push_back(*minEdge);
            visited[minEdge->start] = visited[minEdge->end] = true;
        }
    }

    for (WeightedEdge &edge : mst) {
        ++edge.start;
        ++edge.end;
    }

    return mst;
}

vector<WeightedEdge> minimumSpanningTree(const vector<WeightedEdge> & edges, int vertices, bool directed) {
    vector<list<WeightedEdge> > adj;
    vector<bool> visited(vertices, false);

    if (directed)
        adj = DirectedGraph::adjacencyList(edges, vertices);
    else
        adj = UndirectedGraph::adjacencyList(edges, vertices);

    return Prim(adj, visited);
}
