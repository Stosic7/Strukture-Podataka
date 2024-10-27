#include "LList.h"

LListNode* FormList(int* array, int size) {
    LListNode* head = nullptr;

    for (int i = 0; i < size; ++i) {
        int el = array[i];
        LListNode* newNode = new LListNode(el);

        if (head == nullptr || head->info >= el) {
            newNode->next = head;
            head = newNode;
        } else {
            LListNode* current = head;
            while (current->next != nullptr && current->next->info < el) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    return head;
}
