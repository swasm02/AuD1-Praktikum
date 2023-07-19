#include <iostream>
#include <cassert>

int living = 0;
struct BST {
    BST* left;
    int key;
    BST* right;
    BST(BST* l, int k, BST* r) : left(l), key(k), right(r) {
        ++living;
    }
    ~BST() {
        delete left; delete right;
        --living;
    }
};

std::ostream& operator<<(std::ostream& out, const BST* T) {
    if (!T)
        return out << "-";
    else
        return out << "(" << T->left << "," << T->key << "," << T->right << ")";
}

bool lookup(const BST* T, const int key) {
    /*
     * Verwendung:
     * BST* T = new BST{nullptr,2,nullptr}; // T == (-,2,-)
     * bool b = lookup(T, 4); // T == (-,2,-), b == false
     */
    if (!T) return false;

    if (T->key == key) return true;
    if (T->key < key) return lookup(T->right, key);
    if (T->key > key) return lookup(T->left, key);

    return false;
}

BST* insert(BST* T, const int key) {
    /*
     * Verwendung:
     * BST* T = nullptr; // T == -
     * T = insert(T, 2);  // T == (-,2,-)
     * T = insert(T, 4);  // T == (-,2,(-,4,-))
     */
    if (T == nullptr) T = new BST{ nullptr, key, nullptr };
    if (T->left == nullptr && T->key > key) T->left = new BST{ nullptr, key, nullptr };
    if (T->right == nullptr && T->key < key) T->right = new BST{ nullptr, key, nullptr };

    if (T->key > key) insert(T->left, key);
    if (T->key < key) insert(T->right, key);

    return T;
}

BST* extractMin(BST* T, int& minKey) {
    /*
     * Verwendung:
     * BST* T = new BST{nullptr,2,new BST{nullptr,4,nullptr}}; // T == (-,2,(-,4,-))
     * int k; // k == undefiniert
     * T = extractMin(T, k); // T == (-,4,-), k == 2
     */
    if (T->left == nullptr) {
        // Schluessel in der Wurzel ist minimal -> linker Teilbaum nicht vorhanden
        // => Wurzel loeschen und rechten Teilbaum zurueckgeben
        minKey = T->key;
        BST* Ts = T->right;
        T->right = nullptr; delete T; 
        return Ts;
    } else {
        // Schluessel in der Wurzel ist noch nicht minimal
        T->left = extractMin(T->left, minKey);
        return T;
    }
}

BST* erase(BST* T, const int key) {
    /*
     * Verwendung:
     * BST* T = new BST{nullptr,2,new BST{nullptr,4,nullptr}}; // T == (-,2,(-,4,-))
     * T = erase(T, 4); // T == (-,2,-)
    */
    if (T == nullptr) return T;

    if (T->key == key) {
        if (T->left == nullptr) {
            // root hat kein linkes Kind -> rechtes Kind hochziehen
            // => rechten Teilbaum zurueckgeben
            BST* rightChild = T->right;
            T->right = nullptr; delete T;
            return rightChild;
        } else if (T->right == nullptr) {
            // root hat kein rechtes Kind -> linkes Kind hochziehen
            // => linken Teilbaum zurueckgeben
            BST* leftChild = T->left;
            T->left = nullptr; delete T; 
            return leftChild;
        } else {
            // root hat sowohl linkes als auch rechtes Kind :(
            // => kleinsten Schluessel im rechten Teilbaum suchen und in root speichern
            // => extractMin auf rechtem Teilbaum aufrufen
            // key von root wird durch minKey ersetzt
            int minKey;
            T->right = extractMin(T->right, minKey);
            T->key = minKey;
        }
    }
    // key nicht in root -> rekursiv in linkem oder rechtem Teilbaum suchen
    // wenn root->key > key, dann key im linken Teilbaum suchen
    // linker Teilbaum wird durch Rueckgabewert von erase ersetzt
    if (T->key > key) T->left = erase(T->left, key); 
    // wenn root->key < key, dann key im rechten Teilbaum suchen
    // rechter Teilbaum wird durch Rueckgabewert von erase ersetzt
    if (T->key < key) T->right = erase(T->right, key);
    
    return T;
}

int main() {
    char c; int key;
    BST* T = nullptr;
    int p = true;

    while(std::cin >> c >> key) {
        if (c == 'p') {
            // Wertzuweisung wenn p eingelesen wird
            if (key != 0) p = true; // nur 0, sorgt fuer fehlende Ausgabe
            else p = false;
        }
        // Ausgabe von insert, extractMin und erase nur wenn p == true
        // Ausgabe von lookup immer
        // Ausfuehrung der Funktionen immer
        switch (c) {
            case 'l': {
                std::cout << lookup(T, key) << std::endl; 
                break;
            }
            case 'i': {
                T = insert(T, key); 
                if (p) std::cout << T << std::endl; 
                break;
            }
            case 'e': {
                T = extractMin(T, key); 
                if (p) std::cout << key << " " << T << std::endl; 
                break;}
            case 'd': {
                T = erase(T, key); 
                if (p) std::cout << T << std::endl; 
                break;
            }
        }
    }
    delete T; T = nullptr;
    assert(!living);
}