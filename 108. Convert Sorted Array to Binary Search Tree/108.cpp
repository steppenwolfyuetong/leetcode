#include<malloc.h>
#include<stack>
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
    TreeNode* sortedArrayToBST(vector<int>& num) {
        return sortedArrayToBST(num.begin(),num.end());
    }
    
    TreeNode* sortedArrayToBST(vector<int>::iterator begin, vector<int>::iterator end)
	{
		int length = end - begin;
		if(length <= 0)
			return NULL;
		vector<int>::iterator mid = begin + length / 2;
		TreeNode* root = new TreeNode(*mid);
		root->left = sortedArrayToBST(begin,mid);
		root->right = sortedArrayToBST(mid+1,end);
		return root;	
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
	
	vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        inorder(root,nodes);
        return nodes;
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
	int a[] = {1,2,3,4,5,6,7,8,9};
	vector<int> num;
	for(int i = 0; i < 9; i++)
		num.push_back(a[i]);
	Solution *s = new Solution;
	TreeNode *T = s->sortedArrayToBST(num);
	vector<int> traversal = s->preorderTraversal(T);
	for(int i = 0; i < traversal.size(); i++)
		cout<<traversal[i];
	cout<<endl;
	traversal = s->inorderTraversal(T);
	for(int i = 0; i < traversal.size(); i++)
		cout<<traversal[i];
    return 0;
}
