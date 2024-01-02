/*
easiest way is to create an array and then use the sorted array to form B=ST
we can find midpoint of linked list and use binary search on it using fast and slow pointers
109. Convert Sorted List to Binary Search Tree
Medium
Topics
Companies

Given the head of a singly linked list where elements are sorted in ascending order, convert it to a
height-balanced
binary search tree.

 

Example 1:

Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.

Example 2:

Input: head = []
Output: []

 

Constraints:

    The number of nodes in head is in the range [0, 2 * 104].
    -105 <= Node.val <= 105


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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* sortedListToBST(ListNode* head) {
        // just as in array we find mid of the linked list
        /// using fast and slow pointer
        // then disconnect left 

        // this is because there is no mid.prev to keep track of end of left 
        // list
        // right list is mid.next to end
        if(!head) return NULL;
        ListNode *slow=head, *fast=head, *prev=NULL;
        while(fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        //if(mid == head) return root;
        TreeNode *root = new TreeNode(slow->val);
        //nececssary check. if no next to access that is an issue
        if(slow==head) return root;
        if(prev) prev->next = NULL;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        return root;

    }
};
