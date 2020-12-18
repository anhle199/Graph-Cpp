//
//  main.cpp
//  Graph
//
//  Created by Le Hoang Anh on 17/12/2020.
//

#include "Traversal.h"
#include "SpanningTrees.h"
#include "ShortestPath.h"
#include "TopologicalSorting.h"

int main() {
//    vector<vector<int> > edges = {
//        {1, 2}, {1, 9},
//        {2, 3}, {2, 5}, {2, 9}, {2, 10},
//        {3, 4}, {3, 5}, {3, 6}, {3, 11},
//        {4, 6}, {4, 7}, {4, 12},
//        {5, 10}, {5, 11},
//        {6, 11}, {6, 12},
//        {7, 8}, {7, 12},
//        {9, 10},
//        {10, 11},
//        {11, 12}
//    };
//    int vertices = 12;

    vector<vector<int> > edges = {
        {1, 2}, {1, 8},
        {2, 3}, {2, 4}, {2, 8}, {2, 10},
        {3, 4},
        {4, 5}, {4, 6}, {4, 11},
        {5, 6},
        {6, 7}, {6, 8}, {6, 12},
        {7, 8},
        {8, 9},
        {9, 10}, {9, 12},
        {10, 11},
        {11, 12}
    };
    int vertices = 12;

    cout << "The number of vertices: " << vertices << endl;
    cout << "The number of edges: " << edges.size() << endl;
    cout << "Graph: ";
    printGraph(edges);
    cout << endl;

//    vector<vector<bool> > adjMatrix = adjacencyMatrix(edges, 12);
//    vector<list<int> > adjList = adjacencyList(edges, 12);

//    cout << "DFS: ";
//    traversalEntireGraph(adjMatrix, DEPTH_FIRST_SEARCH);
//    cout << endl;
//
//    cout << "DFS: ";
//    traversalEntireGraph(adjList, DEPTH_FIRST_SEARCH);
//    cout << endl;

//    cout << "BFS: ";
//    traversalEntireGraph(adjMatrix, BREADTH_FIRST_SEARCH);
//    cout << endl;
//
//    cout << "BFS: ";
//    traversalEntireGraph(adjList, BREADTH_FIRST_SEARCH);
//    cout << endl;

    vector<vector<int> > tree = spanningTree(edges, vertices);
    cout << "\nSpanning tree: ";
    printGraph(tree);
    cout << endl;

    return 0;
}
