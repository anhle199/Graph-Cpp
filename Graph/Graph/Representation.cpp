//
//  Representation.cpp
//  Graph
//
//  Created by Le Hoang Anh on 22/12/2020.
//

#include "Representation.h"

vector<vector<bool> > DirectedGraph::adjacencyMatrix(const vector<vector<int> > &edges, int countVertices) {
    vector<vector<bool> > adj;

    if (countVertices > 0) {
        adj.resize(countVertices, vector<bool>(countVertices, false));

        for (int i = 0; i < edges.size(); i++)
            adj[edges[i][0] - 1][edges[i][1] - 1] = true;
    }

    return adj;
}

vector<list<int> > DirectedGraph::adjacencyList(const vector<vector<int> > &edges, int countVertices) {
    vector<list<int> > adj;

    if (countVertices > 0) {
        adj.resize(countVertices);

        for (int i = 0; i < edges.size(); i++)
            adj[edges[i][0] - 1].push_back(edges[i][1] - 1);
    }

    return adj;
}

vector<list<WeightedEdge>> DirectedGraph::adjacencyList(const vector<WeightedEdge> &edges, int countVertices) {
    vector<list<WeightedEdge> > adj;

    if (countVertices > 0) {
        adj.resize(countVertices);

        for (WeightedEdge edge : edges) {
            --edge.start;
            --edge.end;
            adj[edge.start].push_back(edge);
        }
    }

    return adj;
}

// MARK: - Test
vector<vector<int> > DirectedGraph::adjacencyWeightedMatrix(const vector<WeightedEdge> &edges, int countVertices) {
    vector<vector<int> > adj;

    if (countVertices > 0) {
        adj.resize(countVertices, vector<int>(countVertices, INFINITY_LENGTH));

        for (const WeightedEdge &edge : edges)
            adj[edge.start - 1][edge.end - 1] = edge.weight;
    }

    return adj;
}
//

vector<vector<bool> > UndirectedGraph::adjacencyMatrix(const vector<vector<int> > &edges, int countVertices) {
    vector<vector<bool> > adj;

    if (countVertices > 0) {
        adj.resize(countVertices, vector<bool>(countVertices, false));

        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0] - 1][edges[i][1] - 1] = true;
            adj[edges[i][1] - 1][edges[i][0] - 1] = true;
        }
    }

    return adj;
}

vector<list<int> > UndirectedGraph::adjacencyList(const vector<vector<int> > &edges, int countVertices) {
    vector<list<int> > adj;

    if (countVertices > 0) {
        adj.resize(countVertices);

        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0] - 1].push_back(edges[i][1] - 1);
            adj[edges[i][1] - 1].push_back(edges[i][0] - 1);
        }
    }

    return adj;
}

vector<list<WeightedEdge>> UndirectedGraph::adjacencyList(const vector<WeightedEdge> &edges, int countVertices) {
    vector<list<WeightedEdge> > adj;

    if (countVertices > 0) {
        adj.resize(countVertices);

        for (WeightedEdge edge : edges) {
            --edge.start;
            --edge.end;

            adj[edge.start].push_back(edge);
            swap(edge.start, edge.end);
            adj[edge.start].push_back(edge);
        }
    }

    return adj;
}

// MARK: - Test
vector<vector<int> > UndirectedGraph::adjacencyWeightedMatrix(const vector<WeightedEdge> &edges, int countVertices) {
    vector<vector<int> > adj;

    if (countVertices > 0) {
        adj.resize(countVertices, vector<int>(countVertices, INFINITY_LENGTH));

        for (const WeightedEdge &edge : edges) {
            adj[edge.start - 1][edge.end - 1] = edge.weight;
            adj[edge.end - 1][edge.start - 1] = edge.weight;
        }
    }

    return adj;
}
//
