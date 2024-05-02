#include <iostream>
#include <Windows.h>
#include "kruskal.h"
#include "prim.h"
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int vybir = 0;
    int numNodes = 0, numEdges = 0;
    int totalWeight = 0;
    Edge* edges = nullptr;
    int graph[MAX_NODES][MAX_NODES] = { 0 };

     cout << "1-Краскала. 2-Прима: ";
     cin >> vybir;

    switch (vybir) {
    case 1:
         cout << "Введіть кількість вершин та зв'язків: ";
         cin >> numNodes >> numEdges;
        edges = new Edge[numEdges];

         cout << "Введіть початкову вершину, кінцеву вершину, довжину зв'язку:" <<  endl;
        for (int i = 0; i < numEdges; i++) {
             cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
        }

        totalWeight = kruskal(edges, numNodes, numEdges);
         cout << "\nЗагальна відстань: " << totalWeight;
        delete[] edges;
        break;

    case 2:
         cout << "Введіть кількість вершин: ";
         cin >> numNodes;

         cout << "Введіть матрицю суміжності:" <<  endl;
        for (int i = 0; i < numNodes; i++)
            for (int j = 0; j < numNodes; j++)
                 cin >> graph[i][j];

        prim(graph, numNodes);
        break;

    default:
        break;
    }

    return 0;
}
