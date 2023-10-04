/*
100. Same Tree
Solved
Easy
Topics
Companies

Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

 

Example 1:

Input: p = [1,2,3], q = [1,2,3]
Output: true

Example 2:

Input: p = [1,2], q = [1,null,2]
Output: false

Example 3:

Input: p = [1,2,1], q = [1,1,2]
Output: false

 

Constraints:

    The number of nodes in both trees is in the range [0, 100].
    -104 <= Node.val <= 104
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
bool isSameTree(struct TreeNode* p, struct TreeNode* q){
      
      if(p == NULL || q == NULL){
          return (p == q);
      }
      if(p->val != q->val){
          return false;
      }
      assert(p->val >= -10000 && p->val <=10000);
      assert(q->val >= -10000 && q->val <=10000);
      return (p->val == q->val && isSameTree(p->left, q->left) &&
      isSameTree(p->right, q->right));
 
}
