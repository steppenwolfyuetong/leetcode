#include <malloc.h>
#include <stack>
#include <cmath>
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
    // 方法一
    // 需要重复遍历结点多次
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        if(abs(height(root->left)-height(root->right)) > 1)
			return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }

    int height(TreeNode* root)
    {
        if(!root)
            return 0;
        int left = height(root->left);
        int right = height(root->right);
        return max(left,right)+1;
    }
public:
    // 方法二
    // 每个结点只遍历一次
    bool isBalanced1(TreeNode* root)
    {
        int depth = 0;
        return helper(root, depth);
    }

    bool helper(TreeNode *root, int& depth)
    {
        if(root == NULL)
        {
            depth = 0;
            return true;
        }

        int leftDepth, rightDepth;
        if(helper(root->left, leftDepth) && helper(root->right, rightDepth))
        {
            if(abs(leftDepth - rightDepth) <= 1)
            {
                depth = max(leftDepth, rightDepth) + 1;
                return true;
            }
        }
        return false;
    }
	
public:
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
	Solution *s = new Solution;
	TreeNode *T = s->createBiTree(T);
	cout << s->isBalanced(T) << endl;
    cout << s->isBalanced1(T) << endl;
	return 0;
}
