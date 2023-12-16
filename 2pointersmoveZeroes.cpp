/*
283. Move Zeroes
Solved
Easy
Topics
Companies
Hint

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:

Input: nums = [0]
Output: [0]

 

Constraints:

    1 <= nums.length <= 104
    -231 <= nums[i] <= 231 - 1

 
Follow up: Could you minimize the total number of operations done?
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        size_t sz = nums.size();
        //if(sz == 1) return;

        /* similar time
        int i=0, j=0;
        for( i = 0; i < sz; i++)
        {
            if(nums[i] != 0)
                nums[j++] = nums[i];
        }
        while(j < sz)
        {
            nums[j++] = 0;
        }*/
        
        
        // in place memory movement
        // two pointers
        int p1 = 0, p2 = 1, temp;
        while(p2 < sz) //  && p1 < sz : reducing unnecessary operations
        {
           if(nums[p1] == 0 && nums[p2] != 0)
           {
               //cout << "\n Swapping: "<< nums[p1] << "\t" << nums[p2];
               temp = nums[p1];
               nums[p1] = nums[p2];
               nums[p2] = temp;
               // slower
               // swap(nums[p1], nums[p2]);
               p1++;
           }
           else if(nums[p1] != 0)
           {
               p1++;
           }
           p2++;
        }
    }
};
