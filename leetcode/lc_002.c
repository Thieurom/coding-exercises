//
// LeetCode
// 2. Add Two Numbers
// https://leetcode.com/problems/add-two-numbers
//


/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


#include <stdlib.h>


struct ListNode* createNode(int val) {
    struct ListNode* node;
    
    if ((node = (struct ListNode*) (malloc(sizeof(struct ListNode)))) == NULL)
        exit(-1);
    
    node->val = val;
    node->next = NULL;
    
    return node;
}


void appendNode(struct ListNode** head, struct ListNode** tail, struct ListNode* node) {
    if (*head == NULL) {
        *head = node;
        *tail = node;
    } else {
        (*tail)->next = node;
        *tail = node;
    }
}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    int n1, n2, digit, carry = 0, sum;
    
    while (l1 != NULL || l2 != NULL) {
        n1 = (l1 == NULL) ? 0 : l1->val;
        n2 = (l2 == NULL) ? 0 : l2->val;
        
        sum = n1 + n2 + carry;
        digit = sum % 10;
        carry = sum / 10;
        
        appendNode(&head, &tail, createNode(digit));
               
        if (l1 != NULL)
            l1 = l1->next;
        
        if (l2 != NULL)
            l2 = l2->next;
    }
    
    if (carry > 0)
        appendNode(&head, &tail, createNode(carry));
    
    return head;
} 


/*-----------------------------------------------------------------------------
 * Time complexity: O(max(m, n)), where m, n are the number of nodes of l1, l2.
 * Space complexity: O(max(m, n)), because we create new list with the number
 * of nodes is at most max(m, n) + 1.
 *---------------------------------------------------------------------------*/
