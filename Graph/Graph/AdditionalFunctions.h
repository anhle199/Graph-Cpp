//
//  AdditionalFunctions.h
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

struct WeightedEdge {
    int start;
    int end;
    int weight;
};

void printGraph(const vector<vector<int> > &edges);

void printGraph(const vector<WeightedEdge> &edges);

vector<vector<bool> > adjacencyMatrix(const vector<vector<int> > &edges, int countVertices);

vector<list<int> > adjacencyList(const vector<vector<int> > &edges, int countVertices);

//vector<list<WeightedEdge>> adjacencyList(const vector<vector<int> > &edges, const vector<int> &weights, int countVertices);

vector<list<WeightedEdge>> adjacencyList(const vector<WeightedEdge> &edges, int countVertices);

#endif
