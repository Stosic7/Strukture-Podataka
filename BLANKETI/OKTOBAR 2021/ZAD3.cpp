#include "BSTreeInt.h"

int countSpecificNodes(BSTNodeInt* node) {
    if (node == nullptr) return 0;

    int count = 0;
    if (node->left == nullptr && node->right != nullptr) {
        count = 1;
    }

    count += countSpecificNodes(node->left);
    count += countSpecificNodes(node->right);

    return count;
}
