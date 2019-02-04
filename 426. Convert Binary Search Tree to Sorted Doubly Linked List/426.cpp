/*
Convert a BST to a sorted circular doubly-linked list in-place.  Think of the left and right pointers as synonymous to the previous and next pointers in a doubly-linked list.
We want to transform this BST into a `circular doubly linked list`.  Each node in a doubly linked list has a predecessor and successor.  For a circular doubly linked list, the predecessor of the first element is the last element, and the successor of the last element is the first element.
*/

// BST转换为循环双向链表
//
// 本质为中序遍历, see leetcode 109


class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        Node dummy(0);
        pre = &dummy;                           // dummy->right points to head
        inorder(root, &pre);

        pre->right = dummy->right;              // after inorder traverse, pre becomes the tail
        dummy->right->left = pre;
        return dummy->right;
    }

    void inorder(Node* cur) {
        if (cur == nullptr) {
            return;
        }

        inorder(cur->left);
        pre->right = cur;
        cur->left = pre;
        pre = cur;
        inorder(cur->right);
    }
private:
    Node *pre = nullptr;
};
