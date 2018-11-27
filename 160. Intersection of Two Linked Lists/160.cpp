/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* getIntersectionNodeNormal(ListNode* headA, ListNode *headB)
    {
        //常规方法是 先各自遍历两个链表一次 获取两个链表的长度
        //然后使两个指针分别指向头节点，并移动其中一个指针，使得两个指针距离尾部的距离相同
        //然后两个指针同时前行，直到两个指针相等返回
        int lenA = getLinkedListLength(headA);
        int lenB = getLinkedListLength(headB);

        ListNode *pLongList = (lenA > lenB) ? headA : headB;
        ListNode *pShortList = (lenA < lenB) ? headA : headB;

        for(int i = 0; i < abs(lenA - lenB); i++)
        {
            pLongList = pLongList->next;
        }

        while(pLongList != NULL && pShortList != NULL && pLongList != pShortList)
        {
            pLongList = pLongList->next;
            pShortList = pShortList->next;
        }
        return pLongList;
    }

    int getLinkedListLength(ListNode* pHead)
    {
        int len = 0;
        while(pHead != NULL)
        {
            len++;
            pHead = pHead->next;
        }
        return len;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //而下面的方法不需要知道链表的长度
        //核心思想也是两次遍历
        //假设len(headA) = a, len(headB) = b
        //当遍历完A链表，使其指向B，另一个指针遍历完B，则指向A
        //a + b = b + a,达到同样的效果
        /* 1.
         * 如果有重合部分,当两个指针为NULL时，均指向另一个链表头
         * 这样两个指针距离重合点的距离相同
         * 2.
         * 如果没有重合部分，则经过两次遍历，两个指针都指向NULL
         */
        ListNode *p1 = headA;
        ListNode *p2 = headB;
        while(p1 != p2)
        {
            p1 = p1 ? p1->next : headB;
            p2 = p2 ? p2->next : headA;
        }
        return p1;
    }
};
