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
    ListNode *rotateRight(ListNode *head, int k) {
        if(head == NULL || k == 0) return head;

        int len = 1; // that's the head
        ListNode *p = head;
        while(p->next != NULL)
        {
        	p = p->next;
        	len++;
        }

        p->next = head;
        // walked through the list, get the length of the linked list. At the end of the list, make it a cycle.
        
        k = len - k%len;
        int step = 0;
        while(step < k)
        {
        	p = p->next;
        	step++;
        }
        head = p->next;
        p->next = NULL;
        return head;
    }
};