#include "result.h"
#include <vector>
using namespace std;

Result summerRec(const std::vector<int>& A, int left, int right) {
    int n = right - left;

    // Basisfälle
    if (n == 1) {
        int x = A.at(left);
        if (x > 0) return {x, left, right - 1};
        else return {0,0,-1};
    }
    if (n == 0) return {0,0,-1};

    // Divide and Conquer
    int m = n / 2;
    const Result resLeft = summerRec(A, left, left + m);
    const Result resRight = summerRec(A, left + m, right);


    int s = 0;
    int maxL = -1; 
    int maxLind = left;

    for (int i = left + m - 1; i >= left; i--) {
        s += A.at(i);
        if (s >= maxL) {
            maxL = s;
            maxLind = i;
        }
    }


    s = 0;
    int maxR = -1;
    int maxRind = right - m;

    for (int j = left + m; j < right; j++) { 
        s += A.at(j);
        if (s > maxR) {
            maxR = s;
            maxRind = j;
        }
    }

    // Bestimmen von maxmid
    Result maxmid = {maxL + maxR, maxLind, maxRind};

    // Rückgabe des größten Wertes
    return max(maxmid, max(resLeft, resRight));
}

int main() {
    int size;
    while (std::cin >> size) {
        std::vector<int> v(size);
        for (int& x : v) std::cin >> x;
        std::cout << summerRec(v, 0, v.size()) << std::endl;
    }
}