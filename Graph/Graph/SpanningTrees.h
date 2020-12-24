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

enum AlgorithmFindMST {PRIM, KRUSKAL};

vector<vector<int> > spanningTree(const vector<vector<int> > edges, int countVertices, bool directed);

vector<WeightedEdge> Prim(const vector<list<WeightedEdge> > &adj);
vector<WeightedEdge> Kruskal(vector<WeightedEdge> edges, int countVertices);
vector<WeightedEdge> minimumSpanningTree(const vector<WeightedEdge> & edges, int countVertices, bool directed,
                                         AlgorithmFindMST algorithmName);

#endif
