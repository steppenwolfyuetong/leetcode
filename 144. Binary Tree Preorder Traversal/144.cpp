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
	// �ݹ�
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
	
    
	// ջ 
	vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> nodes;
        TreeNode *cur = root;
        while(cur || !nodes.empty())
        {
            if(cur)
            {
                result.push_back(cur->val);
                //���if���Բ�Ҫ
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
    // Morris����
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode *cur = root, *pre = NULL;
        vector<int> result;
        while(cur != NULL)
        {
            // �����ǰ�ڵ������Ϊ�գ��������ǰ�ڵ㲢�����Һ�����Ϊ��ǰ�ڵ�
            if(cur->left == NULL)
            {
                result.push_back(cur->val);
                cur = cur->right;
            }
            else
            {
                // �����ǰ�ڵ�����Ӳ�Ϊ�գ��ڵ�ǰ�ڵ�����������ҵ���ǰ�ڵ�����������µ�ǰ���ڵ㡣
                pre = cur->left;
                while(pre->right && pre->right != cur)
                    pre = pre->right;
                // ���ǰ���ڵ���Һ���Ϊ�գ��������Һ�������Ϊ��ǰ�ڵ㡣 
                // �����ǰ�ڵ㣨������������������������Ψһһ�㲻ͬ������ǰ�ڵ����Ϊ��ǰ�ڵ�����ӡ�
                if(pre->right == NULL)
                {
                    pre->right = cur;
                    result.push_back(cur->val);
                    cur = cur->left;
                }
                // ���ǰ���ڵ���Һ���Ϊ��ǰ�ڵ㣬�������Һ���������Ϊ�ա���ǰ�ڵ����Ϊ��ǰ�ڵ���Һ��ӡ�
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
