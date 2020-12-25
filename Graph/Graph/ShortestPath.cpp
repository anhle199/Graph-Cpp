//
//  ShortestPath.cpp
//  Graph
//
//  Created by Le Hoang Anh on 18/12/2020.
//

#include "ShortestPath.h"

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

int findMin(const vector<Label> &labels, const vector<bool> &visited) {
    int minWeight = INT_MAX;
    int pos = -1;

    for (int i = 0; i < labels.size(); i++)
    if (minWeight > labels[i].weight && !visited[i]) {
        minWeight = labels[i].weight;
        pos = i;
    }

    return pos;
}

int findWeight(const list<WeightedEdge> &edges, int v) {
    int weight = 0;

    for (const WeightedEdge &edge : edges)
        if (edge.end == v) {
            weight = edge.weight;
            break;
        }

    return weight;
}

vector<WeightedEdge> Dijkstra(const vector<list<WeightedEdge> > &adj, int v) {
    size_t countVertices = adj.size();
    vector<WeightedEdge> result;

    if (countVertices > 0) {
        vector<Label> labels(countVertices);
        vector<bool> visited(countVertices, false);
        vector<vector<Label> > table(countVertices, vector<Label>(countVertices));
        int u = v - 1;

        table[0][u].weight = 0;
        visited[u] = true;
        for (int i = 1; i < countVertices; i++) {
            table[i] = table[i - 1];

            for (auto it = adj[u].begin(); it != adj[u].end(); it++) {
                int x = (u == it->start) ? it->end : it->start;

                if (!visited[x] && (table[i][u].weight + it->weight < table[i][x].weight)) {
                    table[i][x].weight = table[i][u].weight + it->weight;
                    table[i][x].parent = u;
                }
            }

            int pos = findMin(table[i], visited);
            if (pos == -1)
                break;

            labels[pos] = table[i][pos];
            visited[pos] = true;
            u = pos;
        }

        Label none = Label();
        for (int i = 0; i < labels.size(); i++) {
            if (i == v - 1 || labels[i] == none)
                continue;

            WeightedEdge edge;
            edge.start = labels[i].parent + 1;
            edge.end = i + 1;
            edge.weight = findWeight(adj[edge.start], edge.end);

            result.push_back(edge);
        }
    }

    return result;
}

bool isStable(const vector<vector<Label> > &table, const vector<bool> &visited) {
    size_t last = table.size() - 1;
    Label none = Label();

    for (int i = 0; i < table[last].size(); i++)
        if ((!visited[i] && table[last][i] != none) || (table[last][i] != table[last - 1][i]))
            return false;

    return true;
}

vector<WeightedEdge> FordBellman(const vector<list<WeightedEdge> > &adj, int v) {
    size_t countVertices = adj.size();
    vector<WeightedEdge> result;

    if (countVertices > 0) {
        vector<bool> visited(countVertices, false);
        vector<vector<Label> > table;
        int u = v - 1;

        table.push_back(vector<Label>(countVertices));
        table[0][u].weight = 0;
        visited[u] = true;
        for (int i = 1; i < countVertices; i++) {
            table.push_back(table[i - 1]);

            for (auto it = adj[u].begin(); it != adj[u].end(); it++) {
                int x = (u == it->start) ? it->end : it->start;

                if (!visited[x] && (table[i][u].weight + it->weight < table[i][x].weight)) {
                    table[i][x].weight = table[i][u].weight + it->weight;
                    table[i][x].parent = u;
                }
            }

            if (isStable(table, visited))
                break;

            int pos = findMin(table[i], visited);
            if (pos == -1)
                break;

            visited[pos] = true;
            u = pos;
        }

        vector<Label> labels = table.back();
        Label none = Label();
        for (int i = 0; i < labels.size(); i++) {
            if (i == v - 1 || labels[i] == none)
                continue;

            WeightedEdge edge;
            edge.start = labels[i].parent + 1;
            edge.end = i + 1;
            edge.weight = findWeight(adj[edge.start], edge.end);

            result.push_back(edge);
        }
    }

    return result;
}

vector<WeightedEdge> shortestPath(const vector<WeightedEdge> &edges, int countVertices, bool directed, int v,
                                  Algorithms algorithmName) {

    vector<list<WeightedEdge> > adj;
    vector<WeightedEdge> path;

    if (directed == DIRECTED)
        adj = DirectedGraph::adjacencyList(edges, countVertices);
    else
        adj = UndirectedGraph::adjacencyList(edges, countVertices);

    if (algorithmName == DIJKSTRA)
        path = Dijkstra(adj, v);
    else if (algorithmName == FORD_BELLMAN)
        path = FordBellman(adj, v);

    return path;
}
