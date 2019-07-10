#
# LeetCode
# 112. Path Sum
# https://leetcode.com/problems/path-sum/
#

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        if not root:
            return False
        
        if root.val == sum and not root.left and not root.right:
            return True
        
        if root.left:
            if self.hasPathSum(root.left, sum - root.val):
                return True
            
        if root.right:
            if self.hasPathSum(root.right, sum - root.val):
                return True
            
        return False
