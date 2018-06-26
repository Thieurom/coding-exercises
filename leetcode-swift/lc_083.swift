//
// LeetCode
// 83. Remove Duplicates from Sorted List
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/
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
    func deleteDuplicates(_ head: ListNode?) -> ListNode? {
        guard let headNode = head else {
            return nil
        }
        
        var currentNode = headNode
        
        while let nextNode = currentNode.next {
            if currentNode.val == nextNode.val {
                currentNode.next = nextNode.next
            } else {
                currentNode = nextNode
            }
        }
        
        return headNode
    }
}
