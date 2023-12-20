/*

intuiition:
1. find minimum value in entire array. dont sort as order matters
2. immediate intuition is to find max in the array remaining after min is found.
but more importantly we want to difference of elemnt from remaining array such that it is greates. and we are not starting from 0 ., so that element will be after 
the miniumum element.
3. so find max profit and min buying  point
121. Best Time to Buy and Sell Stock
Solved
Easy
Topics
Companies

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.

 

Constraints:

    1 <= prices.length <= 105
    0 <= prices[i] <= 104

*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyAt = prices[0];
        int sz = prices.size();
        int maxProfit = prices[sz-1] - prices[0];
        for(int i = 0; i < sz; i++)
        {
            buyAt = min(buyAt, prices[i]);
            // if buyAt > prices[i], diff will be neg and not count towards max
            maxProfit = max(maxProfit, prices[i] - buyAt);
        }
        // brute force..too much time
        /*for(int i = 0; i < sz-1; i++)
        {
            for(int j = i+1; j < sz; j++)
            {
                int diff = prices[j]-prices[i];
                if(diff > maxProfit)
                {
                    maxProfit = diff;
                }
            }
        }*/
        return maxProfit;
    }
};
