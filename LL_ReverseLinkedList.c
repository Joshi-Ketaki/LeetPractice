/*
206. Reverse Linked List
Easy
19.7K
357
company
Apple
company
Microsoft
company
Amazon

Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:

Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:

Input: head = [1,2]
Output: [2,1]

Example 3:

Input: head = []
Output: []

 

Constraints:

    The number of nodes in the list is the range [0, 5000].
    -5000 <= Node.val <= 5000

*/

/*SOLUTION*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    struct ListNode* prev=NULL, *curr=head, *nxt;
    int ctr = 0;
    while(curr != NULL){
        assert(curr->val >= -5000 && curr->val <= 5000);
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        ctr++;
    } 
    assert(ctr>=0 && ctr<=5000);
    return prev;
}
