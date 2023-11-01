/*
46. Permutations
Medium
Topics
Companies

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:

Input: nums = [1]
Output: [[1]]

 

Constraints:

    1 <= nums.length <= 6
    -10 <= nums[i] <= 10
    All the integers of nums are unique.


*/
/*SOLUTION*/
class Solution {
public:

    void backTrack(vector<vector<int>>& res, vector<int>& nums, int k, int idx){
        if(idx == nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i = idx; i < k; i++)
        {
            //ans.push_back(i);
            swap(nums[idx], nums[i]);
            backTrack(res, nums, k, idx+1);
            swap(nums[idx], nums[i]);
            //ans.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        //vector<int> ans;
        vector<vector<int>> res;

        backTrack(res, nums, nums.size(), 0);
        return res;
    }
};
