void UmetniListu(DList& uredjena, DList& nova) {
    DListNode* current_uredjena = uredjena->head;
    DListNode* current_nova = nova->head;

    while (current_nova != nullptr) {
        DListNode* newNode = current_nova; 
        current_nova = current_nova->next; 

        
        while (current_uredjena != nullptr && current_uredjena->info < newNode->info) {
            current_uredjena = current_uredjena->next;
        }

        
        if (current_uredjena == nullptr) {
            
            newNode->prev = uredjena->tail;
            if (uredjena->tail != nullptr) {
                uredjena->tail->next = newNode;
            }
            newNode->next = nullptr;
            uredjena->tail = newNode;
            if (uredjena->head == nullptr) {
                uredjena->head = newNode;
            }
        } else {
            
            newNode->next = current_uredjena;
            newNode->prev = current_uredjena->prev;

            if (current_uredjena->prev != nullptr) {
                current_uredjena->prev->next = newNode;
            } else {
                
                uredjena->head = newNode;
            }

            current_uredjena->prev = newNode;
        }

        
        current_uredjena = newNode;
    }
}
