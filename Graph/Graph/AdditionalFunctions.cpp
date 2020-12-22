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

void printGraph(const vector<WeightedEdge> &edges) {
    if (!edges.empty())
        for (int i = 0; i < edges.size(); i++)
            cout << "(start: " << edges[i].start << ", end: " << edges[i].end << ", weight: " << edges[i].weight << ")" << endl;
}
