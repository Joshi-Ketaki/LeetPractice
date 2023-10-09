/*
103. Binary Tree Zigzag Level Order Traversal
Solved
Medium
Topics
Companies

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]

Example 2:

Input: root = [1]
Output: [[1]]

Example 3:

Input: root = []
Output: []

 

Constraints:

    The number of nodes in the tree is in the range [0, 2000].
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> returnList;
        vector<int> tempList;
        int altFlag = 0;
        queue<TreeNode*> q;
        int ctr = 0;
        TreeNode* node;
        if(root == NULL)
            return returnList;
        q.push(root);
        ctr++;
        //altFlag = 1;
        int n;
        while(!q.empty())
        {
            n = q.size();
            tempList.clear();
            for(int i = 0; i < n; i++)
            {
                node = q.front();
                assert(node->val >=-100 && node->val <= 100);
                q.pop();
                //cout << "\n node and altFlag" << node->val << altFlag;
                tempList.push_back(node->val);
                if(node->left) 
                {
                    q.push(node->left);
                    ctr++;
                }
                if(node->right) {
                    q.push(node->right);
                    ctr++;
                }
            }
            assert(ctr >= 0 && ctr <= 2000);
            if(altFlag == 1){
                altFlag = 0;
                std::reverse(tempList.begin(), tempList.end());
            }
            else {
                altFlag = 1;
                //std::reverse(tempList.begin(), tempList.end());
            }
            returnList.push_back(tempList);
        }
        return returnList;
    }
};
