
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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode *oddHead = head, *evenHead = head->next;
        ListNode *odd = oddHead, *even = evenHead;
        while(even && even->next)
        {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return oddHead;
    }
};

#include <vector>
int main()
{
	ListNode a1(1),a2(2),a3(3),a4(4),a5(5);
	a1.next = &a2; a2.next = &a3; a3.next = &a4; a4.next = &a5;

	Solution *s = new Solution;

    ListNode *cur = s->oddEvenList(&a1);
    while(cur)
    {
        cout << cur->val << ' ';
        cur = cur->next;
    }
    cout << endl;
    
    vector<int> a(a,,)
    
    return 0;
}
