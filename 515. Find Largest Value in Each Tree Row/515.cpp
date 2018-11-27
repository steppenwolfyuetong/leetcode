#include <queue>
#include <vector>
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> rt;
        if(root == NULL)
            return rt;

        queue<TreeNode*> cur, next;
        cur.push(root);

        int curMax = INT_MIN;
        while(!cur.empty())
        {
            TreeNode* node = cur.front();
            if(node->left)
                next.push(node->left);
            if(node->right)
                next.push(node->right);
            if(node->val > curMax)
                curMax = node->val;
            cur.pop();

            if(cur.empty())
            {
                rt.push_back(curMax);
                swap(cur, next);
                curMax = INT_MIN;
            }
        }
        return rt;
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
    vector<int> result = s->largestValues(T);
    for(auto num : result)
        cout << num << ' ';
    cout << endl;
    return 0;
}
