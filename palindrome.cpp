/*
234. Palindrome Linked List
Solved
Easy
Topics
Companies

Given the head of a singly linked list, return true if it is a
palindrome
or false otherwise.

 

Example 1:

Input: head = [1,2,2,1]
Output: true

Example 2:

Input: head = [1,2]
Output: false

 

Constraints:

    The number of nodes in the list is in the range [1, 105].
    0 <= Node.val <= 9

 
Follow up: Could you do it in O(n) time and O(1) space?
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
    ListNode* findMid(ListNode* head)
    {
        ListNode *fast=head, *slow=head, *prev;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        return prev;
    }

    ListNode* reverseList(ListNode* head)
    {
        ListNode *prev=NULL, *ptr=head, *tmp;
        while(ptr)
        {
            tmp = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = tmp;
        }
        head = prev;
        return head;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* preMid = findMid(head);
        //cout << "\n Mid returned" << preMid->val;
        ListNode* tmp = preMid;
        ListNode* second = preMid->next;
        tmp->next = NULL;

        second = reverseList(second);
        //cout << "\n Mid is" << second->val;

        while(head && second)
        {
            //cout << "\n first: " << head->val;
            //cout << "\t second: " << second->val;
            if(head->val != second->val)
            {
                return false;
            }
            head = head->next;
            second = second->next;
        }
        //if(head || second) return false;
        return true;
    }
};
