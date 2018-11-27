/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *next = node->next;
        *node = *next;
        delete next;
    }
};

int main()
{
	ListNode a1(1),a2(2),a3(3),a4(4);
	a1.next = &a2; a2.next = &a3; a3.next = &a4;
	Solution *s = new Solution;
    s->deleteNode(&a3);

    ListNode *cur = &a1;
    while(cur)
    {
        cout << cur->val << ' ';
        cur = cur->next;
    }
    cout << endl;
    return 0;
}
