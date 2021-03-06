//
//  ShortestPath.cpp
//  Graph
//
//  Created by Le Hoang Anh on 18/12/2020.
//

#include "ShortestPath.h"
#include "AdditionalFunctions.h"
#include <queue>

Label::Label() {
    parent = -1;
    weight = INT_MAX;
}

bool operator!= (const Label &l1, const Label &l2) {
    return l1.weight != l2.weight || l1.parent != l2.parent;
}

bool operator== (const Label &l1, const Label &l2) {
    return l1.weight == l2.weight && l1.parent == l2.parent;
}

//int findMinWeightInTable(const vector<Label> &labels, const vector<bool> &visited) {
//    int minWeight = INT_MAX;
//    int pos = -1;
//
//    for (int i = 0; i < labels.size(); i++)
//    if (minWeight > labels[i].weight && !visited[i]) {
//        minWeight = labels[i].weight;
//        pos = i;
//    }
//
//    return pos;
//}

int findWeight(const list<WeightedEdge> &edges, int v) {
    int weight = 0;

    for (const WeightedEdge &edge : edges)
        if (edge.end == v) {
            weight = edge.weight;
            break;
        }

    return weight;
}

//vector<WeightedEdge> Dijkstra(const vector<list<WeightedEdge> > &adj, int v) {
//    size_t countVertices = adj.size();
//    vector<WeightedEdge> result;
//
//    if (countVertices > 0) {
//        vector<Label> labels(countVertices);
//        vector<bool> visited(countVertices, false);
//        vector<vector<Label> > table(countVertices, vector<Label>(countVertices));
//        int u = v - 1;
//
//        table[0][u].weight = 0;
//        visited[u] = true;
//        for (int i = 1; i < countVertices; i++) {
//            table[i] = table[i - 1];
//
//            for (auto it = adj[u].begin(); it != adj[u].end(); it++) {
//                int x = it->end;
//                if (!visited[x] && (table[i - 1][u].weight + it->weight < table[i][x].weight)) {
//                    table[i][x].weight = table[i - 1][u].weight + it->weight;
//                    table[i][x].parent = u;
//                }
//            }
//
//            int pos = findMinWeightInTable(table[i], visited);
//            if (pos == -1)
//                break;
//
//            labels[pos] = table[i][pos];
//            visited[pos] = true;
//            u = pos;
//        }
//
//        Label none = Label();
//        for (int i = 0; i < labels.size(); i++) {
//            if (i == v - 1 || labels[i] == none)
//                continue;
//
//            WeightedEdge edge;
//            edge.start = labels[i].parent + 1;
//            edge.end = i + 1;
//            edge.weight = findWeight(adj[labels[i].parent], i);
//
//            result.push_back(edge);
//        }
//    }
//
//    return result;
//}

vector<WeightedEdge> Dijkstra(const vector<vector<int> > &adj, int v) {
    size_t countVertices = adj.size();
    vector<int> length(countVertices);
    vector<int> parent(countVertices);
    vector<bool> visited(countVertices, false);

    --v;
    visited[v] = true;

    for (int u = 0; u < countVertices; u++) {
        length[u] = adj[v][u];
        parent[u] = v;
    }
    length[v] = 0;

    vector<WeightedEdge> path;

    for (int step = 1; step < countVertices; step++) {
        WeightedEdge edge = findEdgeHasSmallestWeight(length, parent, visited);

        path.push_back(edge);
        visited[edge.end] = true;

        // update height for each vertex adjacency to v (edge.end).
        for (int u = 0; u < countVertices; u++)
            if (!visited[u] && adj[edge.end][u] != INFINITY_LENGTH && length[u] > adj[edge.end][u] + length[edge.end]) {
                length[u] = adj[edge.end][u] + length[edge.end];
                parent[u] = edge.end;
            }
    }

    for (WeightedEdge &edge : path) {
        ++edge.start;
        ++edge.end;
    }

    return path;
}

vector<WeightedEdge> FordBellman(const vector<list<WeightedEdge> > &adj, int v) {
    size_t countVertices = adj.size();
    vector<WeightedEdge> result;

    if (countVertices > 0) {
        vector<vector<Label> > table(1, vector<Label>(countVertices));
        queue<int> q;

        q.push(v - 1);
        table[0][v - 1].weight = 0;
        for (int i = 1; i < countVertices; i++) {
            table.push_back(table[i - 1]);

            int count = (int)q.size();
            while (count > 0) {
                int u = q.front();
                q.pop();
                --count;

                for (auto it = adj[u].begin(); it != adj[u].end(); it++) {
                    int x = it->end;
                    if (it->start != it->end && table[i - 1][u].weight + it->weight < table[i][x].weight) {
                        table[i][x].weight = table[i - 1][u].weight + it->weight;
                        table[i][x].parent = u;
                        q.push(x);
                    }
                }
            }

            if (q.empty()) // stable.
                break;
        }

        vector<Label> labels = table.back();
        Label none = Label();

        for (int i = 0; i < labels.size(); i++) {
            if (i == v - 1 || none == labels[i])
                continue;

            WeightedEdge edge;
            edge.start = labels[i].parent + 1;
            edge.end = i + 1;
            edge.weight = findWeight(adj[labels[i].parent], i);

            result.push_back(edge);
        }
    }

    return result;
}

vector<WeightedEdge> shortestPath(const vector<WeightedEdge> &edges, int countVertices, bool directed, int v,
                                  Algorithms algorithmName) {

    vector<WeightedEdge> path;

    if (algorithmName == DIJKSTRA) {
        vector<vector<int>> adjWeightedMatrix;
        if (directed == DIRECTED)
            adjWeightedMatrix = DirectedGraph::adjacencyWeightedMatrix(edges, countVertices);
        else
            adjWeightedMatrix = UndirectedGraph::adjacencyWeightedMatrix(edges, countVertices);

        path = Dijkstra(adjWeightedMatrix, v);
    } else if (algorithmName == FORD_BELLMAN) {
        vector<list<WeightedEdge> > adj;
        if (directed == DIRECTED)
            adj = DirectedGraph::adjacencyList(edges, countVertices);
        else
            adj = UndirectedGraph::adjacencyList(edges, countVertices);

        path = FordBellman(adj, v);
    }

    return path;
}
