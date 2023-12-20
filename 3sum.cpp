/*
Observe:
1. we need to "search" the other two numbers after fixing the first one---so binary search makes sense
2. before that you do not want same start point etc to avoid duoplicates. so sort the array before starting.

so we need to search in the sorted array after fixing a starting point.


15. 3Sum
Solved
Medium
Topics
Companies
Hint

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

 

Constraints:

    3 <= nums.length <= 3000
    -105 <= nums[i] <= 105


*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> finalans;
        vector<int> ans;
        int sz = nums.size();
        if(sz < 3) return finalans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < sz; i++)
        {
            // if first value > 0, you cannot reach 0
            // remember array is sorted so negative values will not appear later
            if(nums[i] > 0) continue;
            if(i > 0 && nums[i-1] == nums[i]) continue;
            int low = i+1, high = sz-1;
            while(low < high)
            {
                    
                    int sum = nums[i] + nums[low] + nums[high];
                    //cout << "sum " << sum;
                    if( sum == 0)
                    {
                        ans.clear(); // this is time consuming though
                        ans.push_back(nums[i]); ans.push_back(nums[low]), ans.push_back(nums[high]);
                        finalans.push_back(ans);
                        //finalans.push_back({nums[i], nums[low], nums[high]});
                        int currLow = nums[low];
                        int currHigh = nums[high];
                        // you dont want to surpass high. so add this low < high 
                        // in both whiles to hold conditions for outer while
                        while(low < high && nums[low] == currLow) low++;
                        while (low < high && nums[high] == currHigh) high--;
                    }
                    else if(sum > 0)
                    {
                        // try reducing what is added as it might have overshot past 0
                        high--;
                    }
                    else
                    {
                        // add something to get it to zero
                        low++;
                    }
            }
        }
        return finalans;
    }
};
