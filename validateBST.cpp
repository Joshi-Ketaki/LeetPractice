/*
BST is akin to inordeer traversal. for  a sorted list while traversing inorder and check if list is actually sorted

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
    vector<int> nodes;

    void inorderTraversal(TreeNode* root)
    {
        if(root->left) inorderTraversal(root->left);
        nodes.push_back(root->val);
        if(root->right) inorderTraversal(root->right);
    }

    bool isValidBST(TreeNode* root) {
        if(root == NULL || (root->left == NULL && root->right==NULL)) return true;
        inorderTraversal(root);
        for(int i = 1; i < nodes.size(); i++)
        {
            if(nodes[i] <= nodes[i-1])
                return false;
        }
        return true;
    }
};
