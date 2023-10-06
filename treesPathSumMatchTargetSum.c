/*
112. Path Sum
Solved
Easy
Topics
Companies

Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.

 

Example 1:

Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true
Explanation: The root-to-leaf path with the target sum is shown.

Example 2:

Input: root = [1,2,3], targetSum = 5
Output: false
Explanation: There two root-to-leaf paths in the tree:
(1 --> 2): The sum is 3.
(1 --> 3): The sum is 4.
There is no root-to-leaf path with sum = 5.

Example 3:

Input: root = [], targetSum = 0
Output: false
Explanation: Since the tree is empty, there are no root-to-leaf paths.

 

Constraints:

    The number of nodes in the tree is in the range [0, 5000].
    -1000 <= Node.val <= 1000
    -1000 <= targetSum <= 1000
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

bool sumAll(struct TreeNode* root, int sum, int targetSum) {
    if(root == NULL){
        return false;
    }
    assert(root->val <= 1000 && root->val >= -1000);
    //print("")
    sum = sum + root->val;
    // should have reached leaf
    if(sum == targetSum && root->left == NULL && root->right == NULL) {
        //printf("returning true");
        return true;
    }
    
    if(root->left) {
        if(sumAll(root->left, sum, targetSum))
            return true;
    }
    //printf("\nafter left sum: %d and root %d", sum, root->val);
    if(root->right) {
        //printf("in right with root: %d, sum %d", root->val, sum);
        if(sumAll(root->right, sum, targetSum))
            return true;
    }
    return false;
}

bool hasPathSum(struct TreeNode* root, int targetSum){
    assert(targetSum <=1000 && targetSum>=-1000);
    if(root == NULL){
        return false;
    }
    bool sum = sumAll(root, 0, targetSum);
    return sum;
}
