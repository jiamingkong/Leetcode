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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // Form another list with length of n to always keep the last n nodes encountered, delete the head of it while you reach the end.
        if (!head) return NULL;

        ListNode *slow, *fast;
        fast = head; slow = head;

        int step = 0;
        while (fast && step < n)
        {
            fast = fast->next;
            step++;
        }

        if (fast == NULL)
        {
            head = head->next;
            return head;
        }
        while (fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode *temp = slow->next;
        slow->next = temp->next;
        delete temp;
        return head;
    }
};