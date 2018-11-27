/*
 * Given a non-negative number represented as a singly linked list of digits, plus one to the number.
 * The digits are stored such that the most significant digit is at the head of the list.
 *
 * Example:
 * Input:
 * 1->2->3
 * Output:
 * 1->2->4
 */

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{  
public:  
    /*
    int DFS(ListNode* head)  
    {  
        int flag = 0;  
        if(!head->next) flag = 1;  
        else flag = DFS(head->next);  
        int val = head->val+flag;  
        head->val = val%10;  
        flag = val/10;  
        return flag;  
    }  
      
    ListNode* plusOne(ListNode* head) {  
        if(!head) return head;  
        if(DFS(head)==0) return head;  
        ListNode* p = new ListNode(1);  
        p->next = head;  
        return p;  
    }  
    */

    ListNode* plusOne(ListNode* head) 
    {
        if(head == NULL)
            return head;

        head = reverse(head);
        ListNode *cur = head;
        int carry = (cur->val + 1) / 10;
        cur->val = (cur->val + 1) % 10;

        while(cur && carry)
        {
            if(cur->next == NULL)
            {
                cur->next = new ListNode(1);
                break;
            }
            else
            {
                cur = cur->next;
                carry = (cur->val + 1) / 10;
                cur->val = (cur->val + 1) % 10;
            }
        }

        return reverse(head);
    }

    ListNode* reverse(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
            return head;

        ListNode *pre = NULL, *cur = head, *next = head->next;
        while(cur)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        free(cur);
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
	Solution *s = new Solution;
	ListNode a1(9), a2(0), a3(9);
	ListNode *a = &a1;
	a1.next = &a2;
	a2.next = &a3;

    s->display(a);
    s->display(s->plusOne(a));
}
