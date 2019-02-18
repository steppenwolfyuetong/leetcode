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
    vector<int> preorder(Node* root) {
        vector<int> result;
        preorder(root, result);
        return result;
    }
private:
    void preorder(Node* root, vector<int>& result) {
        if (root == nullptr) {
            return;
        }
        result.emplace_back(root->val);
        for (const auto& child : root->children) {
            preorder(child, result);
        }
    }
};
