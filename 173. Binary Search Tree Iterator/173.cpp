
class BSTIterator {
private:
    stack<TreeNode*> nodes;
    TreeNode *rt;
public:
    BSTIterator(TreeNode *root) {
        while(root)
        {
            nodes.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(nodes.empty())
        {
            return false;
        }
        else
        {
            TreeNode *cur = nodes.top();
            rt = cur;                       //访问中结点
            nodes.pop();
            cur = cur->right;               //访问右结点
            if(cur)                         //入栈
            {
                while(cur)
                {
                    nodes.push(cur);
                    cur = cur->left;
                }
            }
            return true;
        }
    }

    /** @return the next smallest number */
    int next() {
		return rt->val;
    }

};
