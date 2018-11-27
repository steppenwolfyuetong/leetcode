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
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> inorder = inorderTraversal(root);
        displayTree(inorder);
        vector<TreeNode*>::iterator iter1 = inorder.begin();
        for(; iter1 != inorder.end() - 1; iter1++)
            if((*iter1)->val > (*(iter1+1))->val)
                break;
        vector<TreeNode*>::reverse_iterator iter2 = inorder.rbegin();
        for(; iter2 != inorder.rend() - 1; iter2++)
            if((*iter2)->val < (*(iter2+1))->val)
                break;
		swap((*iter1)->val,(*iter2)->val);
		inorder = inorderTraversal(root);
        displayTree(inorder);
    }

    void displayTree(vector<TreeNode*> tree)
    {
        for(int i = 0; i < tree.size(); i++)
            cout<<tree[i]->val<<' ';
        cout<<endl;
        return;
    }
	
	// Morris±éÀú
	vector<TreeNode*> inorderTraversal(TreeNode* root)
	{
		TreeNode *cur = root, *pre = NULL;
		vector<TreeNode*> result;
		while(cur)
		{
			if(cur->left == NULL)
			{
				result.push_back(cur);
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
					result.push_back(cur);
					cur = cur->right;
				}
			}
		}
		return result;
	}
	/*
	// Õ»
    vector<TreeNode*> inorderTraversal(TreeNode* root)
    {
        vector<TreeNode*> result;
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
                result.push_back(cur);
                nodes.pop();
                cur = cur->right;
            }
        }
        return result;
    }
	*/

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
    s->recoverTree(T);
	return 0;
}
