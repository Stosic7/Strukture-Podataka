#include "OpenScatterTable.h"

bool addCompany(OpenScatterTable& table, const char* pib, const char* name, int employees, double revenue) {
    ScatterObject newCompany(pib, name, employees, revenue);
    return table.insert(newCompany);
}

ScatterObject* searchCompany(OpenScatterTable& table, const char* pib) {
    unsigned int index = table.g(table.f(pib));
    return table.find(index, pib);
}
