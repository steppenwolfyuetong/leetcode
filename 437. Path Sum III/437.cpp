#include<malloc.h>
#include<vector>
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
    int pathSum(TreeNode* root, int sum) {
        if(!root)
            return 0;

        return helper(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
private:
    int helper(TreeNode* node, int pre, int target)
    {
        if(!node)
            return 0;
        int cur = pre + node->val; 
        return (cur == target) + helper(node->left, cur, target) + helper(node->right, cur, target);
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
    Solution *s = new Solution();
    TreeNode *T = s->createBiTree(T);
    int sum = 8;
    cout << s->pathSum(T, sum) << endl;
    return 0;
}
