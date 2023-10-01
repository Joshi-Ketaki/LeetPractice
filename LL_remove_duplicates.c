/*
82. Remove Duplicates from Sorted List II
Solved
Medium
Topics
Companies

Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

 

Example 1:

Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]

Example 2:

Input: head = [1,1,1,2,3]
Output: [2,3]

 

Constraints:

    The number of nodes in the list is in the range [0, 300].
    -100 <= Node.val <= 100
    The list is guaranteed to be sorted in ascending order.
*/

/*SOLUTION*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* deleteDuplicates(struct ListNode* head){
     struct ListNode *ptr=head, *tmp, *prev;
     int ctr = 0;
     prev = (struct ListNode *)malloc(sizeof(struct ListNode));
     while(ptr != NULL)
     {
         assert(ptr->val >= -100 && ptr->val <=100);
         if(ptr->next != NULL && ptr->next->val == ptr->val)
         {
             while(ptr && ptr->next != NULL && ptr->next->val == ptr->val)
             {
                 tmp = ptr->next;
                 ptr->next = ptr->next->next;
                 ctr++;
                 tmp->next = NULL;
                 free(tmp);
             }
             //printf("ptr->val %d", ptr->val);
             tmp = ptr;
             if(ptr == head)
             {
                ptr = ptr->next;
                ctr++;
                head = ptr;
                //prev = head;
             }
             else
             {
                ptr = ptr->next;
                ctr++;
             }
             prev->next = ptr;
             tmp->next = NULL;
             free(tmp);
         }
         else
         {
             prev = ptr;
             ptr = ptr->next;
             ctr++;
         }
     }
     assert(ctr>=0 && ctr <=300);
     return head;
}
