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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)
            return NULL;

        TreeNode *cur = root, *pre = NULL;
        while(cur != NULL && cur->val != key)
        {
            pre = cur;
            if(cur->val < key)
                cur = cur->right;
            else
                cur = cur->left;
        }

        if(pre == NULL)
        {
            return organize(cur);
        }

        if(pre->left == cur)
        {
            pre->left = organize(cur);
        }
        else
        {
            pre->right = organize(cur);
        }
        return root;
    }

    TreeNode* organize(TreeNode *node)
    {
        if(node == NULL)
            return NULL;
        // 左右子树若有为空返回另一个
        if(node->left == NULL)
            return node->right;
        if(node->right == NULL)
            return node->left;

        // 左右子树均不为空
        TreeNode *newRoot = node->right;            // 以原先的右孩子为根节点 并将原先的左子树找到合适位置插入即可
        TreeNode *cur = newRoot->left;              // 原来的左子树也一定在新的左子树上 且一定是leftmost
        TreeNode *pre = newRoot;
        while(cur)
        {
            pre = cur;
            cur = cur->left;
        }
        pre->left = node->left;
        delete node;
        return newRoot;
    }
};

int main()
{
}
