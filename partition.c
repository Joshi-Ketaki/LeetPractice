/*86. Partition List
Solved
Medium
Topics
Companies

Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

 

Example 1:

Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]

Example 2:

Input: head = [2,1], x = 2
Output: [1,2]

 

Constraints:

    The number of nodes in the list is in the range [0, 200].
    -100 <= Node.val <= 100
    -200 <= x <= 200

*/

/*SOLUTION*/

**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode *tmp, *newHead = NULL, *list2Ptr, *ptr1 = head, *prev;
    int allGreat = 1, allSmall = 1, ctr = 0;
    if(head == NULL || head->next == NULL)
        return head;
        
    assert( x>=-200 && x <= 200);
    while(ptr1 != NULL)
    {
        //printf("\ngoin in val %d", ptr1->val);
        //if(ptr1->val == x)
        //    xflag == 1
        ctr++;
        assert(ptr1->val <= 100 && ptr1->val >=-100);
        if(ptr1->val >= x)
        {
            allSmall = 0;
            //printf("val %d", ptr1->val);
            if(newHead == NULL) {
                newHead = ptr1;
                list2Ptr = newHead;
            }
            else {
                newHead->next = ptr1;
                newHead = newHead->next;
            }
            if(ptr1 != head)
                prev->next = ptr1->next;
            tmp = ptr1;
            ptr1 = ptr1->next;
            if(newHead == head)
                head = ptr1;
            tmp->next = NULL;
            newHead = tmp;
        }
        else
        {
            allGreat = 0;
            prev = ptr1;
            printf("prev val%d", prev->val);
            ptr1 = ptr1->next;
        }

    }
    assert(ctr >= 0 && ctr <=200);
    if(allGreat == 1)
        return list2Ptr;
    if(allSmall == 1)
        return head;
    prev->next = list2Ptr;
    return head;
}
