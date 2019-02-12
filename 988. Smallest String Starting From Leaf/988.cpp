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
    string smallestFromLeaf(TreeNode* root) {
        return dfs(root);
    }

    string dfs(TreeNode* root) {
        if (!root) {
            return "";
        }
        if (!root->left && !root->right) {
            return string(1, 'a' + root->val);
        }

        string left = dfs(root->left);
        string right = dfs(root->right);
        string suffix(1, 'a' + root->val);
        if (!root->left) {
            return right + suffix;
        } else if (!root->right) {
            return left + suffix;
        } else {
            return min(left, right) + suffix;
        }
    }
};
