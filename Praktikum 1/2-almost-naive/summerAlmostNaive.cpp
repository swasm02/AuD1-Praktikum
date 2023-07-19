#include "result.h"
#include <vector>

// nur lesender Zugriff
Result summerAlmostNaive(const std::vector<int>& A) {
    // Umbennung des Endwertes, um eine leichtere Verknüpfung zu Folie 1.8 zu haben. 
    // Deklaration von maxpair mit Standardwertes von Aufgabenblatt.
    Result maxpair = {0, 0, -1};
    int s;

    for (int i = 0; i < A.size(); i++) {
        s = 0;
        for (int j = i; j < A.size(); j++) {
            // Neuberechnung von s mit Zugriff auf Stelle j im "Array" (Vector) A
            s += A.at(j);

            // Aktualisieren von maxpair, wenn (bessere) Sommerperiode gefunden
            if (s > maxpair.sum) maxpair = {s, i, j};
        }
    }    

    return maxpair;
}

int main() {
    int size;
    while(std::cin >> size) {
        std::vector<int> v(size);
        for(int& x : v) std::cin >> x;
        std::cout << summerAlmostNaive(v) << std::endl;
    }
}