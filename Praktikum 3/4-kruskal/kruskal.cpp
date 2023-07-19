#include "unionfind.h"
#include "edge.h"
#include <algorithm>

std::vector<Edge> kruskal(uint32_t n, std::vector<Edge> edges) {
    std::vector<Edge> R;
    // first step: sort edges by weight (ascending)
    std::sort(edges.begin(), edges.end());

    // second step: initialize UnionFind structure for n elements
    UF unionfind(n);

    // third step: iterate over edges
    int s; int t; // source and target
    for (Edge e : edges) {
    // check if source and target are in the same set
        s = unionfind.findWithCompression(e.first);
        t = unionfind.findWithCompression(e.second);
    // if not, add edge to R and union sets
        if (s != t) {
            R.push_back(e);
            unionfind.unionByRank(s, t);
        }
    }
    // fourth step: return R
    return R;
}

// helper function to compute total weight of a vector of edges
uint32_t totalWeight(std::vector<Edge> edges) {
    uint32_t sum = 0;
    for (Edge e : edges) {
        sum += e.weight;
    }
    return sum;
}

int main() {
    uint32_t n, m;
    while (std::cin >> n >> m) {
        std::vector<Edge> edges(m);
        for (uint32_t i = 0; i < m; ++i) {
            std::cin >> edges[i];
        }
        std::vector<Edge> R = kruskal(n, edges);
        std::cout << totalWeight(R) << ": " << R << std::endl;
    }
}