class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;

        for (auto& desc : descriptions) {
            int parentVal = desc[0];
            int childVal = desc[1];
            int isLeft = desc[2];

            if (!nodes.count(parentVal)) {
                nodes[parentVal] = new TreeNode(parentVal);
            }

            if (!nodes.count(childVal)) {
                nodes[childVal] = new TreeNode(childVal);
            }

            TreeNode* parent = nodes[parentVal];
            TreeNode* child = nodes[childVal];

            if (isLeft == 1) {
                parent->left = child;
            } else {
                parent->right = child;
            }
            children.insert(childVal);
        }
        for (auto& desc : descriptions) {
            int parentVal = desc[0];

            if (!children.count(parentVal)) {
                return nodes[parentVal];
            }
        }
        return nullptr;
    }
};