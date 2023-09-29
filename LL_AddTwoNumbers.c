/*
2. Add Two Numbers
Medium
28.5K
5.5K
company
Amazon
company
Adobe
company
Apple

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

/*SOLUTION*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if(l1 == NULL && l2 == NULL)
        return NULL;
    if(l1 == NULL)
        return l2;
    if(l2 == NULL)
        return l1;

    int carry = 0, sum=0, ctr1=0, ctr2=0;
    struct ListNode* sumList, *head=l1, *prev;
    while(l1 != NULL && l2 != NULL)
    {
        sumList = l1;
        assert(l1->val >= 0 && l1->val <= 9);
        assert(l2->val >= 0 && l2->val <= 9);
        sum = (l1->val + l2->val + carry);
        //printf("sum %d", sum);
        sumList->val = sum % 10;
        //printf("sum val %d", sumList->val);
        carry = sum / 10;
        prev = l1;
        l1 = l1->next;
        l2 = l2->next;
        ctr1++;
        ctr2++;
        //tmp  = (struct ListNode* ) malloc(sizeof(struct ListNode));
        //sumList->next = (struct ListNode*) malloc(sizeof(struct ListNode));
    }
    
    if(l1 == NULL && l2 != NULL){
        printf("prev->val %d", prev->val);
        prev->next = l2;
        while(l2)
        {
            sumList = l2;
            assert(l2->val >= 0 && l2->val <= 9);
            sum = (l2->val + carry);
            sumList->val = sum % 10;
            printf("l2->val %d", sumList->val);
            carry = sum / 10;
            l2 = l2->next;
            ctr2++;
            
        }
        //sumList->next = (struct ListNode* ) malloc(sizeof(struct ListNode));
        //sumList = sumList->next;
    }

    else if(l2 == NULL && l1 != NULL){
        while(l1)
        {
            sumList = l1;
            assert(l1->val >= 0 && l1->val <= 9);
            sum = (l1->val + carry);
            sumList->val = sum % 10;
            //printf("l1->val %d", l1->val);
            //sumList->next = NULL;
            carry = sum / 10;
            l1 = l1->next;
            ctr1++;
            //sumList->next = (struct ListNode* ) malloc(sizeof(struct ListNode));
            //sumList = sumList->next;
        }
    }
    assert(ctr1 >=1 && ctr1 <=100);
    assert(ctr2 >=1 && ctr2 <=100);
    if (carry!=0) {
        sumList->next = (struct ListNode*) malloc(sizeof(struct ListNode));
        sumList = sumList->next;
        sumList->val = carry;
        sumList->next = NULL;
    }
    
    return head;
}
