/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> rt;
        if(root == NULL)
            return rt;

        unordered_map<int, int> count;
        inorder(root, count);

        int maxCount = 0;
        for(auto kv : count)
        {
            if(kv.second > maxCount)
            {
                maxCount = kv.second;
            }
        }

        for(auto kv : count)
        {
            if(kv.second == maxCount)
            {
                rt.push_back(kv.first);
            }
        }
        return rt;
    }

    void inorder(TreeNode *root, unordered_map<int, int> &count)
    {
        if(root == NULL)
            return;
        inorder(root->left, count);
        count[root->val] += 1;
        inorder(root->right, count);
        return;
    }

	TreeNode* createBiTree(TreeNode *T)
	{
		int val;
		cin >> val;
		if(val == 0)
			return NULL;
		else
		{
			TreeNode *T = new TreeNode(val);
			T->left = createBiTree(T->left);
			T->right = createBiTree(T->right);
			return T;
		}
	}
};

int main()
{
    Solution s;
    TreeNode *T = s.createBiTree(T);
    vector<int> rt = s.findMode(T);
    for(auto num : rt)
        cout << num << endl;
    return 0;
}
