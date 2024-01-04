/*
106. Construct Binary Tree from Inorder and Postorder Traversal
Solved
Medium
Topics
Companies

Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

 

Example 1:

Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]

Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]

 

Constraints:

    1 <= inorder.length <= 3000
    postorder.length == inorder.length
    -3000 <= inorder[i], postorder[i] <= 3000
    inorder and postorder consist of unique values.
    Each value of postorder also appears in inorder.
    inorder is guaranteed to be the inorder traversal of the tree.
    postorder is guaranteed to be the postorder traversal of the tree.


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
    int postOrderIdx;
    map<int, int> inorderMap;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      // form map for inorder 
    for(int i = 0; i < inorder.size(); i++)
    {
           inorderMap[inorder[i]] = i;
    }
    postOrderIdx = postorder.size()-1;
    return mapToTree(postorder, 0, inorder.size()-1);
    }

    TreeNode* mapToTree(vector<int>& postorder, int left, int right)
    {
        if(left > right || postOrderIdx < 0) return NULL;

        int element = postorder[postOrderIdx--];
        cout << "\nElement root" << element;

        TreeNode* root = new TreeNode();
        root->val = element;

        int position = inorderMap[root->val];
        cout << "\t position in inorder array" << position;

        root->right = mapToTree(postorder, position+1, right);
        root->left = mapToTree(postorder, left, position-1);

        return root;
    }
};

