#
# LeetCode
# 144. Binary Tree Preoreder Traversal
# https://leetcode.com/problems/binary-tree-preorder-traversal/
# Recursive solution
#

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        
        values = [root.val]
        
        if root.left:
            values.extend(self.preorderTraversal(root.left))
        if root.right:
            values.extend(self.preorderTraversal(root.right))
        
        return values
