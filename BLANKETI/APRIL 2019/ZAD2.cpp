class HashTable3D {
private:
    struct Entry {
        int x, y, z;
        double value;
        bool isOccupied;
        Entry() : isOccupied(false) {}
    };
    
    Entry* table;
    int capacity;
    int size;

public:
    HashTable3D(int M, int N, int P) {
        capacity = M * N * P; 
        table = new Entry[capacity];
        size = 0;
    }

    ~HashTable3D() {
        delete[] table;
    }
};

int primaryHash(int x, int y, int z, int M, int N, int P) {
    return (x * N * P + y * P + z) % capacity; 
}

int secondaryHash(int hashValue, int i) {
    return (hashValue + i * i) % capacity; 
}

void insert(int x, int y, int z, double val) {
    int hashValue = primaryHash(x, y, z, M, N, P);
    int i = 0;

   
    while (table[hashValue].isOccupied) {
        hashValue = secondaryHash(hashValue, ++i);
    }

    
    table[hashValue].x = x;
    table[hashValue].y = y;
    table[hashValue].z = z;
    table[hashValue].value = val;
    table[hashValue].isOccupied = true;
    size++;
}
