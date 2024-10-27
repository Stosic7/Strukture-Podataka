#include "GraphInt.h"

LinkedNodeInt* findNearestCommonAncestor(GraphAsListsInt& graph, int node1, int node2) {
    LinkedNodeInt* ancestor = nullptr;
    std::vector<LinkedNodeInt*> path1 = graph.DFSWithPath(node1);
    std::vector<LinkedNodeInt*> path2 = graph.DFSWithPath(node2);

    int i = 0;
    while (i < path1.size() && i < path2.size() && path1[i] == path2[i]) {
        ancestor = path1[i];
        i++;
    }
    return ancestor;
}
