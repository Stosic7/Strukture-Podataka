#include "GraphInt.h"

int shortestPathBFS(GraphAsListsInt& graph, int start, int end) {
    LinkedNodeInt* startNode = graph.findNode(start);
    LinkedNodeInt* endNode = graph.findNode(end);

    if (startNode == nullptr || endNode == nullptr) {
        throw new exception("Start or end node not found in graph");
    }

    QueueAsArrayLinkedNodeInt queue(graph.nodeNum);
    startNode->status = 2;
    queue.enqueue(startNode);

    int pathLength = 0;

    while (!queue.isEmpty()) {
        LinkedNodeInt* current = queue.dequeue();
        if (current->node == end)
            return pathLength;

        LinkedEdgeInt* edge = current->adj;
        while (edge != nullptr) {
            if (edge->dest->status == 1) {
                edge->dest->status = 2;
                queue.enqueue(edge->dest);
            }
            edge = edge->link;
        }
        pathLength++;
    }

    return -1; 
