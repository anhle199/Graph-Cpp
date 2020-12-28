//
//  ShortestPath.h
//  Graph
//
//  Created by Le Hoang Anh on 18/12/2020.
//

#ifndef SHORTEST_PATH_H_
#define SHORTEST_PATH_H_

#include "Representation.h"

struct Label {
    int parent;
    int weight;

    Label();
};

bool operator!= (const Label &l1, const Label &l2);
bool operator== (const Label &l1, const Label &l2);

//vector<WeightedEdge> Dijkstra(const vector<list<WeightedEdge> > &adj, int v);
vector<WeightedEdge> Dijkstra(const vector<vector<int> > &adj, int v);
vector<WeightedEdge> FordBellman(const vector<list<WeightedEdge> > &adj, int v);

vector<WeightedEdge> shortestPath(const vector<WeightedEdge> &edges, int countVertices, bool directed, int v,
                                  Algorithms algorithmName);

#endif
