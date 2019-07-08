#
# LeetCode
# 144. Binary Tree Preoreder Traversal
# https://leetcode.com/problems/binary-tree-preorder-traversal/
# Iterative solution
#

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        values = []
        stack = [root]
        
        while len(stack) > 0:
            node = stack.pop()
            
            if node:
                values.append(node.val)
                if node.right:
                    stack.append(node.right)
                if node.left:
                    stack.append(node.left)
        
        return values
