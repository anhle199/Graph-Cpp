//
//  AdditionalFunctionls.h
//  Graph
//
//  Created by Le Hoang Anh on 19/12/2020.
//

#ifndef ADDITIONAL_FUNCTIONS_H_
#define ADDITIONAL_FUNCTIONS_H_

#include <iostream>
#include <vector>
#include <list>

using namespace std;

void printGraph(const vector<vector<int> > &edges);

vector<vector<bool> > adjacencyMatrix(const vector<vector<int> > &edges, int countVertices);

vector<list<int> > adjacencyList(const vector<vector<int> > &edges, int countVertices);

#endif
