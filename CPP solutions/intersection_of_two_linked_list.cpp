/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// need a function to run to the end of the linked list and return length.


class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int length_A = length(headA);
        int length_B = length(headB);
        if (length_A > length_B)
        {
            int step = length_A - length_B;
            for (int i = 0; i < step; i++)
            {
                headA = headA->next;
            }
        }
        else if (length_A < length_B)
        {
            int step = length_B - length_A;
            for (int i = 0; i < step; i++)
            {
                headB = headB->next;
            }
        }

        // now step together

        while(headA != NULL && headB != NULL)
        {
        	if (headA == headB)
        	{
        		return headA;
        	}
        	else
        	{
        		headA = headA->next;
        		headB = headB->next;
        	}
        }
        return NULL;
    }

    int length(ListNode *head)
    {
        int result = 0;
        ListNode *ptr;
        ptr = head;

        while (ptr != NULL)
        {
            ptr = ptr->next;
            result++;
        }
        return result;
    }
};