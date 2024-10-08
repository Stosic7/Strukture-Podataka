void DList::transpose(int el) {
    if (isEmpty())
        throw new exception("List is empty");

    DListNode* node = findNodePtr(el);
    
    if (node == nullptr || node->prev == nullptr)
        return;

    DListNode* prevNode = node->prev;
    DListNode* nextNode = node->next;

    
    if (prevNode->prev != nullptr) {
        prevNode->prev->next = node;
    } else {
        
        head = node;
    }

    node->prev = prevNode->prev;
    node->next = prevNode;

    prevNode->prev = node;
    prevNode->next = nextNode;

    if (nextNode != nullptr) {
        nextNode->prev = prevNode;
    }
}
