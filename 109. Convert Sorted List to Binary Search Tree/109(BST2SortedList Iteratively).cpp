#include <stack>
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
    // 
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

    //
    TreeNode* Convert(TreeNode *root)
    {
        if(root == NULL)
        {
            return NULL;
        }

        stack<TreeNode*> stk;
        TreeNode *pHead = findLeftMostNode(root);
        TreeNode *cur = root, *pre = NULL;
        while(cur || !stk.empty())
        {
            if(cur)
            {
                cout << cur->val << " pushed" << endl;
                stk.push(cur);
                cur = cur->left;
            }
            else
            {
                cur = stk.top();
                stk.pop();

                cout << cur->val << " is cur" << endl;

                cur->left = pre;
                if(pre)
                    pre->right = cur;
                pre = cur;

                cur = cur->right;
            }
        }
        return pHead;
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
