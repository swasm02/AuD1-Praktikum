/* This code implements a binary search tree. 
The struct BST has three fields: left, key and right. 
The field key holds the value stored in the node. 
The fields left and right hold pointers to the left and right subtree respectively. 
The operator << is overloaded to print the tree in the following format: (-,2,(-,4,-)). 
The operator << works recursively. If the pointer is a nullptr, it prints a dash. 
Otherwise it prints the left subtree, the key and the right subtree. 
The destructor deletes the left and right subtree.
*/
/* This code implements a binary search tree. 
The struct BST has three fields: left, key and right. 
The field key holds the value stored in the node. 
The fields left and right hold pointers to the left and right subtree respectively. 
The operator << is overloaded to print the tree in the following format: (-,2,(-,4,-)). 
The operator << works recursively. If the pointer is a nullptr, it prints a dash. 
Otherwise it prints the left subtree, the key and the right subtree. 
The destructor deletes the left and right subtree.
*/

#include <iostream>
#include <cassert>
#include <vector>

int living = 0;
struct BST {
    BST* left;
    int key;
    BST* right;
    BST(BST* left, int key, BST* right) : left(left), key(key), right(right) {
        ++living;
    }
    ~BST() {
        delete left; delete right;
        --living;
    }
};

std::ostream& operator<<(std::ostream& out, const BST* tree) {
    /*
#include <iostream>
#include <cassert>
#include <vector>

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
    /*
     * Verwendung:
     * BST* T = nullptr;
     * std::cout << T << std::endl; // -
     * T = new BST{nullptr,2,new BST{nullptr,4,nullptr}};
     * std::cout << T << std::endl; // (-,2,(-,4,-))
     */
    if (!T)
        return out << "-";
    else
        return out << "(" << T->left << "," << T->key << "," << T->right << ")";
}

int main() {
    std::vector<BST*> bsts = {
        nullptr,
        new BST{nullptr,13,nullptr},
        new BST{new BST{nullptr,7,nullptr},13,new BST{nullptr,23,nullptr}},
        new BST{new BST{new BST{nullptr,0,nullptr},7,nullptr},13,new BST{new BST{nullptr,21,nullptr},23,new BST{nullptr,42,new BST{nullptr,1337,nullptr}}}}
    };
    // Display the BSTs
    for(BST* t : bsts) {
        std::cout << t << std::endl;
        delete t;
    }
    // Assert that no BSTs are still alive
    assert(!living);
}