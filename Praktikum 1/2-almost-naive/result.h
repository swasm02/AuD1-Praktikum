#ifndef __RESULT_H_INCLUDED__
#define __RESULT_H_INCLUDED__

#include <iostream>

// erstelltes struct "Result"
struct Result {
    int sum, i, j;
};

std::ostream& operator<< (std::ostream& out, const Result& r) {
    out << "(" << r.sum << "," << r.i << "," << r.j << ")";
    return out;
}

std::istream& operator>> (std::istream& in, Result& r) {
    char c;
    in >> c >> r.sum >> c >> r.i >> c >> r.j >> c;
    return in;
}

bool operator< (const Result& x, const Result& y) {
    // siehe Aufgabenblatt
    if (x.sum < y.sum) return true;
    if (x.sum == y.sum && (x.i > y.i || (x.i == y.i && x.j > y.j))) return true;

    return false;
}

#endif // __RESULT_H_INCLUDED__