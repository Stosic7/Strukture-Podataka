#include "BSTreeInt.h"
#include <cmath>

BSTNodeInt* findClosestValueBSTNode(BSTNodeInt* root, int val) {
    BSTNodeInt* closest = nullptr;
    int minDiff = INT_MAX;

    while (root != nullptr) {
        int diff = std::abs(root->key - val);
        if (diff < minDiff) {
            minDiff = diff;
            closest = root;
        }

        if (root->key < val) {
            root = root->right;
        } else {
            root = root->left;
        }
    }

    return closest;
}
