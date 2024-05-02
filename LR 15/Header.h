#ifndef HEADER_H
#define HEADER_H
#include <iostream>
using namespace std;

const int MAX_NODES = 100;
const int INF = 1e9;
extern bool visited[MAX_NODES];
extern int parent[MAX_NODES];
extern int key[MAX_NODES];

struct Edge {
    int src, dest, weight;
};

#endif