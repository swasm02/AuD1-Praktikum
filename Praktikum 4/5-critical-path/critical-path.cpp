#include "dfs.h"

/********************************************************
* Definition/Implementierung der Erweiterungsfunktionen
********************************************************/

/* zusätzliche Variablen und Datenstrukturen */
/* TODO */
std::vector<int> path;              // path of max. length
std::vector<int> max_length_nodes;  // length of max. path from each node
int64_t max;                        // max. length of path
int64_t start_max_node;             // start node of max. path

/* Aktionen direkt vor DFS() */
void preDFS() {
    /* TODO */
    max = 0;
    start_max_node = -1;
    path.resize(n);
    max_length_nodes.resize(n);
}

/* Präorder-Aktionen an Knoten v bei Entdeckung */
void dfsVisit(const int v) {
    /* TODO */
}

/* Postorder-Aktionen an Knoten v bei Abschluss */
void finVisit(const int v) {
    /* TODO */
    int64_t max_length = 0;
    for (int i : G.at(v)) {
        if (max_length_nodes.at(i) > max_length) {
            max_length = max_length_nodes.at(i);
            path.at(v) = i;
        }
    }
    max_length_nodes.at(v) = max_length + 1;

    if (max_length_nodes.at(v) > max) {
        max = max_length_nodes.at(v);
        start_max_node = v;
    }


}

/* Aktionen direkt nach DFS() */
void postDFS() {
    /* TODO */
    if (B.empty()) {
        std::cout << max << ":";
        int v = start_max_node;
        for (int i = 0; i < max; ++i) {
            std::cout << " " << v;
            v = path.at(v);
        }
        std::cout << std::endl;
    }
    else std::cout << "-" << std::endl;
}
