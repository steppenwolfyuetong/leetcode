#include<limits.h>
#include<malloc.h>
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
	// 递归 由于边界值 不能仅使用IMT_MIN和INT_MAX 容易出错
	/*
    bool isValidBST(TreeNode* root) {
        return isValidBST(root,LLONG_MIN,LLONG_MAX);
    }

    bool isValidBST(TreeNode* root, long long lower, long long upper)
    {
        if(root == NULL)
            return true;
        if(root->val <= lower || root->val >= upper)
			return false;
        if(!isValidBST(root->left, lower, root->val) || !isValidBST(root->right, root->val, upper))
			return false;
        return true;
    }
    */
	
	// 基于中序遍历 不存在边界问题
	// pre为中序遍历当前节点的前一个节点
	bool isValidBST(TreeNode* root) {
		TreeNode *pre = NULL;
		return validate(root,pre);
	}
	
	bool validate(TreeNode* node, TreeNode* &pre)
	{
		if(node == NULL)
			return true;
		if(!validate(node->left,pre))
			return false;
		if(pre != NULL && pre->val >= node->val)
			return false;
		pre = node;
		return validate(node->right,pre);
	}

    // stack
    /*
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode *cur = root, *pre = NULL;
        while(cur || !stk.empty())
        {
            if(cur)
            {
                stk.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = stk.top();
                stk.pop();
                if(pre != NULL && pre->val >= cur->val)
                    return false;
                pre = cur;
                cur = cur->right;
            }
        }
        return true;
    }
    */
	
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
    Solution *s = new Solution;
    TreeNode *T = s->createBiTree(T);
    cout<<s->isValidBST(T)<<endl;
    return 0;
}
