#include <iostream>
#include "prim.h"

void printprim(int parent[], int graph[MAX_NODES][MAX_NODES], int numNodes) {
     cout << "Мінімальне дерево:" <<  endl;
    int sum = 0;
    for (int i = 1; i < numNodes; i++) {
         cout << parent[i] + 1 << " - " << i + 1 << " : " << graph[i][parent[i]] <<  endl;
        sum += graph[i][parent[i]];
    }
     cout << "\nДовжина:" << sum;
}
int minim(int key[], bool visited[], int numNodes) {
    int min = INF, min_index = -1;
    for (int v = 0; v < numNodes; v++)
        if (visited[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}
void prim(int graph[MAX_NODES][MAX_NODES], int numNodes) {
    for (int i = 0; i < numNodes; i++)
        key[i] = { INF }, visited[i] = { false };

    key[0] = 0;
    parent[0] = -1;
    int u = 0;
    for (int count = 0; count < numNodes - 1; count++) {
        u = minim(key, visited, numNodes);
        visited[u] = true;
        for (int v = 0; v < numNodes; v++)
            if (graph[u][v] && visited[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printprim(parent, graph, numNodes);
}
