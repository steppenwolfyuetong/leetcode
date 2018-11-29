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
    int maxDepth(Node* root) {
        if (root == nullptr) {
            return 0;
        }

        int result = 1;
        for (auto node : root->children) {
            result = max(result, 1 + maxDepth(node));
        }
        return result;
    }
};
