#include "LList.h"

LList* extractEven(LList* list) {
    LList* evenList = new LList();
    LListNode* current = list->getHead();
    LListNode* prev = nullptr;
    int index = 0;

    while (current != nullptr) {
        LListNode* nextNode = current->next;
        if (index % 2 == 0) {
            if (prev != nullptr) {
                prev->next = nextNode;
            } else {
                list->head = nextNode;
            }
            evenList->addToTail(current->info);
            delete current;
        } else {
            prev = current;
        }
        current = nextNode;
        index++;
    }

    return evenList;
}
