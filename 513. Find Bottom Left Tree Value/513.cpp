#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        // Note: You may assume the tree (i.e., the given root node) is not NULL.
        int maxLevel = 0;
        int value = root->val;                  // 应对只有一个根节点的树
        helper(root, maxLevel, value, 0);
        return value;
    }

    void helper(TreeNode *root, int &maxLevel, int &value, int curLevel)
    {
        if(root == NULL)
            return;

        helper(root->left, maxLevel, value, curLevel + 1);
        helper(root->right, maxLevel, value, curLevel + 1);

        cout << curLevel << ' ' << maxLevel << endl;
        if(curLevel > maxLevel)
        {
            maxLevel = curLevel;
            value = root->val;
        }
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
    Solution *s = new Solution();
    TreeNode *T = s->createBiTree(T);
    cout << s->findBottomLeftValue(T) << endl;
    return 0;
}
