#include<malloc.h>
#include<stack>
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
	/*
	// µÝ¹é
    bool isSymmetric(TreeNode* root) {
        if(!root)
			return true;
		else
			return isSymmetric(root->left,root->right);
	}
	
	bool isSymmetric(TreeNode* left,TreeNode* right)
	{
		if(!left && !right)
			return true;
		if(!left || !right)
			return false;
		if(left->val == right->val)
			if(isSymmetric(left->left,right->right) && isSymmetric(left->right,right->left))
				return true;
		return false;
    }
	*/
	
	// µü´ú Õ»
	bool isSymmetric(TreeNode* root)
	{
		if(!root)
			return true;
		stack<TreeNode*> s;
		s.push(root->right);
		s.push(root->left);
		while(!s.empty())
		{
			TreeNode* p = s.top();
			s.pop();
			TreeNode* q = s.top();
			s.pop();
			if(!p && !q)
				continue;
			if(!p || !q)
				return false;
			if(p->val != q->val)
				return false;
			s.push(p->left);
			s.push(q->right);
			s.push(p->right);
			s.push(q->left);
		}
		return true;
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
	cout<<s->isSymmetric(T);
	return 0;
}
