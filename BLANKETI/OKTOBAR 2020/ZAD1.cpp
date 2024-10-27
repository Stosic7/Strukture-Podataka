#include "LList.h" 

void addSorted(LList* list, int el) {
    if (list->isEmpty()) {
        list->addToHead(el);
        return;
    }

    LListNode* prev = nullptr;
    LListNode* current = list->getHead();
    while (current != nullptr && current->info < el) {
        prev = current;
        current = current->next;
    }

    LListNode* newNode = new LListNode(el);
    if (prev == nullptr) {
        newNode->next = list->getHead();
        list->head = newNode;
    } else {
        prev->next = newNode;
        newNode->next = current;
    }
}
