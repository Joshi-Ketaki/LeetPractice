/*61. Rotate List
Solved
Medium
Topics
Companies

Given the head of a linked list, rotate the list to the right by k places.

 

Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Example 2:

Input: head = [0,1,2], k = 4
Output: [2,0,1]

 

Constraints:

    The number of nodes in the list is in the range [0, 500].
    -100 <= Node.val <= 100
    0 <= k <= 2 * 109

*/
/*SOLUTION*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k)
{
    struct ListNode *ptr = head, *nxtPtr, *last, *newHead, *prev;
    int i=0, ctr = 0;
    if(head == NULL || head->next==NULL || k == 0)
        return head;
    while(ptr->next != NULL)
    {
        ctr++;
        prev = ptr;
        last = ptr->next;
        ptr = ptr->next;
    }
    ctr++;
    ptr = head;
    if(k%ctr == 0)
        return head;
    //printf("prev %d", prev->val);
    //printf("ctr %d", ctr);
    k = k%ctr;
    k = ctr -k;
    while(i < k)
    {
        nxtPtr = ptr;
        ptr = ptr->next;
        i++;
    }
    
    if(nxtPtr->next != NULL){
        last->next = head;
        newHead = nxtPtr->next;
        nxtPtr ->next = NULL;
    }
    else{
        newHead = nxtPtr;
        nxtPtr->next = head;   
        prev->next = NULL;
    }
    return newHead;
}
