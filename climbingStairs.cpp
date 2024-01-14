/*
Fibonacci pattern:


70. Climbing Stairs
Solved
Easy
Topics
Companies
Hint

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

 

Constraints:

    1 <= n <= 45


*/
/*class Solution {
public:
    int climbStairs(int n) {
        assert(n >= 1 && n <= 45);
        int one=1, two=1, temp;
        for(int i = 0; i < n-1; i++)
        {
            temp = one;
            one = one+two;
            two = temp;
        }
        return one;
    }
};*/

// More DP like approach of memoization with 1 D array
class Solution {
public:
    int climbStairs(int n) {
        assert(n >= 1 && n <= 45);
        //int one=1, two=1, temp;
        /*for(int i = 0; i < n-1; i++)
        {
            temp = one;
            one = one+two;
            two = temp;
        }*/
        //return one;
        vector<int> dp;
        // dp[0]
        dp.push_back(1);
        // dp[1]
        dp.push_back(2);
        for(int i = 2; i < n; i++)
        {
            dp.push_back(dp[i-1] + dp[i-2]);
        }
        return dp[n-1];
    }
};
