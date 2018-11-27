/*
Given a binary search tree and a node in it, find the in-order successor of that node in the BST.
Note: If the given node has no in-order successor in the tree, return null.
*/

/*
There are just two cases:
The easier one: p has right subtree, then its successor is just the leftmost child of its right subtree;
The harder one: p has no right subtree, then a traversal is needed to find its successor.

*/

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) 
    {
        //First case
        if(p->right)
        {
            TreeNode *cur = p->right;
            while(cur->left)
                cur = cur->left;
            return cur;
        }

        //Second Case:
        //根据BST性质找到目标节点 只有当cur->val > p->val时 cur节点可能是successor 当找到目标节点时 保存的即为结果
        TreeNode *cur = root;
        TreeNode *rt = NULL;
        while(cur)
        {
            if(cur->val > p->val)
            {
                rt = cur;
                cur = cur->left;
            }
            else if(cur->val < p->val)
            {
                cur = cur->right;
            }
            else
                break;
        }
        return rt;
    }
};
