#include "OpenScatterTable.h"
#include <string>

bool AddWithTransformation(OpenScatterTable& table, const char* key) {

    std::string transformedKey = key;
    for (char& c : transformedKey) {
        c = ((c - '0' + 1) % 10) + '0';
    }

    ScatterObject newObj(transformedKey.c_str());
    return table.insert(newObj);
}
