class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        // handle corner case
        if (!isValid(root)) {
            return nullptr;
        }
        return root;
    }

    bool isValid(TreeNode* root) {
        if (root == nullptr) {
            return false;
        } 

        bool leftValid = true, rightValid = true;

        // set null to invalid branch
        if (!isValid(root->left)) {
            root->left = nullptr;
            leftValid = false;
        }
        if (!isValid(root->right)) {
            root->right = nullptr;
            rightValid = false;
        }

        // if val = 0 and both branch invalid, root itself is invalid too
        if (!leftValid && !rightValid && root->val == 0) {
            return false;
        }
        return true;
    }

    /*
    TreeNode* pruneTree(TreeNode* root) {
        if (!root) 
            return NULL;

        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if (!root->left && !root->right && root->val == 0) 
            return NULL;
        return root;
    }
    */
};
