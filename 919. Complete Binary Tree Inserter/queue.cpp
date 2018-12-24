/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        this->root = root;
        q.push(root);
    }
    
    int insert(int v) {
        TreeNode *parent = nullptr;
        while(!parent) {
            TreeNode *node = q.front();
            if (!node->left) {
                parent = node;
                node->left = new TreeNode(v);
            } else if (!node->right) {
                parent = node;
                node->right = new TreeNode(v);
            } else {
                q.pop();
                q.push(node->left);
                q.push(node->right);
            }
        }
        return parent->val;
    }
    
    TreeNode* get_root() {
        return root;
    }

    TreeNode *root;
    queue<TreeNode*> q;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
