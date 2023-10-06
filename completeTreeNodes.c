/*
222. Count Complete Tree Nodes
Solved
Easy
Topics
Companies

Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.

 

Example 1:

Input: root = [1,2,3,4,5,6]
Output: 6

Example 2:

Input: root = []
Output: 0

Example 3:

Input: root = [1]
Output: 1

 

Constraints:

    The number of nodes in the tree is in the range [0, 5 * 104].
    0 <= Node.val <= 5 * 104
    The tree is guaranteed to be complete.
*/
/*SOLUTION*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int cNodes(struct TreeNode* root, int ctr)
{
    if(!root) return ctr;
    //both children
    assert(root->val >= 0 && root->val<=50000);
    if(root->right && root->left)
        ctr++;
    //leaf
    if(!root->right)// && !root->left)
        ctr++;
    //if(root->left && !root->right)
    //    ctr++;
    ctr = cNodes(root->left, ctr);
    ctr = cNodes(root->right, ctr);
    return ctr;
}

int countNodes(struct TreeNode* root){
    if(!root) return NULL;
    int ctr = 0;
    ctr = cNodes(root, ctr);
    //asssrts on count of complete nodes
    assert(ctr >= 0 && ctr <= 50000);
    return ctr;
}
