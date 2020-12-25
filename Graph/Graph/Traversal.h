//
//  Traversal.h
//  Graph
//
//  Created by Le Hoang Anh on 17/12/2020.
//

#ifndef TRAVERSAL_H_
#define TRAVERSAL_H_

#include <stack>
#include <queue>
#include <iostream>
#include "Representation.h"

void DFS(const vector<vector<bool> > &adj, vector<bool> &visited, int v);
void DFS(const vector<list<int> > &adj, vector<bool> &visited, int v);
void BFS(const vector<vector<bool> > &adj, vector<bool> &visited, int v);
void BFS(const vector<list<int> > &adj, vector<bool> &visited, int v);
void traversalEntireGraph(const vector<vector<bool> > &adj, Algorithms algorithmName);
void traversalEntireGraph(const vector<list<int> > &adj, Algorithms algorithmName);


#endif
