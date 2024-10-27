#include "LList.h"

void Relocate(LList* list, int info, int pos) {
    LListNode* prev = nullptr;
    LListNode* current = list->getHead();
    LListNode* nodeToMove = nullptr;
    LListNode* nodeToMovePrev = nullptr;
    int index = 0;

    
    while (current != nullptr) {
        if (current->info == info) {
            nodeToMove = current;
            nodeToMovePrev = prev;
            break;
        }
        prev = current;
        current = current->next;
    }

    if (nodeToMove == nullptr) {
        throw std::invalid_argument("Element not found in list");
    }

    
    if (nodeToMovePrev != nullptr) {
        nodeToMovePrev->next = nodeToMove->next;
    } else {
        list->head = nodeToMove->next; 
    }

    
    current = list->getHead();
    prev = nullptr;
    index = 0;

    while (current != nullptr && index < pos) {
        prev = current;
        current = current->next;
        index++;
    }

    if (prev == nullptr) {
        
        nodeToMove->next = list->getHead();
        list->head = nodeToMove;
    } else {
        prev->next = nodeToMove;
        nodeToMove->next = current;
    }
}
