#include "BSTreeInt.h"

int MaxLevel(BSTreeInt* tree) {
    return findMaxLevel(tree->getRoot());
}

int findMaxLevel(BSTNodeInt* node) {
    if (node == nullptr) return 0;
    int leftDepth = findMaxLevel(node->left);
    int rightDepth = findMaxLevel(node->right);
    return 1 + std::max(leftDepth, rightDepth);
}
