#include "dfs.h"
#include <algorithm>

/********************************************************
* Definition/Implementierung der Erweiterungsfunktionen
********************************************************/

/* zusätzliche Variablen und Datenstrukturen */
/* TODO */
std::vector<int> topologicalOrder; // Vector for topological order
int offset;

/* Aktionen direkt vor DFS() */
void preDFS() {
    /* TODO */
    offset = 0;
    topologicalOrder.resize(n); // resize Vector to number of nodes
}

/* Präorder-Aktionen an Knoten v bei Entdeckung */
void dfsVisit(const int v) {
    /* TODO */
}

/* Postorder-Aktionen an Knoten v bei Abschluss */
void finVisit(const int v) {
    /* TODO */
    topologicalOrder.at(n-1-offset) = v;    // fill Vector with fNumbers (descending order)
    ++offset;                               // increase offset -> next node
}

/* Aktionen direkt nach DFS() */
void postDFS() {
    /* TODO */
    // Output topological order (Vector topologicalOrder)
    if (B.empty()) {    // if B is not empty, there is a cycle
                        // and there is no topological order
        for (int i = 0; i < topologicalOrder.size(); ++i) {
            std::cout << topologicalOrder.at(i);
            if (i != topologicalOrder.size() - 1) std::cout << " ";  // print space between numbers, except for last number
        }
        std::cout << std::endl;
    }
    else std::cout << "-" << std::endl; // there is no topological order
}