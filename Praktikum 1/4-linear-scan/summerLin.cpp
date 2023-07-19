#include "result.h"
#include <vector>

Result summerLin(const std::vector<int>& A) {
    // Deklaration der nötigen Variablen: 
    // Standardbelegung als 0 bzw. -1 zum Abfangen der Basisfälle
    Result zwischenwert = {0, 0, -1};
    Result end = {0, 0 , -1};

    for (int l = 0; l < A.size(); l++) {
        if (A.at(l) > zwischenwert.sum + A.at(l)) {
            zwischenwert.i = l;
            zwischenwert.sum = A.at(l);
        } else {
            zwischenwert.sum += A.at(l);
        }

        zwischenwert = {zwischenwert.sum, zwischenwert.i, l};

        if (end < zwischenwert) {
            end = zwischenwert;
        }
    }

    return end;
}

int main() {
    int size;
    while(std::cin >> size) {
        std::vector<int> v(size);
        for(int& x : v) std::cin >> x;
        std::cout << summerLin(v) << std::endl;
    }
}