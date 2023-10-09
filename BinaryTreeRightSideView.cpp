/*
199. Binary Tree Right Side View
Solved
Medium
Topics
Companies

Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:

Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]

Example 2:

Input: root = [1,null,3]
Output: [1,3]

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
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */



class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> returnList, rList, lList;
        vector<int> tempList;
        queue<TreeNode*> q;
        int ctr = 0;
        TreeNode* node;
        if(root == NULL)
            return returnList;
        
        q.push(root);
        ctr++;
        int n;
        while(!q.empty())
        {
            n = q.size();
            for(int i = 0; i < n; i++)
            {
                node = q.front();
                assert(node->val <= 100 && node->val >= -100);
                q.pop();
                if(node->left) {
                    q.push(node->left); 
                    ctr++; 
                }
                if(node->right) {
                    q.push(node->right);
                    ctr++;
                }
            }
            if(node){
                cout<<"\n node val" << node->val;
                returnList.push_back(node->val);
            }
        }
        assert(ctr >= 0 && ctr <= 100);
        return returnList;
    }
};
