/*
Given a binary tree, find the length of the longest consecutive sequence path.
The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).
For example,
   1
    \
     3
    / \
   2   4
        \
         5
Longest consecutive sequence path is 3-4-5, so return 3.
   2
    \
     3
    / 
   2    
  / 
 1
Longest consecutive sequence path is 2-3,not3-2-1, so return 2.
*/

#include <cstdio>
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
    int longestConsecutive(TreeNode* root) 
    {
        if(!root)
            return 0;
        int count = 1, rt = 1;
        helper(root, count, rt);
        return rt;
    }

    void helper(TreeNode* root, int count, int& rt)
    {
        if(!root)
            return;

        if(root->left)
        {
            if(root->left->val == root->val + 1)
            {
                rt = max(count + 1, rt);
                helper(root->left, count + 1, rt);
            }
            else
            {
                helper(root->left, 1, rt);
            }
        }

        if(root->right)
        {
            if(root->right->val == root->val + 1)
            {
                rt = max(count + 1, rt);
                helper(root->right, count + 1, rt);
            }
            else
            {
                helper(root->right, 1, rt);
            }
        }
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
    cout << s.longestConsecutive(T) << endl;
}
