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
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        dfs(cur, moves);
        return moves;
    }

    // 返回该节点多余或缺少的金币数
    int dfs(TreeNode* cur, int& moves) {
        if (cur == nullptr) {
            return 0;
        }
        int left = dfs(cur->left);
        int right = dfs(cur->right);
        moves += abs(left) + abs(right);            // 统计需要move多少次
        return left + right + cur->val - 1;         // 每个节点消耗一枚金币
    }
};
