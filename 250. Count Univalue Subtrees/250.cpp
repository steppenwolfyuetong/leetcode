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
    int countUnivalSubtrees(TreeNode* root) {
        int rt = 0;
        helper(root, -1, rt);
        return rt;
    }

    // val is the value of parent of cur
    bool helper(TreeNode* cur, int val, int &rt)
    {
        if (cur == nullptr) {
            return true;
        }

        if (!helper(cur->left, cur->val, rt) | !helper(cur->right, cur->val, rt)) {
            return false;
        }

        // subtree (root is cur) is unival subtree
        rt++;
        return cur->val == val;
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

int main() {
    Solution *s = new Solution();
    TreeNode *root = new TreeNode(0);
    root = s->createBiTree(root);
    cout << s->countUnivalSubtrees(root) << endl;
}
