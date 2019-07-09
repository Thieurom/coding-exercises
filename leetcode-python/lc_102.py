#
# LeetCode
# 102. Binary Tree Level Order Traversal
# https://leetcode.com/problems/binary-tree-level-order-traversal/
#

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        values = []
        level_nodes = [root]

        while len(level_nodes) > 0:
            level_values = [node.val for node in level_nodes if node is not None]

            if len(level_values) > 0:
                values.append(level_values)

            temp = []

            for node in level_nodes:
                if node and node.left:
                    temp.append(node.left)

                if node and node.right:
                    temp.append(node.right)

                level_nodes = temp

        return values
