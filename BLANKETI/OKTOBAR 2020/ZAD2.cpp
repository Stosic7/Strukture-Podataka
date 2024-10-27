#include "OpenScatterTable.h"

bool addWorker(OpenScatterTable& table, const char* id) {
    unsigned int branchCode = table.g(table.f(id)) % 1000;

    ScatterObject newObj(id);
    return table.insert(newObj);
}
