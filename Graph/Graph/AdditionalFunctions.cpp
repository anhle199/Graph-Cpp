//
//  AdditionalFunctions.cpp
//  Graph
//
//  Created by Le Hoang Anh on 19/12/2020.
//

#include "AdditionalFunctions.h"

void printGraph(const vector<vector<int> > &edges) {
    if (!edges.empty()) {
        for (int i = 0; i < edges.size() - 1; i++)
            cout << "{" << edges[i][0] << ", " << edges[i][1] << "}, ";

        size_t lastIndex = edges.size() - 1;
        cout << "{" << edges[lastIndex][0] << ", " << edges[lastIndex][1] << "} ";
    }
}

vector<vector<bool> > adjacencyMatrix(const vector<vector<int> > &edges, int countVertices) {
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

vector<list<int> > adjacencyList(const vector<vector<int> > &edges, int countVertices) {
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
