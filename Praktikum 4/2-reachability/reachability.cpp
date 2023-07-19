#include "dfs.h"
#include <vector>

/********************************************************
* Definition/Implementierung der Erweiterungsfunktionen
********************************************************/

/* zusätzliche Variablen und Datenstrukturen */
/* TODO */
std::vector<bool> reachable;
// Implementierung von Array reachable
// reachable.at(v) == true, wenn v von 0 aus erreichbar ist

// Methode addReachable, markiert alle Knoten, die von v aus erreichbar sind
// rekursive Implementierung
void addReachable(int v) {
    reachable.at(v) = true;
    for (int w : G.at(v)) {         // alle Nachbarn von v betrachten -> Adjazenzliste
        if (!reachable.at(w)) {     // nur Knoten betrachten, die noch nicht markiert sind -> sonst Endlosschleife
            addReachable(w);
        }
    }
} 

/* Aktionen direkt vor DFS() */
void preDFS() {
    /* TODO */
    reachable = std::vector<bool>(n, false); // Neuinitialisierung, alle Knoten sind standardmäßig nicht erreichbar
    addReachable(0); // trivialerweise ist 0 von 0 aus erreichbar
}

/* Präorder-Aktionen an Knoten v bei Entdeckung */
void dfsVisit(const int v) {
    /* TODO */
    if (v == 0) {
        std::cout << "0";
    }
    else if (reachable.at(v)) {
        std::cout << " " << v;
    }
}

/* Postorder-Aktionen an Knoten v bei Abschluss */
void finVisit(const int v) {
    /* TODO */
}

/* Aktionen direkt nach DFS() */
void postDFS() {
    /* TODO */
    std::cout << std::endl;
}