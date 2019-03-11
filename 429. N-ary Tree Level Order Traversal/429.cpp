/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }

        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            result.emplace_back(vector<int>());
            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();
                result.back().emplace_back(node->val);
                for (const auto& child : node->children) {
                    q.push(child);
                }
            }
        }
        return result;
    }
};
