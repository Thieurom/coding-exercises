#
# LeetCode
# 141. Linked List Cycle
# https://leetcode.com/problems/linked-list-cycle/
# Solution A: O(n) space & O(n) time
#

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        visited = {}
        node = head
        while node:
            if visited.get(node, 0) == 1:
                return True

            visited[node] = 1
            node = node.next

        return False
