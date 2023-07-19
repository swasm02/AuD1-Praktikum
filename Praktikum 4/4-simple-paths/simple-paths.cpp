#include "dfs.h"

/********************************************************
* Definition/Implementierung der Erweiterungsfunktionen
********************************************************/

/* zusätzliche Variablen und Datenstrukturen */
/* TODO */
std::vector<std::int64_t> count;                    // Vector for counting the number of paths

/* Aktionen direkt vor DFS() */
void preDFS() {
    /* TODO */
    count.resize(n);                                // resize Vector to number of nodes
}

/* Präorder-Aktionen an Knoten v bei Entdeckung */
void dfsVisit(const int v) {
    /* TODO */
}

/* Postorder-Aktionen an Knoten v bei Abschluss */
void finVisit(const int v) {
    /* TODO */
    // initialize count.at(v) with 0
    count.at(v) = 0;

    // if v is n - 1 -> count.at(v) = 1
    if (v == (n - 1)) {
        count.at(v) = 1;
    }  
    // else calculate count.at(v) by adding the count.at(i) of all nodes i that have an edge to v
    for (int i : G.at(v)) {
        count.at(v) += count.at(i);
    }

}

/* Aktionen direkt nach DFS() */
void postDFS() {
    /* TODO */
    if (B.empty()) { // if B is empty, there is a path from 0 to n-1, else there is a cycle
        // print the number of paths from 0 to n-1 to be found in count.at(0)
        std::cout << count.at(0) << std::endl;
    }
    else std::cout << "-" << std::endl;
}