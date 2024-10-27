#include "GraphInt.h"

void removeAllBridges(GraphAsListsInt& graph) {
    LinkedNodeInt* current = graph.getStartNode();

    while (current != nullptr) {
        LinkedEdgeInt* edge = current->adj;
        while (edge != nullptr) {
            if (graph.isBridge(current, edge->dest)) {
                graph.deleteEdge(current->node, edge->dest->node);
            }
            edge = edge->link;
        }
        current = current->next;
    }
}
