#include<malloc.h>
#include<stack>
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
    // 二叉树转换为单链表
    // right指针指向下一个元素
	/*
	// 先序遍历 栈
    void flatten(TreeNode* root) {
        if(!root)
            return;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode *p = s.top();
			s.pop();
            if(p->right)
                s.push(p->right);
            if(p->left)
                s.push(p->left);
            p->left = NULL;
            if(!s.empty())
                p->right = s.top();
        }
		return;
    }
	*/
	
	
	// 迭代 对于某一根节点 找到其左子树中序遍历中 根节点之前的那个节点
	// 将其right指向root->right
	// 然后将root->right指向root->left
	// 即将右子树嫁接到左子树之后
	void flatten(TreeNode* root) {
		while(root)
		{
			if(root->left)
			{
				TreeNode *pre = root->left;
				while(pre->right)
					pre = pre->right;
				pre->right = root->right;
				root->right = root->left;
			}
			root->left = NULL;
			root = root->right;
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
	Solution *s = new Solution;
	TreeNode *T = s->createBiTree(T);
	s->flatten(T);
    while(T)
    {
        cout<<T->val<<endl;
        T = T->right;
    }
	return 0;
}
