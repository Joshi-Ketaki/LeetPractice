/*
1. Two Sum
Solved
Easy
Topics
premium lock icon
Companies
Hint
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 

Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
*/

// Intuition:
/* The brute force way to solve this is to just loop twice over the elements to find the complement.
That is not really effective as it will be O(n^2) TC. The trick is to trade space for time i.e. think of a way where the the time to lookup
is faster even if you consume some space in form of a data structure.
The choice here is a hashmap - ordered or unordered. We go with unordered because in this example you don't need an order of elements
The logic is simply that the hashmap will carry key-value pairs s.t. key = data and value = index in the main array
We loop over the main array and add elements to the hashmap. While doing so, if we find that the complement's key-value pair already exists,
we return that.
If nothing is found, we return an empty vector indicating no such pairs were found.*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // using unordered map because we do not care 
        // about the particular order of the keys
        unordered_map <int, int> hash;

        for(int i = 0; i < nums.size(); i++)
        {
            int cmpl = target - nums[i];
            if(hash.find(cmpl) != hash.end())
            {
                return{hash[cmpl], i};
            }
            // else add the key-value to the map
            hash[nums[i]] = i;
        }
        // if nothing found, return an empty vector
        return {};
    }
};
