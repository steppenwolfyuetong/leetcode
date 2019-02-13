#include<malloc.h>
#include<stack>
#include<vector>
#include<iostream>
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
	/*
	// 递归
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
	*/
	
    
	// 栈 
	vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> nodes;
        TreeNode *cur = root;
        while(cur || !nodes.empty())
        {
            if(cur)
            {
                result.push_back(cur->val);
                //这个if可以不要
				if(cur->right)
                    nodes.push(cur->right);
                cur = cur->left;
            }
            else
            {
                cur = nodes.top();
                nodes.pop();
            }
        }
        return result;
    }
	

	/*
    // Morris遍历
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode *cur = root, *pre = NULL;
        vector<int> result;
        while(cur != NULL)
        {
            // 如果当前节点的左孩子为空，则输出当前节点并将其右孩子作为当前节点
            if(cur->left == NULL)
            {
                result.push_back(cur->val);
                cur = cur->right;
            }
            else
            {
                // 如果当前节点的左孩子不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点。
                pre = cur->left;
                while(pre->right && pre->right != cur)
                    pre = pre->right;
                // 如果前驱节点的右孩子为空，将它的右孩子设置为当前节点。 
                // 输出当前节点（在这里输出，这是与中序遍历唯一一点不同）。当前节点更新为当前节点的左孩子。
                if(pre->right == NULL)
                {
                    pre->right = cur;
                    result.push_back(cur->val);
                    cur = cur->left;
                }
                // 如果前驱节点的右孩子为当前节点，将它的右孩子重新设为空。当前节点更新为当前节点的右孩子。
                else
                {
                    pre->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return result;
    }	
	*/
	
	TreeNode* createBiTree(TreeNode *T) {
		int val;
		cin >> val;
		if(val == 0) {
			return NULL;
        } else {
            T = new TreeNode(val);
			T->left = createBiTree(T->left);
			T->right = createBiTree(T->right);
			return T;
		}
	}
};

int main()
{
	Solution *s = new Solution;
	TreeNode *T = s->createBiTree(T);
	vector<int> result = s->preorderTraversal(T);
	for(int i = 0; i < result.size(); i++)
		cout<<result[i]<<endl;
	return 0;
}
