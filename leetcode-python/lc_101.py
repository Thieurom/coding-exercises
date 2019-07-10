#
# LeetCode
# 101. Symmetric Tree
# https://leetcode.com/problems/symmetric-tree/
#

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if root is None:
            return True
        
        return self.isMirror(root.left, root.right)
    
    def isMirror(self, a: TreeNode, b: TreeNode) -> bool:
        if a is None and b is None:
            return True
        
        if (a is None and b is not None) or (a is not None and b is None):
            return False
        
        if a.val != b.val:
            return False

        return self.isMirror(a.left, b.right) and self.isMirror(a.right, b.left)
