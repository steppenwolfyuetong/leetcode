/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include<queue>
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
    //BFS
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rt;
        if(!root)
            return rt;
        queue<TreeNode*> cur,next;
        cur.push(root);
        while(!cur.empty())
        {
            rt.push_back(cur.front()->val);
            while(!cur.empty())
            {
                TreeNode *p = cur.front();
                cur.pop();
                if(p->right)
                    next.push(p->right);
                if(p->left)
                    next.push(p->left);
            }
            swap(cur,next);
        }
        return rt;
    }

    //递归 dfs
    vector<int> rightSideView1(TreeNode* root) 
    {
        vector<int> rt;
        dfs(root,1,rt);
        return rt;
    }

    void dfs(TreeNode* root, int level, vector<int> &rt)
    {
        if(!root)
            return;
        if(rt.size() < level)
            rt.push_back(root->val);
        dfs(root->right,level+1,rt);
        dfs(root->left,level+1,rt);
    }

	vector<TreeNode*> preorderTraversal(TreeNode* root) {
        vector<TreeNode*> nodes;
        preorder(root,nodes);
        return nodes;
    }

    void preorder(TreeNode* root, vector<TreeNode*>& nodes)
    {
        if(root == NULL)
            return;
        nodes.push_back(root);
        preorder(root->left,nodes);
        preorder(root->right,nodes);
        return;
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
};

int main()
{
    Solution s;
    TreeNode *T = s.createBiTree(T);
    vector<int> result = s.rightSideView(T);
    for(vector<int>::iterator iter = result.begin(); iter != result.end(); iter++)
    {
        cout << *iter << ' ';
    }
}
