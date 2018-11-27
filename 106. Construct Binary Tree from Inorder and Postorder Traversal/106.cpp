#include<malloc.h>
#include<stack>
#include<vector>
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
	// Õ»
	TreeNode* buildTree(vector<int> &inorder, vector<int>& postorder)
	{
		if(inorder.size() != postorder.size())
			return NULL;
		if(!inorder.size())
			return NULL;
		stack<TreeNode*> s;
		TreeNode *root = new TreeNode(postorder[postorder.size()-1]);
		s.push(root);
		for(int i = postorder.size() - 2, j = inorder.size() - 1; i > -1; i--)
		{
			TreeNode *cur = s.top();
			if(cur->val != inorder[j])
			{
				cur->right = new TreeNode(postorder[i]);
				s.push(cur->right);
			}
			else
			{
				while(!s.empty() && s.top()->val == inorder[j])
				{
					cur = s.top();
					s.pop();
					j--;
				}
				if(j > -1)
				{
					cur->left = new TreeNode(postorder[i]);
					s.push(cur->left);
				}
			}
		}
		return root;
	}

	
	/*
	// µÝ¹é
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder,0,inorder.size(),postorder,0,postorder.size());
    }

    TreeNode* build(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe)
    {
        if(ps == pe)
            return NULL;
        TreeNode *root = new TreeNode(postorder[pe-1]);
        int index;
		for(index = is; index < ie; index++)
			if(inorder[index] == root->val)
				break;
		int dis = index - is;
        root->left = build(inorder,is,is+dis,postorder,ps,ps+dis);
        root->right = build(inorder,is+dis+1,ie,postorder,ps+dis,pe-1);
        return root;
    }
	*/
	
	vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        inorder(root,nodes);
        return nodes;
    }
    
    void inorder(TreeNode* root, vector<int>& nodes)
    {
        if(root == NULL)
            return;
        inorder(root->left,nodes);
        nodes.push_back(root->val);
        inorder(root->right,nodes);
        return;
    }
	
	vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nodes;
        postorder(root,nodes);
        return nodes;
    }

    void postorder(TreeNode* root, vector<int>& nodes)
    {
        if(root == NULL)
            return;
        postorder(root->left,nodes);
        postorder(root->right,nodes);
        nodes.push_back(root->val);
        return;
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
	int size = 8;
	int in[] = {4,7,2,1,5,3,8,6};
	int post[] = {7,4,2,5,8,6,3,1};
	vector<int> inorder,postorder;
	for(int i = 0; i < size; i++)
	{
		inorder.push_back(in[i]);
		postorder.push_back(post[i]);
	}
	TreeNode *T = s->buildTree(inorder,postorder);
	vector<int> traversal = s->inorderTraversal(T);
	for(int i = 0; i < traversal.size(); i++)
		cout<<traversal[i]<<' ';
	cout<<endl;
	traversal = s->postorderTraversal(T);
	for(int i = 0; i < traversal.size(); i++)
		cout<<traversal[i]<<' ';
	cout<<endl;
	return 0;
}



