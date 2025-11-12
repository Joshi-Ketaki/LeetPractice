/*217. Contains Duplicate
Solved
Easy
Topics
premium lock icon
Companies
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 

Example 1:

Input: nums = [1,2,3,1]

Output: true

Explanation:

The element 1 occurs at the indices 0 and 3.

Example 2:

Input: nums = [1,2,3,4]

Output: false

Explanation:

All elements are distinct.

Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]

Output: true

 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109*/

// Intuition:
/*
Brute force is to simply use nested loops and compare each element with every other element in the set.

Unlike a lookup, here we are only concerned with the value of the elements. Therefore a set makes sense.
A set will not have duplicate elements. So we can use that. If the size of the new set is less than the input vector, this means there were some
duplicate elements.

Else we sort the array. This will bring duplicates close to each other.
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //use set here. there are no duplicates in a set
        // Solution 1:
        // unordered sets use hashing for insert... O(1)
        // set will use trees for sorting O(nlogn)
        // SC = O(n)
        //if(nums.size() > unordered_set<int>(nums.begin(), nums.end()).size()) return true;
        //return false;

        // sort
        // TC: O(nlogn)
        // SC(O(1))
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-1; i++)
        {
            if(nums[i] == nums[i+1]) return true;
        }
        return false;
    }
};

