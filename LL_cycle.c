/*
141. Linked List Cycle
Easy
14.2K
1.2K
company
Amazon
company
Apple
company
Adobe

Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

 

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

Example 2:

Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

Example 3:

Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.

 

Constraints:

    The number of the nodes in the list is in the range [0, 104].
    -105 <= Node.val <= 105
    pos is -1 or a valid index in the linked-list.

 

Follow up: Can you solve it using O(1) (i.e. constant) memory?

*/

/*SOLUTION : O(1) memory*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool hasCycle(struct ListNode *head) {
    if(head == NULL || head->next == NULL)
        return false;
   
    struct ListNode *fast = head, *slow = head;
    bool cycle = false;
    int pos=-1, ctr=0;
    while(fast && fast->next != NULL){
        assert(slow->val >= -100000 && slow->val <= 100000);
        slow = slow->next;
        ctr++;
        fast = fast->next->next;
        if(slow==fast){
            pos = ctr;
            cycle = true;
            break;
        }
    }
    assert(pos >=-1 && pos <= ctr);
    assert(ctr >= 0 && ctr <= 10000);
    return cycle;
}
