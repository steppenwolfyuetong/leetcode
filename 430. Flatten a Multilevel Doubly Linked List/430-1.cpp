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
        for (Node *cur = head; cur; cur = cur->next) {
            if (cur->child) {
                Node *preLevel = cur->next;         // preLevel is the next node of cur level

                // connect cur and its child
                cur->next = cur->child;
                cur->child->prev = cur;
                cur->child = nullptr;

                // find the tail of child list, and connect it with preLevel
                Node *nextLevel = cur->next;
                while (nextLevel->next) {
                    nextLevel = nextLevel->next;
                }
                nextLevel->next = preLevel;
                if (preLevel) {
                    preLevel->prev = nextLevel;
                }
            }
        }
        return head;
    }
};
