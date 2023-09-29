/*
328. Odd Even Linked List
Medium
9.2K
489
company
Amazon
company
Microsoft
company
Adobe

Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.

 

Example 1:

Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]

Example 2:

Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]

 

Constraints:

    The number of nodes in the linked list is in the range [0, 104].
    -106 <= Node.val <= 106


*/
/*SOLUTION*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head){
     if(head == NULL)
         return NULL;
     if(head->next == NULL || head->next->next==NULL)
         return head;
     struct ListNode* oddPtr, *evenPtr, *firstEven;
     int ctr = 0;
     oddPtr = head;
     evenPtr = head->next;
     firstEven = head->next;
     while(oddPtr->next != NULL && evenPtr->next != NULL)
     {
         assert(oddPtr->val >= -1000000 && oddPtr->val <= 1000000);
         assert(evenPtr->val >= -1000000 && evenPtr->val <= 1000000);
         oddPtr->next = evenPtr->next;
         oddPtr = oddPtr->next;
         evenPtr->next = oddPtr->next;
         evenPtr = evenPtr->next;
         ctr++;
     }
     assert(ctr >= -1000000 && ctr <= 1000000);
     oddPtr->next = firstEven;
     return head;
}
