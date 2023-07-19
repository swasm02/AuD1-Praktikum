#include "unionfind.h"

int main() {
    char c;
    uint32_t i, j;
    UF uf;
    while (std::cin >> c) {
        switch (c) {
        case 'i':
            std::cin >> i;
            uf.init(i);
            std::cout << uf << std::endl;
            break;
        case 'u':
            std::cin >> i >> j;
            uf.unionByRank(i, j);
            std::cout << uf << std::endl;
            break;
        default:
            break;
        }
    }
}