//
// LeetCode
// 21. Merge Two Sorted Lists
// https://leetcode.com/problems/merge-two-sorted-lists/
//


/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
    dummy := &ListNode{}
    cursor := dummy

    for l1 != nil && l2 != nil {
        if l1.Val < l2.Val {
            cursor.Next = l1
            l1 = l1.Next
        } else {
            cursor.Next = l2
            l2 = l2.Next
        }

        cursor = cursor.Next
    }

    if l1 != nil {
        cursor.Next = l1
    }

    if l2 != nil {
        cursor.Next = l2
    }

    return dummy.Next
}
