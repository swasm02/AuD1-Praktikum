#ifndef __EDGE_H_INCLUDED__
#define __EDGE_H_INCLUDED__

#include <iostream>
#include <vector>

struct Edge {
    uint32_t first;
    uint32_t second;
    uint32_t weight;
};

bool operator<(const Edge& e1, const Edge& e2) {
    // compare weights
    if (e1.weight < e2.weight)
        return true;
    // if weights are equal compare firsts
    else if (e1.weight == e2.weight) {
        if (e1.first < e2.first)
            return true;
    // if firsts are equal compare seconds
        else if (e1.first == e2.first) {
            if (e1.second < e2.second)
                return true;
        }
    }

    return false;
}

std::istream& operator>>(std::istream& in, Edge& e) {
    char _;
    in >> _ >> e.first >> _ >> e.second >> _ >> e.weight >> _;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Edge& e) {
    return out << '(' << e.first << ',' << e.second << ',' << e.weight << ')';
}

std::ostream& operator<<(std::ostream& out, const std::vector<Edge>& v) {
    if (v.size() > 0) {
        out << v[0];
        for (uint32_t i = 1; i < v.size(); ++i) {
            out << " " << v[i];
        }
    }
    return out;
}

#endif // __EDGE_H_INCLUDED__