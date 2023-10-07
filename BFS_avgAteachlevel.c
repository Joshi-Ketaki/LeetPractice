/*
637. Average of Levels in Binary Tree
Solved
Easy
Topics
Companies
Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. Answers within 10-5 of the actual answer will be accepted.

 

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [3.00000,14.50000,11.00000]
Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
Hence return [3, 14.5, 11].

Example 2:

Input: root = [3,9,20,15,7]
Output: [3.00000,14.50000,11.00000]

 

Constraints:

    The number of nodes in the tree is in the range [1, 104].
    -231 <= Node.val <= 231 - 1


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
    vector<double> averageOfLevels(TreeNode* root) {
        
        queue<TreeNode*> q;
        vector<double> avg;
        int ctr;
        q.push(root);
        double sum = 0;
        TreeNode *node;
        while(q.size() > 0)
        {
            int n = q.size();
            sum = 0;
            //ctr += n;
            assert(ctr >= 1 && ctr <= 10000);
            for(int i = 0; i < n; i++){
                node = q.front();
                q.pop();
                //cout << "\nsum" << sum << "node->val"<< node->val;
                assert(node->val >= pow(-2, 31) && node->val <= pow(2,31)-1);
                sum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            avg.push_back(sum/n);
        }
        return avg;
    }
   
};
