void findDeepestLeaf(BSTNodeInt* node, int depth, int& maxDepth, BSTNodeInt*& result) {
    if (node == nullptr) {
        return;
    }
    
    if (node->left == nullptr && node->right == nullptr) {
        if (depth > maxDepth) {
            maxDepth = depth;
            result = node;
        }
        return;
    }

    findDeepestLeaf(node->left, depth + 1, maxDepth, result);
    findDeepestLeaf(node->right, depth + 1, maxDepth, result);
}


BSTNodeInt* deepestLeaf(BSTNodeInt* root) {
    if (root == nullptr) {
        return nullptr;
    }

    BSTNodeInt* result = nullptr;
    int maxDepth = -1;
    
    findDeepestLeaf(root, 0, maxDepth, result);
    
    return result;
}
