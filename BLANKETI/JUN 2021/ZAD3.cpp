#include "BSTreeInt.h"

int countOneChildNodes(BSTNodeInt* node) {
    if (node == nullptr) return 0;

    int count = 0;
    if ((node->left != nullptr && node->right == nullptr) || (node->left == nullptr && node->right != nullptr)) {
        count = 1;
    }

    count += countOneChildNodes(node->left);
    count += countOneChildNodes(node->right);

    return count;
}
