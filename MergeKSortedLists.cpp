/*
23. Merge k Sorted Lists
Solved
Hard

Topics

Companies
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.
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

    ListNode* mergeTwoLists(ListNode* h1, ListNode*h2)
    {
        if(!h1) return h2;
        if(!h2) return h1;

        ListNode* ans = new ListNode(-1);
        ListNode* ptr = ans;

        while(h1 && h2)
        {
            if(h1->val < h2->val)
            {
                ptr->next = h1;
                ptr = ptr->next;
                h1 = h1->next;
            }
            else if(h2->val <= h1->val)
            {
                ptr->next = h2;
                ptr = ptr->next;
                h2 = h2->next;
            }
        }

        while(h1)
        {
            ptr->next = h1;
            ptr = ptr->next;
            h1 = h1->next;
        }

        while(h2)
        {
            ptr->next = h2;
            ptr = ptr->next;
            h2 = h2->next;
        }
        return ans->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* rootList;
        if(lists.size() <= 0) return NULL;
        rootList = lists[0];

        for(int i = 1; i < lists.size(); i++)
        {
            rootList = mergeTwoLists(rootList, lists[i]);
        }
        return rootList;
    }
};
