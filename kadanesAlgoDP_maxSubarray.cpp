/*

intuition: you need to maintain 2 max values....as discounting a subarray if local max doe snot work will not give comlete picture

53. Maximum Subarray
Solved
Medium
Topics
Companies

Given an integer array nums, find the
subarray
with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.

Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

 

Constraints:

    1 <= nums.length <= 105
    -104 <= nums[i] <= 104

 

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
also read: https://medium.com/@rsinghal757/kadanes-algorithm-dynamic-programming-how-and-why-does-it-work-3fd8849ed73d
*/

class Solution {
    //kadanes algorithm dp
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int lmax = 0, gmax = -INT_MAX; // some large value...-1 is greater than some inputs
        for(int i = 0; i < n; i++)
        {
            lmax = max(nums[i], nums[i]+lmax);
            if(lmax > gmax)
            {
                gmax = lmax;
            }
        }
        return gmax;
    }
};
