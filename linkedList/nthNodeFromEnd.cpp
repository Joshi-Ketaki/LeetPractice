/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
 

Follow up: Could you do this in one pass?
*/

// Intuition: explained inline
// TC: O(n) SC: O(1)

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyPtr = new ListNode(0);
        dummyPtr->next = head;
        // fast will help us know the end of the list, so that two passes
        // are not required
        ListNode* fast = dummyPtr;
        // we want slow to point to the node before the target node
        ListNode* slow = dummyPtr;

        // fast should be n+1 away from slow
        for(int i = 0; i <= n; i++)
            fast = fast->next;

        while(fast != nullptr)
        {
            slow=slow->next;
            fast=fast->next;
        }
        // we have reached end of list
        // fast - slow = n + 1
        // so slow is pointing to node before target(nth) node
        //ListNode* target = slow->next;
        slow->next = slow->next->next;
        //free(target);
        //remember to return head
        return dummyPtr->next;
    }
};
