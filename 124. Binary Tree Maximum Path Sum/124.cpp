#include<malloc.h>
#include<limits.h>
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
    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        dfs(root,result);
        return result;
    }

    int dfs(TreeNode* root, int& result)
    {
        if(!root)
            return 0;
        int left = dfs(root->left, result);
        int right = dfs(root->right, result);
        int sum = root->val;
        if(left > 0)
            sum += left;
        if(right > 0)
            sum += right;
        result = max(result,sum);
        return max(left,right) > 0 ? max(left,right) + root->val : root->val;
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
    Solution *s = new Solution;
    TreeNode *T = s->createBiTree(T);
    int result = s->maxPathSum(T);
    cout<<result<<endl;
}
