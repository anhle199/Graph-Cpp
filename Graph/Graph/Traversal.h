//
//  Traversal.h
//  Graph
//
//  Created by Le Hoang Anh on 17/12/2020.
//

#ifndef TRAVERSAL_H_
#define TRAVERSAL_H_

#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

enum TypeTraversal { DEPTH_FIRST_SEARCH, BREADTH_FIRST_SEARCH };

void DFS(const vector<vector<bool> > &adj, vector<bool> &visited, int v);
void DFS(const vector<list<int> > &adj, vector<bool> &visited, int v);
void BFS(const vector<vector<bool> > &adj, vector<bool> &visited, int v);
void BFS(const vector<list<int> > &adj, vector<bool> &visited, int v);
void traversalEntireGraph(const vector<vector<bool> > &adj, TypeTraversal type);
void traversalEntireGraph(const vector<list<int> > &adj, TypeTraversal type);


#endif
