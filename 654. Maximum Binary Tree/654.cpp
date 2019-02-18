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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, nums.begin(), nums.end());
    }

    using iter = vector<int>::iterator;
    TreeNode* build(vector<int>& nums, iter start, iter end) {
        if (start == end) {
            return nullptr;
        }
        iter maxElement = max_element(start, end);
        TreeNode *root = new TreeNode(*maxElement);
        root->left = build(nums, start, maxElement);
        root->right = build(nums, maxElement + 1, end);
        return root;
    }
};
