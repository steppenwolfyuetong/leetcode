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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> s1, s2;
        leafSequence(root1, s1);
        leafSequence(root2, s2);
        return s1 == s2;
    }

    void leafSequence(TreeNode* root, vector<int> &seq) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            seq.push_back(root->val);
            return;
        }

        leafSequence(root->left, seq);
        leafSequence(root->right, seq);
    }
};
