# ERR : TLE for a big dataset.


# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#         self.next = None


class Solution:
    # @param root, a tree node
    # @return nothing

    def link(self, root):
        if root is None:
            return

        if root.next is None:
            if root.next is not None:
                root.right.next = None

            if root.left is not None:
                root.left.next = root.right

        else:

            p = root.next
            q = None
            while p is not None:
                if p.left is not None:
                    q = p.left
                    break

                if p.right is not None:
                    q = p.right
                    break

                p = p.next

            if root.right is not None:
                root.right.next = q

            if root.left is not None and root.right is not None:
                root.left.next = root.right

            if root.left and not root.right:
                root.left.next = q

        self.link(root.right)
        self.link(root.left)

    def connect(self, root):
        if root is None:
            return

        self.link(root)
