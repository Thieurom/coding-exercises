#
# LeetCode
# 160. Intersection of Two Linked Lists
# https://leetcode.com/problems/intersection-of-two-linked-lists/
#

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        def length(head):
            length = 0
            while head:
                length += 1
                head = head.next
                
            return length
        
        length_a = length(headA)
        length_b = length(headB)
        
        if length_b > length_a:
            headA, headB = headB, headA # headA points to longer list
            
        for _ in range(abs(length_a - length_b)):
            headA = headA.next
            
        while headA and headB and headA is not headB:
            headA = headA.next
            headB = headB.next
            
        return headA
