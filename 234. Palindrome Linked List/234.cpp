#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return true;
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next)       //找到中点前的一个结点
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = reverse(slow->next);           //翻转后一半
        //display(head);

        ListNode *p = head, *q = slow->next;        //由于和链表长度奇偶有关
        while(q)
        {
            if(p->val != q->val)
                return false;
            p = p->next;
            q = q->next;
        }
        slow->next = reverse(slow->next);           //恢复后一半链表
        //display(head);
        return true;
    }

    ListNode* reverse(ListNode *head)
    {
        ListNode *pre = NULL, *cur = head, *next = head->next;
        while(cur)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

    void display(ListNode *head)
    {
        while(head)
        {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
};


int main()
{
	ListNode a1(1),a2(2),a3(3),a4(3),a5(2),a6(1);
	a1.next = &a2; a2.next = &a3; a3.next = &a4; a4.next = &a5; a5.next = &a6;
	Solution *s = new Solution;
    cout << s->isPalindrome(&a1) << endl;
}
