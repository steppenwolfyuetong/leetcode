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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == nullptr) {
            return false;
        }
        if (isSame(s, t)) {
            return true;
        }

        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }

    bool isSame(TreeNode* s, TreeNode *t) {
        if (s == nullptr && t == nullptr) {
            return true;
        } else if (s == nullptr || t == nullptr) {
            return false;
        } else if (s->val != t->val) {
            return false;
        }

        return isSame(s->left, t->left) && isSame(s->right, t->right);
    }
};
