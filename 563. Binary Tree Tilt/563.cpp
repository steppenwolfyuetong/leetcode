/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include<malloc.h>
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int findTilt(TreeNode* root) {
        int tilt = 0;
        helper(root, tilt);
        return tilt;
    }
    
    int helper(TreeNode* root, int &tilt)
    {
        if(!root)
            return 0;

        int left = helper(root->left, tilt);
        int right = helper(root->right, tilt);
        tilt += abs(left - right);
        return left + right + root->val;
    }

    TreeNode* createBiTree(TreeNode *T)
	{
		int val;
		cin>>val;
		if(val == 0)
			return NULL;
		else
		{
			if(!(T = (TreeNode *) malloc(sizeof(TreeNode))))
				cout<<"Failure"<<endl;
			T->val = val;
			T->left = createBiTree(T->left);
			T->right = createBiTree(T->right);
			return T;
		}
	}
};

int main()
{
    Solution *s = new Solution();
    TreeNode *root = s->createBiTree(root);
    cout << s->findTilt(root) << endl;
    return 0;
}
