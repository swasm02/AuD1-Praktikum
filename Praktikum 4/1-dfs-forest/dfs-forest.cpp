#include "dfs.h"

/********************************************************
* Definition/Implementierung der Erweiterungsfunktionen
********************************************************/

/* zusätzliche Variablen und Datenstrukturen */


/* Aktionen direkt vor DFS() */
void preDFS() {
}

/* Präorder-Aktionen an Knoten v bei Entdeckung */
void dfsVisit(const int v) {
    std::cout << v << "("; // neue Knotenausgabe beginnen
}

/* Postorder-Aktionen an Knoten v bei Abschluss */
void finVisit(const int v) {
    std::cout << ")"; // Knotenausgabe abschließen
}

/* Aktionen direkt nach DFS() */
void postDFS() { 
    // keine Aktionen, da nur bestimmte Ausgabe in Aufgabenstellung gefordert
}