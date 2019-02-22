/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // Two nodes of a binary tree are cousins if they have the same depth, but have different parents.
    bool isCousins(TreeNode* root, int x, int y) {
        if (root == nullptr) {
            return false;
        }

        queue<TreeNode*> curLevel, nextLevel;
        curLevel.push(root);
        int xIndex = 0, yIndex = 0;               // indicate x and y node index of in some level

        while (!curLevel.empty()) {
            int count = 0;
            while (!curLevel.empty()) {
                TreeNode *node = curLevel.front();
                curLevel.pop();
                count++;
                if (node->left) {
                    if (node->left->val == x) {
                        xIndex = count;
                    } else if (node->left->val == y) {
                        yIndex = count;
                    }
                    nextLevel.push(node->left);
                }
                if (node->right) {
                    if (node->right->val == x) {
                        xIndex = count;
                    } else if (node->right->val == y) {
                        yIndex = count;
                    }
                    nextLevel.push(node->right);
                }
            }
            
            if (xIndex && yIndex) {
                return xIndex == yIndex ? false : true;
            } else if (xIndex || yIndex) {
                return false;
            }
            swap(curLevel, nextLevel);
        }
        return false;
    }

};
