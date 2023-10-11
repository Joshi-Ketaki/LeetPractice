/*
98. Validate Binary Search Tree
Solved
Medium
Topics
Companies

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

    The left
    subtree
    of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.

 

Example 1:

Input: root = [2,1,3]
Output: true

Example 2:

Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.

 

Constraints:

    The number of nodes in the tree is in the range [1, 104].
    -231 <= Node.val <= 231 - 1


*/

/*SOLUTION*/
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
    int ctr = 0;
    bool isValidBST(TreeNode* root) {
        if(root == NULL)
            return true;
        
        vector<int> sortedList;
        sortedList = formSortedList(sortedList, root);
        assert(ctr >= 1 && ctr <= pow(10,4));
        for(int i = 1; i< sortedList.size(); i++)
        {
            if(sortedList[i-1] >= sortedList[i])
                return false;
        }
        return true;
    }

    vector<int> formSortedList(vector<int> sortedList, TreeNode* root)
    {
        if(root == NULL)
            return sortedList;
        sortedList = formSortedList(sortedList, root->left);
        // assert adds to the time. is there another way to add assert?
        assert(root->val >= pow(-2, 31) && root->val <= pow(2, 31)-1);
        sortedList.push_back(root->val);
        ctr++;
        sortedList = formSortedList(sortedList, root->right);
        return sortedList;
    }
};
