class BTreeNode {
public:
    int* keys;          
    int t;              
    BTreeNode** C;    
    int n;              
    bool leaf;          

    BTreeNode(int _t, bool _leaf);
};

int BTree::count() {
    return countHelper(root); 
}

int BTree::countHelper(BTreeNode* node) {
    if (node == nullptr) {
        return 0; 
    }

    int count = 1; 
    for (int i = 0; i < node->n; i++) {
        count += countHelper(node->C[i]); 
    }
    return count; 
}

BTreeNode* BTree::maxNode(int& maxN) {
    return maxNodeHelper(root, maxN);
}

BTreeNode* BTree::maxNodeHelper(BTreeNode* node, int& maxN) {
    if (node == nullptr) {
        maxN = 0;
        return nullptr;
    }

    BTreeNode* result = nullptr;
    for (int i = 0; i <= node->n; i++) {
        int leftCount = countHelper(node->C[i]); 
        int rightCount = countHelper(node->C[i + 1]); 
        int difference = abs(leftCount - rightCount); 

        if (difference > maxN) { 
            maxN = difference; 
            result = node; 
        }
    }
    return result; 
}
