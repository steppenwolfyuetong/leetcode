/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <vector>
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> rt;
        dfs(root,"",rt);
        return rt;
    }

    void dfs(TreeNode *root, string prefix, vector<string> &rt)
    {
        if(!root)
            return;
        /*
        char buf[10];
        sprintf(buf,"%d",root->val);
        string cur = buf;
        */
        if(!prefix.empty())
            prefix += "->";
        prefix += to_string(root->val);

        if(!root->left && !root->right)
        {
            rt.push_back(prefix);
            return;
        }
        else
        {
            dfs(root->left, prefix, rt);
            dfs(root->right, prefix, rt);
        }
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
    vector<string> rt = s.binaryTreePaths(T);
    for(int i = 0; i < rt.size(); i++)
    {
        cout << rt[i] << endl;
    }
    return 0;
}
