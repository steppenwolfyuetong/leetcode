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
	// 栈 迭代
	/*
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if(preorder.size() != inorder.size())
			return NULL;
		if(!preorder.size())
			return NULL;
		stack<TreeNode*> s;
		TreeNode *root = new TreeNode(preorder[0]);
		s.push(root);
		for(int i = 1, j = 0; i < preorder.size(); i++)
		{
			TreeNode *cur = s.top();
			if(cur->val != inorder[j])
			{
				cur->left = new TreeNode(preorder[i]);
				s.push(cur->left);
			}
			else
			{
				while(!s.empty() && s.top()->val == inorder[j])
				{
					cur = s.top();
					s.pop();
					j++;
				}
				if(j < inorder.size())
				{
					cur->right = new TreeNode(preorder[i]);
					s.push(cur->right);
				}
			}
		}
		return root;
    }
	*/
	
	// 递归 
	// 因为每次vector都要赋值 Memory Limit Exceeded 应该用引用类型
	/*
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        return build(preorder,inorder);
    }
    
    TreeNode* build(vector<int> preorder, vector<int> inorder)
    {
        if(preorder.size() == 0)
            return NULL;
        if(preorder.size() != inorder.size())
            return NULL;
        TreeNode *root = new TreeNode(preorder[0]);
        int index;
        for(index = 0; index < inorder.size(); index++)
            if(inorder[index] == root->val)
                break;
        if(index == inorder.size())
            return NULL;
        vector<int> left_pre, left_in, right_pre, right_in;
        for(int i = 1; i < 1 + index; i++)
            left_pre.push_back(preorder[i]);
        for(int i = index + 1; i < preorder.size(); i++)
            right_pre.push_back(preorder[i]);
        for(int i = 0; i < index; i++)
            left_in.push_back(inorder[i]);
        for(int i = index + 1; i < inorder.size(); i++)
            right_in.push_back(inorder[i]);
        root->left = build(left_pre,left_in);
        root->right = build(right_pre,right_in);
        return root;
    }
	*/
	
	// 递归
	// 引用传值
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        return build(preorder,0,preorder.size(),inorder,0,inorder.size());
    }

    TreeNode* build(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie)
    {
        if(ps == pe)
            return NULL;
        TreeNode *root = new TreeNode(preorder[ps]);
		int dis = find(inorder.begin()+is,inorder.begin()+ie,root->val) - inorder.begin() - is;
        root->left = build(preorder,ps+1,ps+1+dis,inorder,is,is+dis);
        root->right = build(preorder,ps+1+dis,pe,inorder,is+dis+1,ie);
        return root;
    }
    	
	vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nodes;
        preorder(root,nodes);
        return nodes;
    }

    void preorder(TreeNode* root, vector<int>& nodes)
    {
        if(root == NULL)
            return;
        nodes.push_back(root->val);
        preorder(root->left,nodes);
        preorder(root->right,nodes);
        return;
    }
	
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
	int pre[] = {1,2,4,7,3,5,6,8};
	int in[] = {4,7,2,1,5,3,8,6};
	vector<int> preorder,inorder;
	for(int i = 0; i < size; i++)
	{
		preorder.push_back(pre[i]);
		inorder.push_back(in[i]);
	}
	TreeNode *T = s->buildTree(preorder,inorder);
	vector<int> traversal = s->preorderTraversal(T);
	for(int i = 0; i < traversal.size(); i++)
		cout<<traversal[i]<<' ';
	cout<<endl;
	traversal = s->inorderTraversal(T);
	for(int i = 0; i < traversal.size(); i++)
		cout<<traversal[i]<<' ';
	cout<<endl;
	return 0;
}
