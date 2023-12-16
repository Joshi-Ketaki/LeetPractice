/*
4. Median of Two Sorted Arrays
Solved
Hard
Topics
Companies

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

 

Constraints:

    nums1.length == m
    nums2.length == n
    0 <= m <= 1000
    0 <= n <= 1000
    1 <= m + n <= 2000
    -106 <= nums1[i], nums2[i] <= 106


*/

//Brute Force
class Solution {
public:
// brute force: memory expensive, time consuming
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<int> nums;
      
        int i = 0, j = 0;
        while( i <n1 && j < n2)
        {
            if(nums1[i] <= nums2[j]) nums.push_back(nums1[i++]);
            else nums.push_back(nums2[j++]);
        }
        while(i < n1) nums.push_back(nums1[i++]);
        while(j < n2) nums.push_back(nums2[j++]);
        
        int n = n1+n2;
        if(n%2 == 1) return nums[n/2];
        else return (nums[n/2] + nums[(n/2)-1])/2.0;

    }
};