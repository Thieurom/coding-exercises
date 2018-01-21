//
// LeetCode
// 21. Merge Two Sorted Lists
// https://leetcode.com/problems/merge-two-sorted-lists/
//


/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public var val: Int
 *     public var next: ListNode?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.next = nil
 *     }
 * }
 */

class Solution {
    func mergeTwoLists(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        let dummyNode = ListNode(0)
        var cursorNode = dummyNode
        var node1 = l1
        var node2 = l2

        while node1 != nil && node2 != nil {
            if node1!.val < node2!.val {
                cursorNode.next = node1
                node1 = node1!.next
            } else {
                cursorNode.next = node2
                node2 = node2!.next
            }
            cursorNode = cursorNode.next!
        }

        cursorNode.next = node1 ?? node2

        return dummyNode.next
    }
}
