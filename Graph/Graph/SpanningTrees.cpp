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

vector<vector<int> > spanningTree(const vector<vector<int> > edges, int countVertices, bool directed) {
    vector<vector<int> > tree;
    vector<bool> visited(countVertices, false);
    vector<list<int> > adj;

    if (directed)
        adj = DirectedGraph::adjacencyList(edges, countVertices);
    else
        adj = UndirectedGraph::adjacencyList(edges, countVertices);

    for (int i = 1; i < countVertices; i++)
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

vector<WeightedEdge> Prim(const vector<list<WeightedEdge> > &adj) {
    vector<WeightedEdge> mst;

    if (!adj.empty()) {
        vector<bool> visited(adj.size(), false);

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

        for (WeightedEdge &edge : mst) {
            ++edge.start;
            ++edge.end;
        }
    }

    return mst;
}

void quickSort(vector<WeightedEdge> &edges, int left, int right) {
    int i = left;
    int j = right;
    WeightedEdge pivot = edges[(left + right) / 2];

    do {
        while (edges[i].weight < pivot.weight) ++i;
        while (edges[j].weight > pivot.weight) --j;

        if (i <= j) {
            swap(edges[i], edges[j]);
            ++i;
            --j;
        }
    } while (i <= j);

    if (left < j)
        quickSort(edges, left, j);
    if (i < right)
        quickSort(edges, i, right);
}

vector<WeightedEdge> Kruskal(vector<WeightedEdge> edges, int countVertices) {
    vector<WeightedEdge> mst;

    if (!edges.empty() && countVertices > 0) {
        vector<bool> visited(countVertices, false);

        quickSort(edges, 0, (int)edges.size() - 1);
        for (const WeightedEdge &edge : edges) {
            if (mst.size() >= countVertices - 1)
                break;

            if (!visited[edge.start - 1] || !visited[edge.end - 1]) {
                visited[edge.start - 1] = visited[edge.end - 1] = true;
                mst.push_back(edge);
            }
        }
    }

    return mst;
}

vector<WeightedEdge> minimumSpanningTree(const vector<WeightedEdge> &edges, int countVertices, bool directed,
                                         Algorithms algorithmName) {
    if (algorithmName == KRUSKAL)
        return Kruskal(edges, countVertices);
    else if (algorithmName == PRIM) {
        vector<list<WeightedEdge> > adj;

        if (directed)
            adj = DirectedGraph::adjacencyList(edges, countVertices);
        else
            adj = UndirectedGraph::adjacencyList(edges, countVertices);

        return Prim(adj);
    }

    return vector<WeightedEdge>(); // ignore line.
}
