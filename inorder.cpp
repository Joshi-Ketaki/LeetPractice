/*
94. Binary Tree Inorder Traversal
Solved
Easy
Topics
Companies

Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]
Output: [1,3,2]

Example 2:

Input: root = []
Output: []

Example 3:

Input: root = [1]
Output: [1]

 

Constraints:

    The number of nodes in the tree is in the range [0, 100].
    -100 <= Node.val <= 100

 
Follow up: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> op;
public:
    vector<int> inorderTraversal(TreeNode* root) {

        if(root==NULL) return op;
        if(root->left == NULL && root->right == NULL) 
        {
            op.push_back(root->val);
            return op;
        }
        //recursive
        /*if(root->left) inorderTraversal(root->left);
        op.push_back(root->val);
        if(root->right) inorderTraversal(root->right);*/

        //iterative

        stack<TreeNode*> st;
        TreeNode* topNode;
        while(root || !st.empty())
        {
            while(root )
            {
                st.push(root);
                root=root->left;
            }
            topNode = st.top();
            st.pop();
            op.push_back(topNode->val);
            root = topNode->right;
        }
        return op;
    }
};
