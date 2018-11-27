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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> rt;
        queue<TreeNode*> level;

        if(!root)
            return rt;
        level.push(root);
        while(!level.empty())
        {
            int n = level.size();
            double sum = 0;
            for(int i = 0; i < n; i++)
            {
                TreeNode *node = level.front();
                level.pop();
                sum += node->val;
                if(node->left)
                    level.push(node->left);
                if(node->right)
                    level.push(node->right);
            }
            rt.push_back(sum / n);
        }
        return rt;
    }
};
