#include <malloc.h>
#include <vector>
#include <cstdlib>
#include <iostream>
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
    // 二叉搜索树的创建
    TreeNode* insertNode(TreeNode *node, int value)
    {
        if(node == NULL)
        {
            node = new TreeNode(value);
        }
        else if(node->val < value)
        {
            node->right = insertNode(node->right, value);
        }
        else
        {
            node->left = insertNode(node->left, value);
        }
        return node;
    }

    // 递归实现
    // 原先指向左子结点的指针调整为链表中指向前一个结点的指针，原先指向右子结点的指针调整为链表中指向下一个结点的指针。
    // 用last保存已经转换成双向链表的最后一个节点
    // 递归调用即可
    TreeNode* Convert(TreeNode *root)
    {
        if(root == NULL)
        {
            return NULL;
        }

        TreeNode *head = findLeftMostNode(root);
        TreeNode *last = NULL;
        ConvertNode(root, &last);
        return head;
    }
private:
    TreeNode* findLeftMostNode(TreeNode *node)
    {
        if(node == NULL)
        {
            return NULL;
        }

        while(node->left != NULL)
        {
            node = node->left;
        }
        return node;
    }

    // 中序遍历！！！
    void ConvertNode(TreeNode *node, TreeNode **pre)
    {
        if(node == NULL)
        {
            return;
        }

        // 转换左子树
        if(node->left != NULL)
        {
            ConvertNode(node->left, pre);
        }

        // 转换根节点
        node->left = *pre;
        if(*pre != NULL)
        {
            (*pre)->right = node;
        }
        
        // 转换右子树
        *pre = node;
        if(node->right != NULL)
        {
            ConvertNode(node->right, pre);
        }
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        inorder(root,nodes);
        return nodes;
    }
private:
    void inorder(TreeNode* root, vector<int>& nodes)
    {
        if(root == NULL)
            return;
        inorder(root->left,nodes);
        nodes.push_back(root->val);
        inorder(root->right,nodes);
        return;
    }
public:
    void traversalDoubleLinkedList(TreeNode *pHead)
    {
        TreeNode *node = pHead;
        for(; node->right != NULL; node = node->right)
        {
            cout << node->val << ' ';
        }
        cout << node->val << ' ';
        cout << endl;
        for(; node->left != NULL; node = node->left)
        {
            cout << node->val << ' ';
        }
        cout << node->val << ' ';
        cout << endl;
        return;
    }
};

int main()
{
    Solution *s = new Solution();

    TreeNode *root = NULL;
    for(int i = 0; i < 10; i++)
    {
        int val = rand() % 100;
        root = s->insertNode(root, val);
    }
	
	
    vector<int> values = s->inorderTraversal(root);
    for(int i = 0; i < values.size(); i++)
    {
        cout << values[i] << ' ';
    }
    cout << endl;
	
    TreeNode *pHead = s->Convert(root);

    s->traversalDoubleLinkedList(pHead);
	
    return 0;
}
