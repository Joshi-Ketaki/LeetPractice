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

/*SOLUTION*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int findInIO(int findVal, int len, int* arr){
    for(int i = 0; i < len; i++)
    {
        if(*(arr + i) == findVal)
            return i;
    }
    return -1;
}

/*struct TreeNode* buildTree(int* inorder, int inlen, int* postorder, int postlen){
    if(inlen == 0) return NULL;
	
    // Last elem of postorder must be (sub)tree's root
    struct TreeNode* curr = malloc(sizeof(struct TreeNode));
    curr->val = postorder[postlen-1];
	
    // Find partition index
    int mid = 0;
    while(inorder[mid]!=curr->val) ++mid;
	
    curr->left = buildTree(&inorder[0], mid, &postorder[0], mid);
    curr->right = buildTree(&inorder[mid+1], inlen-mid-1, &postorder[mid], inlen-mid-1);
    return curr;
}*/

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    if(inorderSize == 0 || postorderSize == 0) return NULL;
    struct TreeNode* node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    node->val = postorder[postorderSize-1];
    node->right=NULL;
    node->left =NULL;
    //postorderSize = postorderSize-1;
    int idx = findInIO(postorder[postorderSize-1], postorderSize, inorder);
    assert(idx!=-1);
    //int idx = 0;
    //while(inorder[idx]!=node->val) ++idx;
    //postorderSize = postorderSize-1-1;
    node->left = buildTree(&inorder[0], idx, &postorder[0], idx);
    node->right = buildTree(&inorder[idx+1], inorderSize-idx-1, &postorder[idx], inorderSize-idx-1);
    return node;
}
