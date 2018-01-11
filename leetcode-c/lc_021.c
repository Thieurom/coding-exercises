//
// LeetCode
// 21. Merge Two Sorted Lists
// https://leetcode.com/problems/merge-two-sorted-lists/
//


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy = { 0, NULL };
    struct ListNode* head = &dummy;
    struct ListNode* cursor = &dummy;
    
    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            cursor->next = l1;
            l1 = l1->next;
        } else {
            cursor->next = l2;
            l2 = l2->next;
        }
        
        cursor = cursor->next;
    }
    
    if (l1 != NULL)
        cursor->next = l1;
    
    if (l2 != NULL)
        cursor->next = l2;
    
    return head->next;
}
