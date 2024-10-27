#include "BSTreeInt.h"

void buildAndTraverseBST(int arr[], int size) {
    BSTreeInt tree;

    for (int i = 0; i < size; ++i) {
        tree.insert(arr[i]);
    }

    cout << "In-order traversal: ";
    tree.inorder();
    cout << endl;

    cout << "Pre-order traversal: ";
    tree.preorder();
    cout << endl;

    cout << "Post-order traversal: ";
    tree.postorder();
    cout << endl;
}
