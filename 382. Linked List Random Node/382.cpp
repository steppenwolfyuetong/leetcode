/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* head;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;        
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int rt = head->val;
        ListNode *cur = head->next;

        int i = 2;
        while(cur)
        {
            int j = rand() % i;
            if(j == 0)
            {
                rt = cur->val;
            }
            i++;
            cur = cur->next;
        }
        return rt;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */

// 蓄水池抽样
int main()
{
}
