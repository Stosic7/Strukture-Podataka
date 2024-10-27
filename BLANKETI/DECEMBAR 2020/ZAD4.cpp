// Task 4b - Finding the shortest path in a graph using BFS

#include "GraphInt.h"

int findShortestPathBFS(GraphAsListsInt& graph, int start, int end) {
    LinkedNodeInt* startNode = graph.findNode(start);
    LinkedNodeInt* endNode = graph.findNode(end);

    if (startNode == nullptr || endNode == nullptr) {
        cout << "Error: Start or end node not found in graph." << endl;
        return -1;
    }

    QueueAsArrayLinkedNodeInt queue(graph.nodeNum);
    startNode->status = 2; // Mark as visited
    queue.enqueue(startNode);

    int pathLength = 0;

    while (!queue.isEmpty()) {
        LinkedNodeInt* current = queue.dequeue();
        if (current->node == end)
            return pathLength;

        LinkedEdgeInt* edge = current->adj;
        while (edge != nullptr) {
            if (edge->dest->status == 1) { // If not visited
                edge->dest->status = 2;
                queue.enqueue(edge->dest);
            }
            edge = edge->link;
        }
        pathLength++;
    }

    return -1; // No path found
}
