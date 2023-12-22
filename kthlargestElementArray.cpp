/*
215. Kth Largest Element in an Array
Solved
Medium
Topics
Companies

Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4

 

Constraints:

    1 <= k <= nums.length <= 105
    -104 <= nums[i] <= 104


*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      //int total = nums.size() -1;
      // observation...why use an ordered map.
      // we cannot explicitly sort. so use the knowledge that ordered map will have sorted keys.
      // built in priority queue to implement min heaps can be used.....but thats built in
      map<int, int> mp;
      for(auto i:nums)
      {
          // each element will be an index
          // the value will be count of that element
          mp[i]++;
      }

      int num, cnt=0;
      for(auto i:mp)
      {
          cnt = cnt + i.second;
          if(cnt >= nums.size()-k+1)
          {
              num = i.first;
              break;
          }
      }
      return num;

      //brute...not great.
      /*int i = 0, j = i+1, kctr = 0;
      while(kctr < k)
      {
          for(int i = 0; i < total; i++)
          {
              for(j = i+1; j < total; j++)
              {
                  if(nums[i] > nums[j]) 
                    swap(nums[i], nums[j]);
              }
          }
          kctr++;
      }
      return nums[(nums.size())-k];
*/
    }
};
