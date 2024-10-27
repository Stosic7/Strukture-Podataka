#include "BSTreeInt.h"

int countSingleLeavesNodes(BSTNodeInt* node) {
    if (node == nullptr) return 0;

    int count = 0;
    if ((node->left != nullptr && node->right == nullptr) || (node->left == nullptr && node->right != nullptr)) {
        count = 1;
    }

    count += countSingleLeavesNodes(node->left);
    count += countSingleLeavesNodes(node->right);

    return count;
}
