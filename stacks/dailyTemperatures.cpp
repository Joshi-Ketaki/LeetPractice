/*
Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

 

Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]
 

Constraints:

1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100
*/

//Intuition: Keep prev indices on stack and compare with current to see if current is warmer

// TC: O(n) : worst case you go through all prev indices. This is not n^2. Keep in mind that each index is pushed/popped 
// only once on the stack. So even if the while runs within the for, no indices will be pushed/popped again and again
// the number of stack operations will be bounded by n
// SC: O(n): answer vector

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // init with zero to ensure 0 is returned if nothing found for that day
        int length = temperatures.size();
        vector<int> answer(length, 0); 
        // This will have indices
        stack<int> monotonic_st;

        for(int i = 0; i < length; i++)
        {
            // You need to keep doing this till the current temperature is warmer than the one
            // on the stack because technically the current temp at index i is AFTER all of those
            // if you do if, then you will only be comparing with the most recent top element once
            while(!monotonic_st.empty() && temperatures[i] > temperatures[monotonic_st.top()])
            {
                // you found a warmer temperature
                // get the index after which this warmer temp was found
                int prev_index = monotonic_st.top();
                monotonic_st.pop();
                // store after  how many days the warmer temperature will be found
                answer[prev_index] = i - prev_index;
            }
            // if current temperature is not warmer, push on stack
            // Note, yes the previous temperature could have been warmer
            // but remember we are finding AFTER how many days a warmer temperature
            // will occur
            monotonic_st.push(i);
        }
        return answer;
    }
};
