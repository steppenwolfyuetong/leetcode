/*
 *
 * Given a binary tree, find all leaves and then remove those leaves. Then repeat the previous steps until the tree is empty.
 * 
 * Example:
 * Given binary tree 
 *           1
 *          / \
 *         2   3
 *        / \     
 *       4   5    
 * Returns [4, 5, 3], [2], [1].
 * 
 * Explanation:
 * 1. Remove the leaves [4, 5, 3] from the tree
 *           1
 *          / 
 *         2          
 * 2. Remove the leaf [2] from the tree
 *           1          
 * 3. Remove the leaf [1] from the tree
 *           []         
 * Returns [4, 5, 3], [2], [1].
 */


#include <iostream>
#include <vector>
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
    // 根据树的深度
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        helper(root, res);
        return res;
    }

    int helper(TreeNode *root, vector<vector<int>> &res) {
        if (!root) 
            return -1;
        int depth = 1 + max(helper(root->left, res), helper(root->right, res));
        if (depth >= res.size()) 
            res.resize(depth + 1);
        res[depth].push_back(root->val);
        return depth;
    }
    */

    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        while(root)
        {
            vector<int> leaves;
            root = remove(root, leaves);
            res.push_back(leaves);
        }
        return res;
    }

    TreeNode* remove(TreeNode *root, vector<int> &leaves)
    {
        if(root == NULL)
            return NULL;

        if(root->left == NULL && root->right == NULL)
        {
            leaves.push_back(root->val);
            return NULL;
        }

        root->left = remove(root->left, leaves);
        root->right = remove(root->right, leaves);
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
};


int main()
{
    Solution s;
    TreeNode *T = s.createBiTree(T);
    vector<vector<int>> rt = s.findLeaves(T);
    for(int i = 0; i < rt.size(); i++)
    {
    	for(int j = 0; j < rt[i].size(); j++)
    	{
    		cout << rt[i][j] << ' ';
		}
		cout << endl;
	}
}
