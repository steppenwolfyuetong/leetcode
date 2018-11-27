/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <math.h>
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
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        int leftHeight = 0, rightHeight = 0;
        TreeNode *left = root, *right = root;
        while(left)
        {
            leftHeight++;
            left = left->left;
        }
        while(right)
        {
            rightHeight++;
            right = right->right;
        }
        if(leftHeight == rightHeight)
            return pow(2,leftHeight) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
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
    cout << s.countNodes(T) << endl;
}
