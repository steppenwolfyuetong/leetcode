/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <stack>
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
    // recursive
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)
            return 0;

        int rt = 0;
        helper(root, rt, false);
        return rt;
    }

    void helper(TreeNode *root, int &sum, bool isLeft)
    {
        if(!root)
        {
            return;
        }
        if(!root->left && !root->right && isLeft)
        {
            sum += root->val;
            return;
        }

        helper(root->left, sum, true);
        helper(root->right, sum, false);
        return;
    }

    // iterative
    int sumOfLeftLeaves1(TreeNode* root) {
        if(!root)
            return 0;

        int rt = 0;
        stack<TreeNode*> stk;
        stk.push(root);

        while(!stk.empty())
        {
            TreeNode* node = stk.top();
            stk.pop();
            if(node->left != NULL)
            {
                if(node->left->left == NULL && node->left->right == NULL)
                {
                    rt += node->left->val;
                }
                else
                {
                    stk.push(node->left);
                }
            }

            if(node->right != NULL)
            {
                if(node->right->left != NULL || node->right->right != NULL)
                {
                    stk.push(node->right);
                }
            }
        }
        return rt;
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
    cout << s.sumOfLeftLeaves(T) << endl;
    cout << s.sumOfLeftLeaves1(T) << endl;
    return 0;
}
