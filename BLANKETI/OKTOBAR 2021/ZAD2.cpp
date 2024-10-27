#include "OpenScatterTable.h"
#include <iostream>

class HashTableWithSpecificFunction : public OpenScatterTable {
public:
    HashTableWithSpecificFunction(int size) : OpenScatterTable(size) {}

    unsigned int specificHashFunction(int key) const {
        return (3 * key + 7) % m;
    }

    bool insertWithSpecificFunction(int number) {
        unsigned int index = specificHashFunction(number);
        ScatterObject obj(std::to_string(number).c_str());
        if (!insert(obj)) {
            std::cout << "Collision at index: " << index << std::endl;
            return false;
        }
        return true;
    }
};
