#include<malloc.h>
#include<limits.h>
#include<stack>
#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	/*
	// µÝ¹é
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        int left = minDepth(root->left), right = minDepth(root->right);
		if(!root->left && !root->right)
			return 1;
        else if(root->left && !root->right)
			return left+1;
        else if(root->right && !root->left)
            return right+1;
		else
			return min(left,right)+1;
    }
	*/
	
	// µü´ú
    // Õ» ÏÈÐò±éÀú
	int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        int result = INT_MAX;
        stack<pair<TreeNode*,int> > s;
		s.push(make_pair(root,1));
        while(!s.empty())
        {
            TreeNode *cur = s.top().first;
            int depth = s.top().second;
            s.pop();
            if(!cur->left && !cur->right)
                result = min(result,depth);
            if(cur->left && result > depth)
                s.push(make_pair(cur->left,depth+1));
            if(cur->right && result > depth)
                s.push(make_pair(cur->right,depth+1));
        }
        return result;
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
    cout<<s->minDepth(T)<<endl;
    return 0;
}
