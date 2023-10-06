/*
101. Symmetric Tree
Solved
Easy
Topics
Companies

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:

Input: root = [1,2,2,3,4,4,3]
Output: true

Example 2:

Input: root = [1,2,2,null,3,null,3]
Output: false

 

Constraints:

    The number of nodes in the tree is in the range [1, 1000].
    -100 <= Node.val <= 100

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

bool checkMirror(struct TreeNode* left, struct TreeNode* right) 
{
    if(!right || !left)
        return (right == left);
    assert(right->val >= -100 && right->val <= 100);
    assert(left->val >= -100 && left->val <= 100);
    if(right->val == left->val)
        return(checkMirror(left->left, right->right) && checkMirror(left->right, right->left));
    return false;
}
bool isSymmetric(struct TreeNode* root)
{
     return checkMirror(root->left, root->right);
}