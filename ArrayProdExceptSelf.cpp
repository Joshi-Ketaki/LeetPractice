/*
238. Product of Array Except Self
Solved
Medium
Topics
Companies

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

 

Constraints:

    2 <= nums.length <= 105
    -30 <= nums[i] <= 30
    The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

 
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //int prod=1;
        // brute force O (n^2)
        /*for(int i = 0; i < n ; i++)
        {
            //cout << "\nprod" << prod;
            prod = 1;
            for(int j = 0; j < n; j++)
            {
                //cout << "\nprod nums[j]" << prod << " " << nums[j];
                if(i != j)
                    prod = prod * nums[j];
            }
            ans.push_back(prod);
        }*/

        // TLE
        /*
        int i = 0;
        //cout << "\n nums.size" << nums.size();
        int n = nums.size();
        int asz = 0;
        while(asz < n)
        {
            if(i == n)
            {
                //cout << "\n pushing prod" << prod;
                ans.push_back(prod); asz++;
                prod = 1;
                i= 0;
            }
            //cout << "\n ans.size" << asz;
            //cout << "\t i" << i;
            if(i != asz)
            {
                prod = prod * nums[i];
            }
            i++;
        }*/

        // one approach is to find product of all values and divide by each value 
        // at that position. will not work fpr divide by zero



        int n = nums.size();
        vector<int> ans(n,0);
        vector<int> pre(n, 0), suff(n, 0);
        pre[0] = 1;
        suff[n-1] = 1;

        for(int i = 1; i < n; i++)
        {
            pre[i] = pre[i-1] * nums[i-1];
        }

        for(int i = n-2; i >=0; i--)
        {
            suff[i] = suff[i+1] * nums[i+1];
        }

        for(int i = 0; i < n; i++)
        {
            ans[i] = pre[i]*suff[i];
        }
        return ans;
    }
};
