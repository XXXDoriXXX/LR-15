#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "Header.h"

void customSort(Edge edges[], int numEdges);
int findParent(int node);
void unionNodes(int a, int b);
int kruskal(Edge edges[], int numNodes, int numEdges);

#endif
