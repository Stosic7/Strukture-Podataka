#include "BSTreeInt.h"

int findPathSum(BSTreeInt* tree, int targetKey) {
    BSTNodeInt* current = tree->getRoot();
    int pathSum = 0;

    while (current != nullptr) {
        pathSum += current->getKey();
        if (current->isEQ(targetKey))
            return pathSum;
        else if (current->isLT(targetKey))
            current = current->right;
        else
            current = current->left;
    }

    throw new exception("Key not found in tree");
}
