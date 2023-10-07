/*
102. Binary Tree Level Order Traversal
Solved
Medium
Topics
Companies

Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

Example 2:

Input: root = [1]
Output: [[1]]

Example 3:

Input: root = []
Output: []

 

Constraints:

    The number of nodes in the tree is in the range [0, 2000].
    -1000 <= Node.val <= 1000


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
    vector<vector<int>> levelOrder(TreeNode* root) {
       
       vector<vector<int>> result;
       vector<int> ans;
       queue<TreeNode*> q;
       if(root == NULL) return result;
       TreeNode* node;
       q.push(root);
       int n;
       int ctr = 0;
       int level = -1;
       ans.clear();
       while(!q.empty()) {
           n = q.size();
           level = level+1;
           //cout << "\nlevel" << level << endl<< "n:" <<n;
           ans.clear();
           ctr = ctr + n;
           assert(ctr >= 0 && ctr <= 2000);
           for(int i = 0; i< n; i++)
           {
               node = q.front();
               q.pop();
               if(node) {
                   //cout << "\n node" << node->val;
                   assert(node->val >= -1000 && node->val <= 1000);
                   ans.push_back(node->val);
                   //cout << "out";
                   if(node->left) q.push(node->left);
                   if(node->right) q.push(node->right);
               }
           }
           result.push_back(ans);
       }
       return result;
    }
};
