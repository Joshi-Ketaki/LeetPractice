/*
good practice for reverse also
445. Add Two Numbers II
Solved
Medium
Topics
Companies

You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:

Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]

Example 2:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]

Example 3:

Input: l1 = [0], l2 = [0]
Output: [0]

 

Constraints:

    The number of nodes in each linked list is in the range [1, 100].
    0 <= Node.val <= 9
    It is guaranteed that the list represents a number that does not have leading zeros.

 

Follow up: Could you solve it without reversing the input lists?

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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev=NULL, *ptr = head, *tmp;
        if(head == NULL || head->next == NULL) return head;
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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 && l2) return l2;
        if(l1 && !l2) return l1;
        if(!l1 && !l2) return NULL;

        l1 = reverseList(l1);
        l2 = reverseList(l2);
        ListNode *l3, *newHead;
        l3 = new ListNode();
        newHead = l3;
        // quick reverseList check
        /*while(l1)
        {
            cout << "\t" << l1->val;
            l1=l1->next;
        }*/
        int s, c=0, first = 0;
        while(l1 || l2)
        {
            s = 0;
            if(l1)
            {
                s = s + l1->val;
                l1 = l1->next;
            }
            if(l2)
            {
                s = s + l2->val;
                l2 = l2->next;
            }
            s = s + c;
            c = s/10;
            s = s%10;
            l3->next = new ListNode(s);
            l3 = l3->next;
        }

        if(c > 0)
        {
            l3->next = new ListNode(c);
            l3 = l3->next;
        }
        l3 = reverseList(newHead->next);
        return l3;
    }
};
