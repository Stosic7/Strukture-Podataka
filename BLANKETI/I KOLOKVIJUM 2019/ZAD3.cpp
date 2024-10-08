/* f, g i c su vec implementirane) */

// OpenScatterTable.cpp

#include "OpenScatterTable.h"
using namespace std;


unsigned int OpenScatterTable::findUnoccupied(ScatterObject obj) {
    unsigned int index = h(obj.getKey());
    unsigned int i = 0;

    while (i < m) {
        unsigned int pos = (index + c(i)) % m;  
        if (array[pos].status == 0 || array[pos].status == 1) { // 0 - slobodan, 1 - obrisan
            return pos;  
        }
        i++;
    }

    return m;  
}


void OpenScatterTable::insert(ScatterObject obj) {
    unsigned int pos = findUnoccupied(obj);
    
    if (pos == m) {
        throw new exception("Hash table is full!");
    }

    
    if (array[pos].status == 2 && array[pos] == obj) {
        array[pos] = obj; 
        return;
    }

    
    array[pos] = obj;    
    array[pos].status = 2; 
    count++;  
}
