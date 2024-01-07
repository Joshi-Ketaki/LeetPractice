/*
143. Reorder List
Solved
Medium
Topics
Companies

You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln

Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …

You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 

Example 1:

Input: head = [1,2,3,4]
Output: [1,4,2,3]

Example 2:

Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]

 

Constraints:

    The number of nodes in the list is in the range [1, 5 * 104].
    1 <= Node.val <= 1000


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
    ListNode* findMiddle(ListNode* head)
    {
        ListNode* fast=head, *slow=head;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* reverseSecondHalf(ListNode* head)
    {
        ListNode *prev = NULL, *ptr=head, *tmp;
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
    ListNode* mergeLists(ListNode* first, ListNode* second)
    {
        ListNode *head = first, *tmp, *tmp2;
        while(first && second)
        {
            tmp = first->next;
            tmp2 = second->next;
            first->next = second;
            second->next = tmp;
            second = tmp2;
            first = tmp; 
        }
        /*while(first)
        {
            first->next ;
        }*/
        return head;
    }

    void reorderList(ListNode* head) {
       ListNode* mid = findMiddle(head); 
       //cout << "\tMiddle node:" << mid->val;

       ListNode* tmp = mid->next;
       mid->next = NULL;
       ListNode* second = reverseSecondHalf(tmp);
       //ListNode*ptr =second;
       /*while(ptr)
       {
           cout << "\n" << ptr->val;
           ptr=ptr->next;
       }*/

       head = mergeLists(head, second);
    }
};
