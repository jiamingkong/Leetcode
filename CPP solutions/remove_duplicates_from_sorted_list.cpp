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
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head) return NULL;
        ListNode *last = head;
        ListNode *now  = head->next;

        while (now)
        {
            if (last->val == now->val)
            {
                now = now->next;
                last->next = now;
                continue;
            }

            last = last->next;
            now = now->next;
        }

        return head;
    }
};