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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> table;
        int maxCount = 0;
        helper(root, table, maxCount);

        vector<int> rt;
        for(auto &kv : table)
        {
            if(kv.second == maxCount)
            {
                rt.push_back(kv.first);
            }
        }
        return rt;
    }

    int helper(TreeNode *root, unordered_map<int, int> &table, int &maxCount)
    {
        if(root == NULL)
            return 0;

        int sum = root->val;
        sum += helper(root->left, table, maxCount);
        sum += helper(root->right, table, maxCount);
        table[sum] += 1;
        maxCount = max(maxCount, table[sum]);
        return sum;
    }
};
