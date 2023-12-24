/*
206. Reverse Linked List
Solved
Easy
Topics
Companies

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

 

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
      // Iterative
        // reverse the links not the data
       if(head == NULL || head->next == NULL) return head;
       ListNode *prev, *ptr, *nxt;
       prev = head;
       ptr = prev->next;
       prev->next = NULL;
       while(ptr)
       {
           nxt = ptr->next;
           ptr->next = prev;
           prev= ptr;
           ptr = nxt;
       }
       head = prev;
       return head;

OR 
    // Recursive:
    // assume k+1 to m nodes have been reversed and you are at kth node
    // so you want k+1 (nk.next) to point to kth node i.e. k = nk.next.next
    // also you want to make sure nk.next does not point to k+1 nk.next=NULL;
    if(head == NULL || head->next == NULL) return head;
    
    // once you get the last node as the head , just propogate it through the recursion stack
    ListNode* h2 = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return h2;
    }

};
//try recursive
