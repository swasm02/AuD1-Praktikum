#ifndef __UNIONFIND_H_INCLUDED__
#define __UNIONFIND_H_INCLUDED__

#include <iostream>
#include <vector>


struct UF {
    std::vector<uint32_t> p;
    std::vector<uint32_t> rank;
    UF(uint32_t n = 0) {
        init(n);
    }
    // set size of vectors to n
    // initialize p[i] = i and rank[i] = 0
    void init(uint32_t n) {
        p.resize(n);
        rank.resize(n);
        for (uint32_t i = 0; i < n; ++i) {
            p[i] = i;
            rank[i] = 0;
        }
    }

    void unionByRank(uint32_t s, uint32_t t) {
        // if rank from s is greater than rank from t then s is the parent of t
        if (rank[s] > rank[t]) {
            p[t] = s;
        } else if (rank[s] < rank[t]) {
        // if rank from t is greater than rank from s then t is the parent of s
            p[s] = t;
        } else {
        // if rank from s is equal to the rank from t then s is the parent of t 
        // and rank from s is incremented
            p[t] = s;
            ++rank[s];
        }
    }

    uint32_t findWithCompression(uint32_t i) {
        uint32_t j = i; // verfolge Vorgängerzeiger bis zur Wurzel r(i)
        uint32_t jj = p[j];

        // search root
        while (jj != j) {
            j = jj;
            jj = p[j];
        }

        uint32_t root = j; // root found
        
        // erneuter Lauf zur Wurzel, Vorgängerzeiger umhängen
        j = i;
        jj = p[j];
        while (jj != j) {
            p[j] = root;
            j = jj;
            jj = p[j];
        }

        return root;
    }
};

template<typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v) {
    out << "(";
    if (!v.empty()) {
        out << v[0];
        for (uint32_t i = 1; i < v.size(); ++i) {
            out << "," << v[i];
        }
    }
    return out << ")";
}

std::ostream& operator<<(std::ostream& out, const UF& uf) {
    return out << uf.p << " " << uf.rank;
}


#endif // __UNIONFIND_H_INCLUDED__