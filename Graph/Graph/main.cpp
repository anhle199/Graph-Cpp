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
//    int countVertices = 12;

//    vector<vector<int> > edges = {
//        {1, 2}, {1, 8},
//        {2, 3}, {2, 4}, {2, 8}, {2, 10},
//        {3, 4},
//        {4, 5}, {4, 6}, {4, 11},
//        {5, 6},
//        {6, 7}, {6, 8}, {6, 12},
//        {7, 8},
//        {8, 9},
//        {9, 10}, {9, 12},
//        {10, 11},
//        {11, 12}
//    };
//    int countVertices = 12;
//
//    cout << "The number of countVertices: " << countVertices << endl;
//    cout << "The number of edges: " << edges.size() << endl;
//    cout << "The set of edges: ";
//    printGraph(edges);
//    cout << endl;

//    vector<vector<bool> > adjMatrix = UndirectedGraph::adjacencyMatrix(edges, 12);
//    vector<list<int> > adjList = UndirectedGraph::adjacencyList(edges, 12);

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

//    vector<vector<int> > tree = spanningTree(edges, countVertices);
//    cout << "\nSpanning tree: ";
//    printGraph(tree);
//    cout << endl;

//    vector<WeightedEdge> edges = {
//        {1, 2, 15}, {1, 5, 9}, {1, 6, 12},
//        {2, 3, 8}, {2, 4, 7}, {2, 5, 6},
//        {3, 4, 8}, {3, 7, 11},
//        {4, 5, 16}, {4, 7, 9},
//        {5, 6, 2}, {5, 7, 14},
//        {6, 7, 13}
//    };
//    int countVertices = 7;

//    vector<WeightedEdge> mst = minimumSpanningTree(edges, countVertices, UNDIRECTED, PRIM);
//    printGraph(mst);

//    vector<WeightedEdge> mst = minimumSpanningTree(edges, countVertices, UNDIRECTED, KRUSKAL);
//    printGraph(mst);

//    vector<WeightedEdge> edges = {
//        {1, 2, 4}, {1, 3, 3},
//        {2, 3, 2}, {2, 4, 5},
//        {3, 4, 3}, {3, 5, 6},
//        {4, 5, 1}, {4, 6, 5},
//        {5, 7, 5},
//        {6, 7, 2}, {6, 8, 7},
//        {7, 8, 4}
//    };
//    int countVertices = 8;

    vector<WeightedEdge> edges = {
        {'a', 'b', 2}, {'a', 'c', 4}, {'a', 'd', 1},
        {'b', 'c', 3}, {'b', 'e', 1},
        {'c', 'e', 2}, {'c', 'f', 2},
        {'d', 'f', 5}, {'d', 'g', 4},
        {'e', 'h', 3},
        {'f', 'g', 3}, {'f', 'h', 3}, {'f', 'i', 2}, {'f', 'j', 4},
        {'g', 'k', 2},
        {'h', 'l', 1}, {'h', 'o', 8},
        {'i', 'j', 3}, {'i', 'l', 3}, {'i', 'm', 2},
        {'j', 'k', 6}, {'j', 'm', 6}, {'j', 'n', 3},
        {'k', 'n', 4}, {'k', 'r', 2},
        {'l', 'm', 3}, {'l', 'o', 6},
        {'m', 'n', 5}, {'m', 'o', 4}, {'m', 'p', 2},
        {'n', 'q', 2}, {'n', 'r', 1},
        {'o', 'p', 2}, {'o', 's', 6},
        {'p', 'q', 1}, {'p', 's', 2}, {'p', 't', 1},
        {'q', 'r', 8}, {'q', 't', 3},
        {'r', 't', 5},
        {'s', 'z', 2},
        {'t', 'z', 8}
    };
    int countVertices = 21;
    // 42 edges.

    for (int i = 0; i < edges.size(); i++) {
        if (edges[i].end == 'z')
            edges[i].end -= 5;

        edges[i].start -= 'a' - 1;
        edges[i].end -= 'a' - 1;
    }

    vector<WeightedEdge> path = shortestPath(edges, countVertices, UNDIRECTED, 1, DIJKSTRA); // 1 is 'a'
    for (int i = 0; i < path.size(); i++) {
        path[i].start += 'a' - 1;
        path[i].end += 'a' - 1;

        if (path[i].start == 'u')
            path[i].start += 5;
        else if (path[i].end == 'u')
            path[i].end += 5;
    }
    cout << "E = {";
    for (int i = 0; i < path.size() - 1; i++) {
        cout << (char)path[i].start << (char)path[i].end << ", ";
    }
    cout << (char)path[path.size() - 1].start << (char)path[path.size() - 1].end << "}" << endl;


    path = shortestPath(edges, countVertices, UNDIRECTED, 1, FORD_BELLMAN);
    for (int i = 0; i < path.size(); i++) {
        path[i].start += 'a' - 1;
        path[i].end += 'a' - 1;

        if (path[i].start == 'u')
            path[i].start += 5;
        else if (path[i].end == 'u')
            path[i].end += 5;
    }
    cout << "E = {";
    for (int i = 0; i < path.size() - 1; i++) {
        cout << (char)path[i].start << (char)path[i].end << ", ";
    }
    cout << (char)path[path.size() - 1].start << (char)path[path.size() - 1].end << "}" << endl;

    return 0;
}
