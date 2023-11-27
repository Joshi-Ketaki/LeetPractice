/*
knapsack DP: target given. find subsequence that matches target
note diff. in fibonacci , target not given. just find subsequence for max and min of all.

416. Partition Equal Subset Sum
Solved
Medium
Topics
Companies

Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.

 

Constraints:

    1 <= nums.length <= 200
    1 <= nums[i] <= 100


*/



class Solution {
public:
    bool canPartition(vector<int>& nums) {
        unordered_set<int> mySack;
        assert(nums.size() >= 1 && nums.size() <= 200);
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum = sum + nums[i];
        }
        if(sum % 2 != 0) return false;
        mySack.insert(0);
        set<int> ::iterator it;
        for(int i = 0; i < nums.size(); i++)
        {
            assert(nums[i] >= 1 && nums[i] <= 100);
            unordered_set<int> myCopySack;
            for(auto it = mySack.begin(); it!= mySack.end(); it++)
            {
                  myCopySack.insert(*it);
                  if(mySack.find(*it+nums[i]) == mySack.end()) 
                  {
                    myCopySack.insert(*it+nums[i]);
                  }
            }
            mySack = myCopySack;
        }
        if(mySack.find(sum/2) != mySack.end())
            return true;
        else 
            return false;
    }
};
