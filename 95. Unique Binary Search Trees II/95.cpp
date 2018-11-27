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
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)
            return generate(1,0);
        else
            return generate(1,n);
    }

	vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        inorder(root,nodes);
        return nodes;
    }
    
private:
    vector<TreeNode*> generate(int start, int end)
    {
        vector<TreeNode*> subTree;
        if(start > end)
        {
            subTree.push_back(NULL);
            return subTree;
        }
        for(int k = start; k <= end; k++)
        {
            vector<TreeNode*> leftSubs = generate(start,k-1);
            vector<TreeNode*> rightSubs = generate(k+1,end);
            for(int i = 0; i < leftSubs.size(); i++)
                for(int j = 0; j < rightSubs.size(); j++)
                {
                    TreeNode *root = new TreeNode(k);
                    root->left = leftSubs[i];
                    root->right = rightSubs[j];
                    subTree.push_back(root);
                }
        }
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
};

int main()
{
	Solution *s = new Solution;
	vector<TreeNode*> root = s->generateTrees(3);
	vector<int> traversal;
	for(int i = 0; i < root.size(); i++)
	{
		traversal = s->inorderTraversal(root[i]);
		for(int j = 0; j < traversal.size(); j++)
			cout<<traversal[j]<<' ';
		cout<<endl;
	}
	cout<<root.size()<<endl;
	return 0;
}
	
