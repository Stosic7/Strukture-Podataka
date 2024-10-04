int HashFunction(int workerID) {
    return workerID % 1000; // Uzima poslednje 3 cifre radnikove oznake
}

Worker* DeleteLastSynonym(Node*& head) {
    if (head == nullptr) {
        return nullptr; // Lista je prazna
    }

    Node* prev = nullptr;
    Node* current = head;

    // Ako postoji samo jedan sinonim u listi
    if (current->next == nullptr) {
        Worker* data = current->data;
        delete current;
        head = nullptr;
        return data;
    }

    // Prolazak kroz listu do poslednjeg sinonima
    while (current->next != nullptr) {
        prev = current;
        current = current->next;
    }

    Worker* data = current->data; // Čuvanje podataka poslednjeg radnika
    delete current; // Brisanje poslednjeg sinonima
    prev->next = nullptr; // Postavljanje prethodnog sinonima da pokazuje na null

    return data;
}
