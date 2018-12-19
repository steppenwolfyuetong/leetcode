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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        findParent(root);
        return bfs(target, K);
    }

    void findParent(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        if (root->left) {
            parent[root->left] = root;
            findParent(root->left);
        }
        if (root->right) {
            parent[root->right] = root;
            findParent(root->right);
        }
    }

    vector<int> bfs(TreeNode* start, int K) {
        if (K == 0) {
            return vector<int> {start->val};
        }

        queue<TreeNode*> que;
        findNeighbor(start, que);

        int dis = 1;
        while (!que.empty() && dis < K) {
            int size = que.size();
            while (size--) {
                TreeNode* node = que.front();
                que.pop();
                findNeighbor(node, que);
            }
            dis++;
        }

        vector<int> rt;
        while (!que.empty()) {
            rt.push_back(que.front()->val);
            que.pop();
        }
        return rt;
    }

    void findNeighbor(TreeNode* start, queue<TreeNode*>& que) {
        if (visited.count(start)) {
            return;
        }

        visited.insert(start);
        if (start->left && !visited.count(start->left)) {
            que.push(start->left);
        }
        if (start->right && !visited.count(start->right)) {
            que.push(start->right);
        }
        if (parent.find(start) != parent.end()) {
            if (!visited.count(parent[start])) {
                que.push(parent[start]);
            }
        }
    }

    unordered_map<TreeNode*, TreeNode*> parent;  // son -> parent
    unordered_set<TreeNode*> visited;
};

