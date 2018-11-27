/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <stack>
#include <queue>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // BFS
    TreeNode* invertTree1(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            TreeNode *cur = que.front();
            if(cur)
            {
                swap(cur->left,cur->right);
                que.push(cur->left);
                que.push(cur->right);
            }
            que.pop();
        }
        return root;
    }

    // DFS: bottom->top
    TreeNode* invertTree2(TreeNode* root)
    {
        if(!root)
            return root;
        invertTree2(root->left);
        invertTree2(root->right);
        swap(root->left,root->right);
        return root;
    }

    // Recursice: top -> bottom
    TreeNode* invertTree3(TreeNode* root)
    {
        if(!root)
            return NULL;

        swap(root->left, root->right);
        invertTree3(root->left);
        invertTree3(root->right);
        return root;
    }
    
    // Iterative
    TreeNode* invertTree4(TreeNode* root)
    {
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty())
        {
            TreeNode *cur = stk.top();
            stk.pop();
            if(cur)
            {
                swap(cur->left,cur->right);
                stk.push(cur->left);
                stk.push(cur->right);
            }
        }
        return root;
    }

	TreeNode* createBiTree(TreeNode *T)
	{
		int val;
		cin >> val;
		if(val == 0)
			return NULL;
		else
		{
			TreeNode *T = new TreeNode(val);
			T->left = createBiTree(T->left);
			T->right = createBiTree(T->right);
			return T;
		}
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
};

int main()
{
    Solution s;
    TreeNode *T = s.createBiTree(T);

    s.invertTree3(T);
    vector<int> pre = s.preorderTraversal(T);
    for(int i = 0; i < pre.size(); i++)
    {
    	cout << pre[i] << ' ';
	}
    cout << endl;
}
