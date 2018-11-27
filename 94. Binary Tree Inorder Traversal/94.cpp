#include<malloc.h>
#include<stack>
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
	/*
    // 递归
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
	*/
	
	/*
	// 栈
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> nodes;
        TreeNode *cur = root;
        while(cur || !nodes.empty())
        {
            if(cur)
            {
                nodes.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = nodes.top();
                nodes.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
        return result;
    }
	*/
	
	
    // Morris遍历
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode *cur = root, *pre = NULL;
        vector<int> result;
        while(cur)
        {
            if(cur->left == NULL)
            {
                result.push_back(cur->val);
                cur = cur->right;
            }
            else
            {
                pre = cur->left;
                while(pre->right && pre->right != cur)
                    pre = pre->right;
                if(pre->right == NULL)
                {
                    pre->right = cur;
                    cur = cur->left;
                }
                else
                {
                    pre->right = NULL;
                    result.push_back(cur->val);
                    cur = cur->right;
                }
            }
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
	vector<int> result = s->inorderTraversal(T);
	for(int i = 0; i < result.size(); i++)
		cout<<result[i]<<endl;
	return 0;
}
