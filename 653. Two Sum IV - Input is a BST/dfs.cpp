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
    bool findTarget(TreeNode* root, int k) {
        return findTarget(root, root, k);
    }

    // select one node, try to seach the other one
    // if this node is invalid, select its left child or right child to try again
    bool findTarget(TreeNode* root, TreeNode* selected, int k) {
        if (selected == nullptr) {
            return false;
        }

        // search the other node exists in bst
        if (search(root, selected, k - selected->val)) {
            return true;
        }

        return findTarget(root, selected->left, k) || findTarget(root, selected->right, k);
    }
    
    bool search(TreeNode *cur, TreeNode* selected, int target) {
        if (cur == nullptr) {
            return false;
        }
        
        if (cur->val == target) {
            return cur != selected;
        } else if (cur->val > target) {
            return search(cur->left, selected, target);
        } else {
            return search(cur->right, selected, target);
        }
    }
};
