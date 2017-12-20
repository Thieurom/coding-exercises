//
// LeetCode
// 83. Remove Duplicates from Sorted List
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/
//


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* prev;
    struct ListNode* current;
    
    if (head) {
        prev = head;
        current = head->next;

        while (current != NULL) {
            if (current->val == prev->val) {
                prev->next = current->next;
                current = current->next;
            } else {
                prev = current;
                current = current->next;
            }
        }
    } 
    
    return head;
}
