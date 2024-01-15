/*
Fibinacci series

198. House Robber
Solved
Medium
Topics
Companies

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.

 

Constraints:

    1 <= nums.length <= 100
    0 <= nums[i] <= 400


*/

/*class Solution {
public:
    int rob(vector<int>& nums) {
        assert(nums.size() <= 100 && nums.size() >= 1);
        int r1 = 0, oldMax = 0;
        int temp;
        for(int i = 0; i < nums.size(); i++) {
            assert(nums[i] <= 400 && nums[i] >=0);
            temp = max(r1 + nums[i], oldMax);
            r1 = oldMax;
            oldMax = temp;

        }
        return oldMax;
    }
};*/

class Solution {
public:
    int rob(vector<int>& nums) {
        assert(nums.size() <= 100 && nums.size() >= 1);
        /*int r1 = 0, oldMax = 0;
        int temp;
        for(int i = 0; i < nums.size(); i++) {
            assert(nums[i] <= 400 && nums[i] >=0);
            temp = max(r1 + nums[i], oldMax);
            r1 = oldMax;
            oldMax = temp;

        }
        return oldMax;*/
        // houses done. so max profit to be earned is 0 at this point
        vector<int> maxAmt(nums.size()+1, 0);
        maxAmt[nums.size()] = 0;
        // amt to be earned is only what is left in last house if this is chosen
        maxAmt[nums.size()-1] = nums[nums.size()-1];
        for(int i = nums.size()-2; i >=0; i--)
        {
            maxAmt[i] = max(nums[i] + maxAmt[i+2], maxAmt[i+1]);
        }
        return maxAmt[0];
    }
};
