#
# LeetCode
# 94. Binary Tree Inorder Traversal
# https://leetcode.com/problems/binary-tree-inorder-traversal/
# Recursive solution
#

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        
        values = []
        if root.left:
            values.extend(self.inorderTraversal(root.left))
            
        values.append(root.val)
        
        if root.right:
            values.extend(self.inorderTraversal(root.right))
            
        return values
