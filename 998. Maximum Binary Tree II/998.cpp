class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if (root == nullptr) {
            TreeNode* node = new TreeNode(val);
            return node;
        }

        if (root->val < val) {
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        } else {
            root->right = insertIntoMaxTree(root->right, val);
            return root;
        }
    }
};
