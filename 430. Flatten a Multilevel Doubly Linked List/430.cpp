/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        Node *cur = head, *pre = nullptr;               // pre is last valid node
        stack<Node*> preLevel;                          // preLevel store the next valid node of previous level
        while (cur || !preLevel.empty()) {
            if (cur == nullptr) {
                cur = preLevel.top();
                preLevel.pop();
                cur->prev = pre;
                if (pre != nullptr) {
                    pre->next = cur;
                }
            }

            if (cur->child) {
                if (cur->next != nullptr) {
                    preLevel.push(cur->next);
                }
                cur->next = cur->child;
                cur->child->prev = cur;
                cur->child = nullptr;
            }
            pre = cur;
            cur = cur->next;
        }
    }
};
