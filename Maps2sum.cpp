/*
1. Two Sum
Solved
Easy
Topics
Companies
Hint

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

 

Constraints:

    2 <= nums.length <= 104
    -109 <= nums[i] <= 109
    -109 <= target <= 109
    Only one valid answer exists.

 
Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> mp;
        int cmpl;
        vector<int> ans;
        size_t sz = nums.size();
        /*for(int i = 0; i < sz; i++)
        {
            mp[nums[i]] = i;
        }*/

        for(int i = 0; i < sz; i++)
        {
            cmpl = target - nums[i];
            // the complement should also exit in the map
            // cannot use same eleement twice
            if(mp.count(cmpl) && mp[cmpl] != i)
            {
                    ans.push_back(i);
                    ans.push_back(mp[cmpl]);
                    return ans;
            }
            else
            {
                mp[nums[i]] = i;
            }

        }
        return ans;
    }
        // WAY 1: SLOW
        /*int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i != j && nums[i] + nums[j] == target)
                {
                    return {i,j};
                }
            }
        }
        return {};*/

        //WAY 2:
       /* unordered_map<int, int> mp;
        int n = nums.size();
        int cmpl;
        for(int i = 0; i <n; i++)
        {
            mp[nums[i]] = i;
        }

        for(int i = 0; i < n; i++)
        {
            cmpl = target - nums[i];
            if(mp.count(cmpl) && mp[cmpl]!=i)
            {
                return{i, mp[cmpl]};
            }
        }
        return {};
    }*/
};
