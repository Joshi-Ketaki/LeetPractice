/*
22. Generate Parentheses
Solved
Medium

Topics

Companies
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
*/

class Solution {
public:
    
    void bTrack(vector<string> &result, string curr, int left, int right, int n)
    {
        if(curr.size() == 2*n)
        {
            result.push_back(curr);
            return;
        }

        if(left < n)
            bTrack(result, curr+"(", left+1, right, n);
        if(right < left)
            bTrack(result, curr+")", left, right+1, n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string curr = "";
        bTrack(result, curr, 0,0,n);
        return result;
    }
};
