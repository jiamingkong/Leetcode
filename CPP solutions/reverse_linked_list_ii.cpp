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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        int step = n - m;
        ListNode *safeGuard  = new ListNode(INT_MIN);
        safeGuard->next = head;
        head = safeGuard;

        ListNode *pre = head;
        for (; m > 1; m--)
            pre = pre->next;

        ListNode *cur = pre->next, *post = cur->next;
        if (step >= 1)
        {
            while (step > 0 && post != NULL)
            {
                ListNode *temp = post->next;
                post->next = cur;
                cur = post;
                post = temp;
                step--;
            }

            ListNode *temp = pre->next;
            pre->next = cur;
            temp->next = post;
        }

        safeGuard = head;
        head = head->next;
        delete safeGuard;
        return head;


    }
};