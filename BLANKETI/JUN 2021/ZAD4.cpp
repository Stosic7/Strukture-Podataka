#include "GraphInt.h"

void removeLargestBranch(GraphAsListsInt& graph) {
    LinkedNodeInt* startNode = graph.getStartNode();
    LinkedNodeInt* largestBranch = nullptr;
    int maxNodes = 0;

    
    while (startNode != nullptr) {
        int nodeCount = graph.countBranchNodes(startNode); 
        if (nodeCount > maxNodes) {
            maxNodes = nodeCount;
            largestBranch = startNode;
        }
        startNode = startNode->next;
    }

    
    if (largestBranch != nullptr) {
        graph.deleteBranch(largestBranch);
    }
}
