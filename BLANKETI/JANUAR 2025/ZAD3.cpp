// POMOĆNA – radi nad referencom na pokazivac da bismo mogli da postavimo child na nullptr
static int deleteLeavesDeeperThan(BSTNodeInt*& node, int depth, int level)
{
    if (!node) return 0;

    // ako je list
    if (node->left == nullptr && node->right == nullptr)
    {
        if (depth > level) {
            delete node;
            node = nullptr;
            return 1;
        }
        return 0;
    }

    int cnt = 0;
    cnt += deleteLeavesDeeperThan(node->left,  depth + 1, level);
    cnt += deleteLeavesDeeperThan(node->right, depth + 1, level);
    return cnt;
}

int numberDeletedLeaves(BSTNodeInt* root, int level)
{
    BSTNodeInt* r = root;
    int cnt = deleteLeavesDeeperThan(r, 0, level);
    return cnt;
}
