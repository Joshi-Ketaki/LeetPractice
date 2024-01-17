/*
148. Sort List
Solved
Medium

Topics

Companies
Given the head of a linked list, return the list after sorting it in ascending order.

 

Example 1:


Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105
 

Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?
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
    ListNode* findMid(ListNode* head)
    {
        ListNode* slow = NULL;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = (slow == NULL) ? head : slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = NULL;
        return mid;
    }

    ListNode* merge(ListNode* left, ListNode* right)
    {
        ListNode dummyHead(0);
        ListNode* ptr = &dummyHead;

        while(left && right)
        {
            if(left->val < right->val)
            {
                ptr->next = left;
                left = left->next;
            }
            else
            {
                ptr->next = right;
                right=right->next;
            }
            ptr=ptr->next;
        }
        if(left) ptr->next = left;
        else ptr->next=right;
        return dummyHead.next;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *mid = findMid(head);
        ListNode *left = sortList(head);
        ListNode *right = sortList(mid);
        return merge(left, right);

    }
};
