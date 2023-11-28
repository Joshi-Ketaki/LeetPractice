/*
DP pattern: unbounded knapsack: target present. number of times instances can occur is unbounded.

322. Coin Change
Solved
Medium
Topics
Companies

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:

Input: coins = [2], amount = 3
Output: -1

Example 3:

Input: coins = [1], amount = 0
Output: 0

 

Constraints:

    1 <= coins.length <= 12
    1 <= coins[i] <= 231 - 1
    0 <= amount <= 104


*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        assert(coins.size() >= 1 && coins.size() <= 12);
        assert(amount >= 0 && amount <= pow(10,4));
        if(amount < 1) return 0;
        int dp[amount+1];
        // check this
        dp[0]=0;

        for(int i = 1; i <= amount; i++)
        {
            dp[i] = INT_MAX;
            for(int c = 0; c < coins.size(); c++)
            {
                assert(coins[c] >= 1 && coins[c] <= pow(2,31)-1);
                if(coins[c] <= i && dp[i-coins[c]] != INT_MAX)
                {
                    //cout << "\n coins[c] and i "<< coins[c] << i;
                    dp[i] = min(dp[i], 1 + dp[i-coins[c]]);
                }
            }
        }
        if(dp[amount] == INT_MAX) return -1;
        else return dp[amount];
    }
};
