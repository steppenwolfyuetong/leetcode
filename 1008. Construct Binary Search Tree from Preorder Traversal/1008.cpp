/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.empty()) {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder.front());
        for (int i = 1; i < preorder.size(); i++) {
            insert(root, preorder[i]);
        }
        return root;
    }

    void insert(TreeNode *root, int val) {
        if (val < root->val) {
            if (root->left == nullptr) {
                root->left = new TreeNode(val);
            } else {
                insert(root->left, val);
            }
        } else {
            if (root->right == nullptr) {
                root->right = new TreeNode(val);
            } else {
                insert(root->right, val);
            }
        }
    }
};
