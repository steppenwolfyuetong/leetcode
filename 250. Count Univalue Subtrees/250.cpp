/*
Given a binary tree, count the number of uni-value subtrees.
A Uni-value subtree means all nodes of the subtree have the same value.

For example:
Given binary tree,

              5
             / \
            1   5
           / \   \
          5   5   5
 
return 4.
*/


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {
        int rt = 0;
        helper(rt, -1, rt);
        return rt;
    }

    bool helper(TreeNode* root, int val, int &rt)
    {
        if(!root)
            return false;
        if(!helper(root->left, root->val, rt) || !helper(root->right, root->val, rt))
            return false;

        rt++;
        return root->val == val;
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
