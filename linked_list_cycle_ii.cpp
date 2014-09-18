/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (!head) return NULL;

        ListNode *fast = head;
        ListNode *slow = head;

        while (fast != NULL)
        {
            step(fast); step(slow);
            if (fast != NULL)
            {
                step(fast);
            }

            if (fast == slow) break;
        }

        if (fast == NULL) return NULL;

        fast = head;
        while (fast != slow)
        {
            step(fast); step(slow);
        }
        return fast;
    }

    inline void step(ListNode *&ptr)
    {
        ptr = ptr->next;
    }
};