#include "GraphInt.h"

int canReachMoreWithUndirected(GraphAsListsInt& graph, LinkedNodeInt* startNode) {
    QueueAsArrayLinkedNodeInt queue(graph.nodeNum);
    int reachableCount = 0;

    graph.setStatusForAllNodes(1);

    queue.enqueue(startNode);
    startNode->status = 2;

    while (!queue.isEmpty()) {
        LinkedNodeInt* current = queue.dequeue();
        reachableCount++;

        LinkedEdgeInt* edge = current->adj;
        while (edge != nullptr) {
            if (edge->dest->status == 1) { 
                queue.enqueue(edge->dest);
                edge->dest->status = 2;
            }
            if (current->status == 1) { 
                queue.enqueue(current);
                current->status = 2;
            }
            edge = edge->link;
        }
    }

    return reachableCount;
}
