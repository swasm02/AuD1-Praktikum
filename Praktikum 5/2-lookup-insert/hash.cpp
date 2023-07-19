#include<iostream>
#include<vector>
#include<iterator>

template<class T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v) {
    out << '(';
    if(!v.empty()) {
        std::copy(v.begin(), v.end() - 1, std::ostream_iterator<T>(out, ","));
        out << v.back();
    }
    return out << ')';
}

const std::string EMPTY = "";  /* kommt nie als Schlüssel vor */

std::vector<std::string> table;

const int p = 16777259;
const std::vector<std::uint64_t> a = {
    5902272, 7629265, 5333771,12383661,11774175,
    9802969,12640503, 3201625,16072600, 3335533,
    5101852,    3440,13405035,12903727,13147288,
    1825828,16182670,12801869, 8007159, 2376172,
};

int linHash(const std::string& s) {
    /* TODO */
    // 64 bit integer because of overflow
    std::int64_t hash = 0; 

    // iterate over string and claculate hash by multiplying the ascii value of the char with the corresponding a_i
    for (int i = 0; i < s.size(); i++) {
        hash += s.at(i) * a.at(i);
    }

    // return the hash mod p
    return hash % p;
}

bool lookup(const std::string& s) {
    /* TODO */ 
    // calculate hash and mod table size -> index, no out of bounds because of mod
    int hash = linHash(s) % table.size();

    // find first empty spot or the string itself by linear probing -> simple increment
    while (table.at(hash) != EMPTY && table.at(hash) != s) {
        hash = (hash + 1) % table.size();
    }

    // case: string is in table -> return true
    if (table.at(hash) == s) {
        return true;
    }
    
    // else: string is not in table -> return false
    return false;
}

void insert(const std::string& s) {
    /* TODO */
    // calculate hash and mod table size -> index, no out of bounds because of mod
    int hash = linHash(s) % table.size(); 

    // find first empty spot or the string itself by linear probing -> simple increment
    while (table.at(hash) != EMPTY && table.at(hash) != s) {
        hash = (hash + 1) % table.size();
    }

    // case: string is already in table -> do nothing 
    if (table.at(hash) == s) {
        return;
    } 

    // case: empty spot -> insert
    if (table.at(hash) == EMPTY) {
        table.at(hash) = s;
    }
}

int main() {
    size_t size; std::cin >> size;
    /* erzeuge Tabelle der Groesse size, jeder Eintrag ist EMPTY */
    table.resize(size, EMPTY);
    char c; std::string s;
    while (std::cin >> c >> s) {
        switch (c) {
        case 'h': // case: calculate hash
            std::cout << "h(" << s << ") = " << linHash(s) << std::endl;
            break;
        case 'p': // case: print table
            std::cout << table << std::endl;
            break;
        case 'l': // case: lookup
            std::cout << lookup(s) << std::endl;
            break;
        case 'i': // case: insert
            insert(s);
            break;
        }
    }
}