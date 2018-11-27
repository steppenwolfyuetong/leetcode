
/*
 * Given a binary tree where all the right nodes are 
 * either leaf nodes with a sibling (a left node that shares the same parent node) or empty,
 * flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes.
 * Return the new root.
    For example:
    Given a binary tree {1,2,3,4,5},
        1
       / \
      2   3
     / \
    4   5
    return the root of the binary tree [4,5,2,#,#,3,1].
       4
      / \
     5   2
        / \
       3   1  
 */

#include <stack>
#include <vector>
#include <iostream>
#include <malloc.h>
using namespace std;

struct TreeNode { 
    int val; 
    TreeNode *left; 
    TreeNode *right; 
    TreeNode(int x) : val(x), left(NULL), right(NULL) {} 
};

class Solution 
{
public:
    //递归
    //把左子树继续颠倒，颠倒完之后，
    //原来的左孩子的左右孩子指针分别指向原来的根节点以及原来的右兄弟节点
    //自底向上
    /*
    TreeNode* upsideDownBinaryTree(TreeNode *root)
    {
        if(!root || !root->left)
            return root;
        TreeNode *left = root->left, *right = root->right;
        TreeNode *rt = upsideDownBinaryTree(left);
        left->left = right;
        left->right = root;
        root->left = NULL;
        root->right = NULL;
        return rt;
    }
    */

    TreeNode* upsideDownBinaryTree(TreeNode *root)
    {
        TreeNode *cur = root, *parent = NULL, *left = NULL, *right = NULL;
        while(cur)      //cur是parent的左子树
        {
            //保存当前节点的左右孩子
            left = cur->left;
            right = cur->right;
            //左孩子的左右孩子指针分别指向原来的根节点以及原来的右兄弟节点
            cur->left = right;
            cur->right = parent;
            parent = cur;
            cur = left;
        }
        return parent;
    }

    TreeNode* createBiTree(TreeNode *T)
	{
		int val;
		cin >> val;
		if(val == 0)
			return NULL;
		else
		{
			if(!(T = (TreeNode *) malloc(sizeof(TreeNode))))
				cout << "Failure" << endl;
			T->val = val;
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
	Solution *s = new Solution;
	TreeNode *T = s->createBiTree(T);
    TreeNode *result = s->upsideDownBinaryTree(T);
    vector<int> pre = s->preorderTraversal(result);
    for(int i = 0; i < pre.size(); i++)
    {
        cout << pre[i] << ' ';
    }
    cout << endl;
	return 0;
}
