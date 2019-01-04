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
    TreeNode* convertBST(TreeNode* root) {
        int s = 0;
        inorder(root, s);
        return root;
    }

    // right -> root -> left
    void inorder(TreeNode *root, int &sum) {
        if (root == nullptr) {
            return;
        }
        inorder(root->right, sum);
        root->val += sum;
        sum = root->val;
        inorder(root->left, sum);
    }
};
