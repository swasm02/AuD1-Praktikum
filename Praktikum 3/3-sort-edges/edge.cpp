#include "edge.h"
#include <algorithm>

int main() {
    uint32_t m;
    while (std::cin >> m) {
        std::vector<Edge> edges(m);
        for (uint32_t i = 0; i < m; ++i) {
            std::cin >> edges[i];
        }
        std::sort(edges.begin(), edges.end());
        std::cout << edges << std::endl;
    }
}