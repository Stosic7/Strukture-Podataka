#include "GraphInt.h"
#include <vector>

LinkedNodeInt* findLeastNodesPath(GraphAsListsInt& graph, LinkedNodeInt* first, LinkedNodeInt* last) {
    if (first == nullptr || last == nullptr) {
        throw std::invalid_argument("One or both nodes not found.");
    }

    QueueAsArrayLinkedNodeInt queue(graph.nodeNum);
    queue.enqueue(first);
    first->status = 2;

    while (!queue.isEmpty()) {
        LinkedNodeInt* current = queue.dequeue();

        if (current == last) {
            return current;
        }

        LinkedEdgeInt* edge = current->adj;
        while (edge != nullptr) {
            if (edge->dest->status == 1) {
                edge->dest->status = 2;
                queue.enqueue(edge->dest);
            }
            edge = edge->link;
        }
    }

    return nullptr;
}
