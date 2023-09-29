/*
21. Merge Two Sorted Lists
Easy
20.1K
1.9K
company
Amazon
company
Apple
company
Adobe

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:

Input: list1 = [], list2 = []
Output: []

Example 3:

Input: list1 = [], list2 = [0]
Output: [0]

 

Constraints:

    The number of nodes in both lists is in the range [0, 50].
    -100 <= Node.val <= 100
    Both list1 and list2 are sorted in non-decreasing order.


*/

/*SOLUTION*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode* curr, *head;
    int ctr1=0, ctr2=0;
    if(list1 == NULL && list2 == NULL)
        return NULL;
    if(list1 == NULL)
        return list2;
    if(list2 == NULL)
        return list1;

    assert(list1->val <= 100 && list1->val >= -100);
    assert(list2->val <= 100 && list2->val >= -100);
    if(list1->val < list2->val)
    {
        curr = list1;
        list1 = list1->next;
        ctr1++;
    }
    else
    {
        curr = list2;
        list2= list2->next;
        ctr2++;
    }
    head = curr;
    while(list1 != NULL && list2 != NULL)
    {
        assert(list1->val <= 100 && list1->val >= -100);
        assert(list2->val <= 100 && list2->val >= -100);
        if(list1->val < list2->val)
        {
            curr->next = list1;
            list1 = list1->next;
            ctr1++;
        }
        else
        {
            curr->next = list2;
            list2 = list2->next;
            ctr2++;
        }
        curr = curr->next;
    }
    if(list1 != NULL && list2 == NULL){
        while(list1 != NULL){
            assert(list1->val <= 100 && list1->val >= -100);
            curr->next = list1;
            list1 = list1->next;
            curr = curr->next;
            ctr1++;
        }
    }
    if(list1 == NULL && list2 != NULL) {
        while(list2 != NULL){
            assert(list2->val <= 100 && list2->val >= -100);
            curr->next = list2;
            list2 = list2->next;
            curr = curr->next;
            ctr2++;
        }   
    }
    assert(ctr1 <= 50 && ctr1 >=0);
    assert(ctr2 <= 50 && ctr2 >=0);
    return head;
}
