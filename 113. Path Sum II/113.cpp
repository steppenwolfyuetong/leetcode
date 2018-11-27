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
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<vector<int> > result;
		vector<int> path;
        pathSum(root, sum, path, result);
        return result;
    }

private:
    void pathSum(TreeNode *root, int sum, vector<int>& path, vector<vector<int> >& result)
    {
        if(!root)
            return;
        path.push_back(root->val);
        if(!root->left && !root->right)
            if(sum == root->val)
                result.push_back(path);
        pathSum(root->left, sum - root->val, path, result);
        pathSum(root->right, sum - root->val, path, result);
        path.pop_back();
        return;
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
	vector<vector<int> > path = s->pathSum(T,22);
	for(int i = 0; i < path.size(); i++)
	{
		for(int j = 0; j < path[i].size(); j++)
			cout<<path[i][j]<<' ';
		cout<<endl;
	}
	return 0;
}
