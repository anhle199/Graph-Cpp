//
//  Representation.h
//  Graph
//
//  Created by Le Hoang Anh on 22/12/2020.
//

#ifndef REPRESENTATION_GRAPH_H_
#define REPRESENTATION_GRAPH_H_

#include <vector>
#include <list>

using namespace std;

struct WeightedEdge {
    int start;
    int end;
    int weight;
};

class DirectedGraph {
private:
    DirectedGraph() {};

public:
    static vector<vector<bool> > adjacencyMatrix(const vector<vector<int> > &edges, int countVertices);
    static vector<list<int> > adjacencyList(const vector<vector<int> > &edges, int countVertices);
    static vector<list<WeightedEdge>> adjacencyList(const vector<WeightedEdge> &edges, int countVertices);
};

class UndirectedGraph {
private:
    UndirectedGraph() {};

public:
    static vector<vector<bool> > adjacencyMatrix(const vector<vector<int> > &edges, int countVertices);
    static vector<list<int> > adjacencyList(const vector<vector<int> > &edges, int countVertices);
    static vector<list<WeightedEdge>> adjacencyList(const vector<WeightedEdge> &edges, int countVertices);
};

#endif
