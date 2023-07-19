#include "result.h"
#include <algorithm>

using namespace std;

int main() {
    // Erstellen von Results first , second
    Result first;
    Result second;

    // Ablauf der Schleife, so lange bis es keine Eingabe mehr gibt
    // eigens definierte << und >> Operatoren
    while(cin >> first >> second) {
        // Ueberprüfen, welches "Result" größer ist (Operator in result.h eigens definiert.)
        // danach Ausgabe
        if (first < second) cout << second; 
        else cout << first;
    }
}