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
    int sumNumbers(TreeNode* root) {
        return dfs(root,0);        
    }

    int dfs(TreeNode* root, int sum)
    {
		cout << sum << endl;
        if(!root)
            return 0;
        if(!root->left && !root->right)
        {
        	cout << sum * 10 + root->val << endl;
            return sum * 10 + root->val;
        }
        return dfs(root->left, sum * 10 + root->val) + dfs(root->right, sum * 10 + root->val);
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
    cout<<s->sumNumbers(T);
    return 0;
}
