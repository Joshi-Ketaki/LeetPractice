/*
300. Longest Increasing Subsequence
Solved
Medium
Topics
Companies

Given an integer array nums, return the length of the longest strictly increasing
subsequence
.

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4

Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1

 

Constraints:

    1 <= nums.length <= 2500
    -104 <= nums[i] <= 104

 

Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?

*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        assert(nums.size() >=1 && nums.size() <= 2500);
        vector<int> dp (nums.size(), 1);

        for(int i = nums.size(); i >= 0; i--)
        {
            for(int j = i+1; j < nums.size(); j++)
            {
                if(nums[i] < nums[j])
                {
                    dp[i] = max(dp[i], 1+dp[j]);
                }
            }
        }
        int max = dp[0];
        for (int d:dp)
        {
            if(d > max)
                max = d;
        }
        //*(max_element(dp.begin(), dp.end()))
        return max;
    }
};
