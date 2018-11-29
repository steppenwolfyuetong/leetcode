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
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return isBalanced(root, height);
    }
    
    bool isBalanced(TreeNode* root, int &height) {
        if (root == nullptr) {
            return true;
        }
        int left = height + 1, right = height + 1;
        if (isBalanced(root->left, left) && isBalanced(root->right, right)) {
            if (abs(left - right) <= 1) {
                height = max(left, right);
                return true;
            }
        }
        return false;
    }
};
