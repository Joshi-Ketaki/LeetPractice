/*
2. Add Two Numbers
Solved
Medium
Topics
Companies

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

 

Constraints:

    The number of nodes in each linked list is in the range [1, 100].
    0 <= Node.val <= 9
    It is guaranteed that the list represents a number that does not have leading zeros.


*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNod
 e(int x, ListNode *next) : val(x), next(next) {}
 * };

 the tricky part comes up is creation of the third list. do you create a node and start from there
 or create a dummy node and start filling up from the next one.
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int s=0,c=0;
        ListNode* head = new ListNode();
        ListNode* l3 = head;
        while(l1 || l2)
        {
            if(l1) 
            {
                s += l1->val;
                l1 = l1->next;
            }
            if(l2) 
            {
                s += l2->val;
                l2 = l2->next;
            }
            s += c;         
            c = s/10;
            ListNode* newNode = new ListNode(s%10);
            l3->next = newNode;
            l3 = l3->next;
            s=0;
        }
        if(c>0)
        {
            ListNode* newNode = new ListNode(c);
            l3->next = newNode;
        }
        return head->next;
    }
};
