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

    bool findTarget(TreeNode *root, TreeNode *cur, int k) {
        if (cur == nullptr) {
            return false;
        }

        // select cur node, dfs traverse root to get k - cur->val.
        if (search(root, cur, k - cur->val)) {
            return true;
        }

        // select other node
        return findTarget(root, cur->left, k) || findTarget(root, cur->right, k);
    }

    // dfs from root to get target, cur is the one of selected node, target is k - cur->val.
    bool search(TreeNode *root, TreeNode *cur, int target) {
        if (root == nullptr) {
            return false;
        }

        if (root->val == target) {
            return cur != root;
        } else if (root->val > target) {
            return search(root->left, cur, target);
        } else {
            return search(root->right, cur, target);
        }
    }
};

class Solution {
    set<int> s;
    bool dfs(TreeNode *cur, int k) {
        if (!cur) return false;
        if (s.count(k - cur->val)) return true;
        s.insert(cur->val);
        return dfs(cur->left, k) || dfs(cur->right, k);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        s.clear();
        return dfs(root, k);
    }
};
