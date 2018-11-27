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
#include <unordered_map>
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
    //O(1)
    vector<int> findMode(TreeNode* root) {
        vector<int> rt;
        if(root == NULL)
            return rt;

        int pre = root->val;
        int count = 0, maxCount = 0;
        inorder(root, rt, pre, count, maxCount);
        return rt;
    }

    void inorder(TreeNode *root, vector<int> &result, int &pre, int &count, int &maxCount)
    {
        if(root == NULL)
            return;
        inorder(root->left, result, pre, count, maxCount);

        if(pre == root->val)
        {
            count++;
        }
        else
        {
            pre = root->val;
            count = 1;
        }

        if(count > maxCount)
        {
            result.clear();
            result.push_back(pre);
            maxCount = count;
        }
        else if(count == maxCount)
        {
            result.push_back(pre);
        }

        inorder(root->right, result, pre, count, maxCount);
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
    vector<int> rt = s.findMode(T);
    for(auto num : rt)
        cout << num << endl;
    return 0;
}
