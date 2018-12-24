/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* 
        1
   2         3
 4   5     6   7
8 9 x 11  x x x 15
   
Always make the id of left child as parent_id * 2;
Always make the id of right child as parent_id * 2 + 1;
*/

class Solution {
public:
    // bfs
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int max = 0;
        queue<pair<TreeNode*, int>> q;
        q.push(pair<TreeNode*, int>(root, 1));
        while (!q.empty()) {
            int l = q.front().second, r = l;            // right started same as left
            for (int i = 0, n = q.size(); i < n; i++) {
                TreeNode* node = q.front().first;
                r = q.front().second;
                q.pop();
                if (node->left) 
                    q.push(pair<TreeNode*, int>(node->left, r * 2));
                if (node->right) 
                    q.push(pair<TreeNode*, int>(node->right, r * 2 + 1));
            }
            max = std::max(max, r + 1 - l);
        }
        return max;
    }

    // dfs
    int widthOfBinaryTree(TreeNode* root) {
        vector<int> lefts; // left most nodes at each level;
        int maxwidth = 0;
        dfs(root, 1, 0, lefts, maxwidth);
        return maxwidth;
    }

    void dfs(TreeNode* node, int id, int depth, vector<int>& lefts, int& maxwidth) {
        if (node == nullptr) {
            return;
        }

        // add left most node
        if (depth >= lefts.size()) {
            lefts.push_back(id);
        }

        maxwidth = max(maxwidth, id - lefts[depth] + 1);
        dfs(node->left, 2 * id, depth + 1, lefts, maxwidth);
        dfs(node->right, 2 * id + 1, depth + 1, lefts, maxwidth);
    }
};
