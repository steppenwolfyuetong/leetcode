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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)		// ÖÕÖ¹Ìõ¼þ
			return true;
		if(p == NULL || q == NULL)		// ¼ôÖ¦
			return false;
		return (p->val == q->val) && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
	*/
	
	bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> s;
		s.push(p);
		s.push(q);
		while(!s.empty())
		{
			p = s.top(); s.pop();
			q = s.top(); s.pop();
			if(!p && !q)
				continue;
			if(!p || !q)
				return false;
			if(p->val != q->val)
				return false;
			s.push(p->left);
			s.push(q->left);
			s.push(p->right);
			s.push(q->right);
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
	TreeNode *T1 = s->createBiTree(T1);
	TreeNode *T2 = s->createBiTree(T2);
	cout<<s->isSameTree(T1,T2);
	return 0;
}