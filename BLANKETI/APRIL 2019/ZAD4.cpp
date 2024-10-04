bool GraphAsListsInt::canReach(LinkedNodeInt* a, LinkedNodeInt* b, int hops) const {
    if (hops < 0) return false; 
    if (a == b) return true;    

    setStatusForAllNodes(0);

    StackAsArrayLinkedNodeInt stack(nodeNum);
    stack.push(a);
    a->status = 1; 

    while (!stack.isEmpty()) {
        LinkedNodeInt* current = stack.pop();
        
        if (current == b) return true;

        if (hops > 0) { 
            LinkedEdgeInt* edge = current->adj;
            while (edge != nullptr) {
                LinkedNodeInt* neighbor = edge->dest;
                if (neighbor->status == 0) { 
                    neighbor->status = 1; 
                    stack.push(neighbor); 
                }
                edge = edge->link;
            }
            
            if (canReach(current, b, hops - 1)) return true;
        }
    }

    return false;
}
