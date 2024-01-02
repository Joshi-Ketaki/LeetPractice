/*
Pre order traversal
108. Convert Sorted Array to Binary Search Tree
Solved
Easy
Topics
Companies

Given an integer array nums where the elements are sorted in ascending order, convert it to a
height-balanced
binary search tree.

 

Example 1:

Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:

Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.

 

Constraints:

    1 <= nums.length <= 104
    -104 <= nums[i] <= 104
    nums is sorted in a strictly increasing order.


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
    TreeNode* helper(int left, int right, vector<int>& nums)
    {
        if(left <= right){
            // this is to avoid overflows
            int p = left+(right-left)/2;
            if((left+right) % 2 == 1) ++p;

            TreeNode *root = new TreeNode(nums[p]);
            root->left = helper(left, p-1, nums);
            root->right= helper(p+1, right, nums);
            return root;
        }
        else
        {
            return NULL;
        }
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        return helper(0, nums.size()-1, nums);
    }
};
