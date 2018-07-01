//
// LeetCode
// 2. Add Two Numbers
// https://leetcode.com/problems/add-two-numbers
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
    func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        let node = ListNode(0)
        var nextNode = node
        var carry = 0
        var l1 = l1
        var l2 = l2
        
        while l1 != nil || l2 != nil {
            var sum = carry
            
            if l1 != nil {
                sum += l1!.val
                l1 = l1!.next
            }
            
            if l2 != nil {
                sum += l2!.val
                l2 = l2!.next
            }
            
            nextNode.next = ListNode(sum % 10)
            nextNode = nextNode.next!
            carry = sum / 10
        }
        
        if carry > 0 {
            nextNode.next = ListNode(carry)
            nextNode = nextNode.next!
        }
        
        return node.next
    }
}
