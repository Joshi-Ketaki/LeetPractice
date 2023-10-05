/*
226. Invert Binary Tree
Solved
Easy
Topics
Companies

Given the root of a binary tree, invert the tree, and return its root.

 

Example 1:

Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

Example 2:

Input: root = [2,1,3]
Output: [2,3,1]

Example 3:

Input: root = []
Output: []

 

Constraints:

    The number of nodes in the tree is in the range [0, 100].
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

 void swap(struct TreeNode* root, int ctr)
 {
     assert(ctr >= 0 && ctr <= 100);
     ctr++;
     struct TreeNode* tmp;
     if(root!= NULL)
     {
        assert(root->val <=100 && root->val >= -100);
        tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        swap(root->left, ctr);
        swap(root->right, ctr);
     }
 }

struct TreeNode* invertTree(struct TreeNode* root){
    if(root == NULL)
        return root;
    int ctr = 0;
    /*struct TreeNode* tmp;
    tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    invertTree(root->left);
    invertTree(root->right);*/
    swap(root, ctr);
    return root;
}
