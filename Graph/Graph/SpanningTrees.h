//
//  SpanningTrees.h
//  Graph
//
//  Created by Le Hoang Anh on 18/12/2020.
//

#ifndef SPANNING_TREES_H_
#define SPANNING_TREES_H_

#include "AdditionalFunctions.h"
#include <stack>
#include <queue>

vector<vector<int> > spanningTree(const vector<vector<int> > edges, int vertices, bool directed);

vector<WeightedEdge> Prim(const vector<list<WeightedEdge> > &adj, vector<bool> &visited);
vector<WeightedEdge> Kruskal(const vector<list<WeightedEdge> > &adj, vector<bool> &visited);
vector<WeightedEdge> minimumSpanningTree(const vector<WeightedEdge> & edges, int vertices, bool directed);

#endif
