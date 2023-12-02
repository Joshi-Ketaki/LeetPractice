/*
//good way to see how to use sort
// good way to see how to use unordered set

217. Contains Duplicate
Solved
Easy
Topics
Companies

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 

Example 1:

Input: nums = [1,2,3,1]
Output: true

Example 2:

Input: nums = [1,2,3,4]
Output: false

Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true

 

Constraints:

    1 <= nums.length <= 105
    -109 <= nums[i] <= 109


*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // way 1
        // O(n)
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-1; i++)
        {
            if(nums[i] == nums[i+1]) return true;
        }
        return false;

        //way 2: took more time
        // O(nlogn)
        /*unordered_set <int>mySet;
        for(int i = 0; i < nums.size(); i++)
        {
            if(mySet.count(nums[i]) > 0) return true;
            mySet.insert(nums[i]);
        }
        return false;*/
    }
};
