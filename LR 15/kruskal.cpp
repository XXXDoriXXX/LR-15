#include <iostream>
#include "kruskal.h"
bool visited[MAX_NODES];
int parent[MAX_NODES];
int key[MAX_NODES];
void customSort(Edge edges[], int numEdges) {
    for (int i = 0; i < numEdges - 1; i++) {
        for (int j = i + 1; j < numEdges; j++) {
            if (edges[i].weight > edges[j].weight) {
                Edge temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }
}

int findParent(int node) {
    if (parent[node] == node)
        return node;
    return parent[node] = findParent(parent[node]);
}

void unionNodes(int a, int b) {
    parent[findParent(a)] = findParent(b);
}

int kruskal(Edge edges[], int numNodes, int numEdges) {
    customSort(edges, numEdges);
    Edge* mst = new Edge[numNodes - 1];
    int mstEdges = 0;
    int totalWeight = 0;

    for (int i = 0; i < numNodes; i++)
        parent[i] = i;

    for (int i = 0; i < numEdges && mstEdges < numNodes - 1; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int uParent = findParent(u);
        int vParent = findParent(v);

        if (uParent != vParent) {
            mst[mstEdges++] = edges[i];
            unionNodes(u, v);
            totalWeight += edges[i].weight;
        }
    }

     cout << "Мінімальне дерево:" <<  endl;
    for (int i = 0; i < numNodes - 1; i++) {
         cout << mst[i].src << " -- " << mst[i].dest << " : " << mst[i].weight <<  endl;
    }

    delete[] mst;
    return totalWeight;
}
