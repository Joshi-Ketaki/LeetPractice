/*
560. Subarray Sum Equals K
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
 

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107
*/

//Intuition: explained in comments

// TC: O(n)  SC: O(n) -- in the worst case all sums may be unique in the hashmap

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map <int, int> sumHash ;
        int sum = 0;
        int res = 0;
        // the hashmap is s.t key=sum value=no of times the sum has occured
        // sum = 0 has appeared atleast once when we begin
        sumHash[sum] = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            // now we look for sum -k because, if this exists
            // then there was some index before the current one, say j
            // s.t sum between j+1 and i = k (sum - k + k[between j+1 and i])
            if(sumHash.find(sum - k) != sumHash.end())
                res+=sumHash[sum-k];

            // update after
            // if you update before you are incorrectly counting 
            // eg. [1, 2] with k =3
            // if you update before, you say i saw a subarray with i=1 and j+1=1
            // which is only 2.
            // think that this update is to be used in the next cycle
            sumHash[sum]++;
        }
        return res;
    }
};
