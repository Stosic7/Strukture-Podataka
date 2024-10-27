#include "LList.h" 

void aggregateByPoints(LList* list, int threshold, LList* aboveThreshold, LList* belowThreshold) {
    LListNode* current = list->getHead();

    while (current != nullptr) {
        if (current->info > threshold) {
            aboveThreshold->addToTail(current->info);
        } else {
            belowThreshold->addToTail(current->info);
        }
        current = current->next;
    }
}
