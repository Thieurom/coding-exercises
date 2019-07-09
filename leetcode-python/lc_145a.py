#
# LeetCode
# 145. Binary Tree Postorder Traversal
# https://leetcode.com/problems/binary-tree-postorder-traversal/
# Recursive solution
#

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        if not root:
            return []

        values = []

        if root.left:
            values.extend(self.postorderTraversal(root.left))

        if root.right:
            values.extend(self.postorderTraversal(root.right))

        values.append(root.val)

        return values
