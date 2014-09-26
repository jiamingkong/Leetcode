# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    # @param root, a tree node
    # @return a list of integers

    def inorderTraversal(self, root):
        result = []
        if root:
            self.traverse(result, root)
        return result

    def traverse(self, result, root):
        if root.left is not None:
            self.traverse(result, root.left)
        result.append(root.val)
        if root.right is not None:
            self.traverse(result, root.right)
