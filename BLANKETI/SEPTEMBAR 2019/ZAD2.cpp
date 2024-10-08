
unsigned int OpenScatterTable::f(const char* key) {
    unsigned int hash = 0;
    for (int i = 0; i < 2; i++) { 
        hash = hash * 26 + (key[i] - 'A');
    }
    for (int i = 3; i < 7; i++) { 
        hash = hash * 10 + (key[i] - '0');
    }
    for (int i = 8; i < 10; i++) { 
        hash = hash * 26 + (key[i] - 'A');
    }
    return hash;
}


unsigned int OpenScatterTable::c(unsigned int i) {
    return i * i;
}

bool OpenScatterTable::isVisited(char* key) {
    unsigned int index = h(key);
    for (unsigned int i = 0; i < m; i++) {
        unsigned int newIndex = (index + c(i)) % m;
        if (array[newIndex].status == 2 && array[newIndex].isEqualKey(key)) {
            return true;
        }
        if (array[newIndex].status == 0) {
            return false; 
        }
    }
    return false;
}

bool OpenScatterTable::hasPaid(char* key) {
    unsigned int index = h(key);
    for (unsigned int i = 0; i < m; i++) {
        unsigned int newIndex = (index + c(i)) % m;
        if (array[newIndex].status == 2 && array[newIndex].isEqualKey(key)) {
            return array[newIndex].isPaid; 
        }
        if (array[newIndex].status == 0) {
            return false;
        }
    }
    return false;
}

void OpenScatterTable::updatePaid(char* key, bool paid) {
    unsigned int index = h(key);
    for (unsigned int i = 0; i < m; i++) {
        unsigned int newIndex = (index + c(i)) % m;
        if (array[newIndex].status == 2 && array[newIndex].isEqualKey(key)) {
            array[newIndex].isPaid = paid;
            return;
        }
    }
}

void OpenScatterTable::visit(char* key, char* time, bool paid) {
    unsigned int index = h(key);
    for (unsigned int i = 0; i < m; i++) {
        unsigned int newIndex = (index + c(i)) % m;
        if (array[newIndex].status == 0 || array[newIndex].status == 1) { 
            array[newIndex] = ScatterObject(key);
            array[newIndex].time = time;
            array[newIndex].isPaid = paid;
            array[newIndex].status = 2; 
            count++;
            return;
        }
    }
    throw std::overflow_error("HashTable is full");
}
