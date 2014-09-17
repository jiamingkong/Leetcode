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
    bool hasCycle(ListNode *head) {
        /** the solution is to use two pointer. One of it goes two steps each time, while the other one proceeds as usual.
         * For example the linked list goes like 1->2->3->4->1. The first pointer will go : 1->3->1->3->1, the second one goes 1 2 3 4 1, and they met after some cycles.
         * If the linked list has no cycle, one of the pointers will reach NULL and stop the algo.
		 */

		if(head == NULL) return false;

		ListNode *slow = head;
		ListNode *fast = slow->next;

		while(fast != NULL && slow != NULL)
		{
			if(fast == slow) return true; // pointers met.
			step(slow);
			step(fast);
			if(fast == NULL) return false; // reaching the end of the list;
			step(fast); // jump again.
		}

    }

    void step(ListNode *&ptr)
    {
    	ptr = ptr->next;
    }
};