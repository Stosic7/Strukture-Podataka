#include "LList.h"


int countElements(LList* list) {
    int count = 0;
    LListNode* tmp = list->getHead();
    while (tmp != nullptr) {
        count++;
        tmp = tmp->next;
    }
    return count;
}

bool LList::DeleteElement(int i, int j) {
    
    int totalElements = countElements(this);
    if (i < 0 || i >= totalElements || j < 0 || j >= totalElements) {
        return false; 
    }

    
    bool deletedI = false;
    bool deletedJ = false;

    
    if (i == j) {
        deleteEl(i);
        deletedI = true;
    } else {
        
        if (i > j) {
            deleteEl(i);
            deletedJ = deleteEl(j);
        } else {
            deletedI = deleteEl(i);
            deleteJ = deleteEl(j);
        }
    }

    return (deletedI || deletedJ);
}
