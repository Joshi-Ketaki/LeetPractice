/*
2095. Delete the Middle Node of a Linked List
Medium
3.6K
64
company
Adobe
company
Microsoft
company
Amazon

You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

    For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.

 

Example 1:

Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]
Explanation:
The above figure represents the given linked list. The indices of the nodes are written below.
Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
We return the new list after removing this node. 

Example 2:

Input: head = [1,2,3,4]
Output: [1,2,4]
Explanation:
The above figure represents the given linked list.
For n = 4, node 2 with value 3 is the middle node, which is marked in red.

Example 3:

Input: head = [2,1]
Output: [2]
Explanation:
The above figure represents the given linked list.
For n = 2, node 1 with value 1 is the middle node, which is marked in red.
Node 0 with value 2 is the only node remaining after removing node 1.

 

Constraints:

    The number of nodes in the list is in the range [1, 105].
    1 <= Node.val <= 105
*/

/* SOLUTION*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 /*SLOW
   int ctr = 0, toDelete;
   struct ListNode* list = head, *prev;

   
   while(list != NULL)
   {
       assert(list->val >= 1 && list->val <= 100000);
       ctr++;
       list = list->next;
   }
   assert(ctr >= 1 && ctr <= 100000);
   if(ctr == 1){
       return NULL;
   }
   toDelete = ctr/2;
   list = head;
   ctr = 0;
   while(ctr < toDelete && list!=NULL){
       prev = list;
       list = list->next;
       ctr++;
   }
   prev->next = list->next;
   list->next = NULL;
   free(list);*/
struct ListNode* deleteMiddle(struct ListNode* head){
   struct ListNode *slow = head, *fast = head, *prev;
   // only one node
   if(slow->next == NULL){
       return NULL;
   }
   if(slow->next->next == NULL)
   {
       // 2 nodes
       head->next = NULL;
       return head;
   }
   while(fast && fast->next)
   {
       prev = slow;
       slow = slow->next;
       fast = fast->next->next;
   }
   prev->next = slow->next;
   slow->next = NULL;
   free(slow);
   return head;
}
