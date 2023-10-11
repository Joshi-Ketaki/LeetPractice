/*
530. Minimum Absolute Difference in BST
Solved
Easy
Topics
Companies

Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

 

Example 1:

Input: root = [4,2,6,1,3]
Output: 1

Example 2:

Input: root = [1,0,48,null,null,12,49]
Output: 1

 

Constraints:

    The number of nodes in the tree is in the range [2, 104].
    0 <= Node.val <= 105

 

Note: This question is the same as 783: https://leetcode.com/problems/minimum-distance-between-bst-nodes/

*/
/* OR */
/*
783. Minimum Distance Between BST Nodes
Easy
Topics
Companies

Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.

 

Example 1:

Input: root = [4,2,6,1,3]
Output: 1

Example 2:

Input: root = [1,0,48,null,null,12,49]
Output: 1

 

Constraints:

    The number of nodes in the tree is in the range [2, 100].
    0 <= Node.val <= 105

 

Note: This question is the same as 530: https://leetcode.com/problems/minimum-absolute-difference-in-bst/

*/

/* SOLUTION */

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
    int getMinimumDifference(TreeNode* root) {
        if(root == NULL)
            return 0;
        vector<int> sortedList;
        int minVal = 1000000;
        int ctr = 0;
        sortedList = formList(sortedList, root);
        // loop starts after one node
        ctr++;
        for(int i = 1; i < sortedList.size(); i++)
        {
            //cout<< "\t" << sortedList[i];
            minVal = min(minVal, (sortedList[i] - sortedList[i-1]));
            ctr++;
        }
        assert(ctr >= 2 && ctr <= pow(10,4));
        return minVal;
    }

    // form sortedList from BST
    vector<int> formList(vector<int> sList, TreeNode* root){
        if(root == NULL)
            return sList;
        assert(root->val >= 0 && root->val <= pow(10,5));
        sList = formList(sList, root->left);
        sList.push_back(root->val);
        sList = formList(sList, root->right);
        return sList;
    }
};
