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
	/*
    // 递归
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
	*/
	
	/*
    // 栈 先序遍历的思想 根-右-左 然后将其reverse
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> nodes;
        vector<int> result;
        if(root == NULL)
            return result;
        nodes.push(root);
        while(!nodes.empty())
        {
            TreeNode* cur = nodes.top();
            result.push_back(cur->val);
            nodes.pop();
            if(cur->left)
                nodes.push(cur->left);
            if(cur->right)
                nodes.push(cur->right);
        }
        reverse(result.begin(),result.end());
        return result;
    }
	*/
	
	// 栈 后序遍历
	vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> nodes;
        TreeNode *cur = root, *last = NULL;
        while(cur || !nodes.empty())
        {
            if(cur)
            {
                nodes.push(cur);
                cur = cur->left;
            }
            else
            {
                TreeNode *top = nodes.top();
                if(top->right && top->right != last)
                    cur = top->right;
                else
                {
                    result.push_back(top->val);
                    last = top;
                    nodes.pop();
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
	vector<int> result = s->postorderTraversal(T);
	for(int i = 0; i < result.size(); i++)
		cout<<result[i]<<endl;
	return 0;
}
