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
    int longestUnivaluePath(TreeNode* root) {
        int result = 0;
        dfs(root, result);
        return result;
    }

    // update result of longestUnivaluePath which pass the root
    int dfs(TreeNode* root, int& result) {
        if (root == nullptr) {
            return 0;
        }

        int leftPath = 0, leftResult = 0;
        if (root->left) {
            // leftPath is length of path go from root to root->left
            leftPath = dfs(root->left, result);
            if (root->left->val == root->val) {
                // leftResult is length of univalue path from root to root->left
                leftResult = leftPath + 1;
            }
        }

        int rightPath = 0, rightResult = 0;
        if (root->right) {
            // rightPath is length of path go from root to root->right
            rightPath = dfs(root->right, result);
            if (root->right->val == root->val) {
                // rightResult is length of univalue path from root to root->right
                rightResult = rightPath + 1;
            }
        }

        result = max(result, leftResult + rightResult);
        return max(leftResult, rightResult);
    }
};
