#include "LList.h"

void Exchange(LList* list, int k, int length) {
    if (list->isEmpty()) {
        cout << "List is empty." << endl;
        return;
    }

    LListNode* first = list->getHead();
    LListNode* second = list->getHead();
    int index = 0;

    while (first != nullptr && index < k) {
        first = first->next;
        index++;
    }

    index = 0;
    while (second != nullptr && index < k + length) {
        second = second->next;
        index++;
    }

    if (first == nullptr || second == nullptr) {
        cout << "Position out of bounds." << endl;
        return;
    }

    int temp = first->info;
    first->info = second->info;
    second->info = temp;
}
