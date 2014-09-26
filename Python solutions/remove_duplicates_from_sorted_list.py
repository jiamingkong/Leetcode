# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    # @param head, a ListNode
    # @return a ListNode

    def deleteDuplicates(self, head):
        if head is None:
            return

        last = head
        now = head.next

        while now:
            if last.val == now.val:
                last.next = now.next
                now = now.next
                continue

            last = last.next
            now = now.next
            # now = now.next

        return head
