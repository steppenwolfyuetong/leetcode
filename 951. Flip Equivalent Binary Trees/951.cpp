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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) {
            return true;
        } else if (root1 == nullptr || root2 == nullptr) {
            return false;
        }

        // not flip
        bool case1 = flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
        // flip
        bool case2 = flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);

        return (root1->val == root2->val) && (case1 || case2);
    }
};
