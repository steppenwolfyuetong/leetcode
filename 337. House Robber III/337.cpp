/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

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
    int rob(TreeNode* root)
    {
        int l, r;
        return helper(root, l, r);
    }

    int helper(TreeNode* root, int &left, int &right)
    {
        if(!root)
            return 0;

        int ll = 0, lr = 0, rl = 0, rr = 0;
        left = helper(root->left, ll, lr);
        right = helper(root->right, rl, rr);

        return max(root->val + ll + lr + rl + rr, left + right);
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
    cout << s.rob(T) << endl;
}
