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
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        int rt = 0;
        dfs(root, rt);
        return rt;
    }

    // return max height of root
    int dfs(TreeNode* root, int &diameter) {
        if (root == nullptr) {
            return 0;
        }

        int left = dfs(root->left, diameter);
        int right = dfs(root->right, diameter);

        // update diameter if longest path with pass through current root is bigger
        if (left + right > diameter) {
            diameter = left + right;
        }

        return max(left, right) + 1;
    }
};

