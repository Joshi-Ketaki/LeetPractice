/*
Given an integer array nums, find a
subarray
that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

 

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

 

Constraints:

    1 <= nums.length <= 2 * 104
    -10 <= nums[i] <= 10
    The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.


*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // see this [-2,3,-4] testcase to understand why you need to trace min also
        // basically a min now might get you a higer max later
        // if - * -
        int currMax = nums[0];
        int currMin = nums[0];
        int maxNum = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            int tmp = currMax;
            currMax = max({nums[i], currMax * nums[i], currMin * nums[i]});
            currMin = min({nums[i], tmp * nums[i], currMin * nums[i]});
            maxNum = max(maxNum, currMax);
        }
        return maxNum;
    }
};
