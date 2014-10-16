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
    ListNode *swapPairs(ListNode *head) {
        // safeguard.
        ListNode *p = new ListNode(INT_MIN);
        p->next = head;

        head = p;
        while (true)
        {
            if (p->next == NULL) {
                break;
            }
            if (p->next->next == NULL)
            {
                break;
            }

            ListNode *q1 = p->next;
            ListNode *q2 = p->next->next;

            q1->next = q2->next;
            q2->next = q1;

            p->next = q2;
            p = q1;
        }
        return head->next;
    }

};