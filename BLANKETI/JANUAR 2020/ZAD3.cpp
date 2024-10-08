int GetMaxLevel() {
        if (!root) return -1;  // Ako je stablo prazno, vraćamo -1.

        std::queue<std::pair<BSTNodeInt*, int>> q; 
        q.push({root, 0});

        int maxLevel = -1;
        int maxDiff = INT_MIN;

        while (!q.empty()) {
            int size = q.size();
            int minValue = INT_MAX;
            int maxValue = INT_MIN;

            for (int i = 0; i < size; i++) {
                auto [node, level] = q.front();
                q.pop();

                
                if (node->value < minValue) minValue = node->value;
                if (node->value > maxValue) maxValue = node->value;

                
                if (node->left) q.push({node->left, level + 1});
                if (node->right) q.push({node->right, level + 1});
            }

            
            int diff = maxValue - minValue;
            if (diff > maxDiff) {
                maxDiff = diff;
                maxLevel = level;
            }
        }

        return maxLevel;
    }
