/*
Description
Guide
Guide
Editorial
Editorial
Solutions
Solutions
[ C++ ] [ Backtracking ]
[ C++ ] [ Backtracking ]
C++ || Simple DP || Memoization || Clean Code
C++ || Simple DP || Memoization || Clean Code
Easy To Understand ||C++ || Recursion || Backtracking
Easy To Understand ||C++ || Recursion || Backtracking
C++ || Recursion Backtracking
C++ || Recursion Backtracking
Submissions
Submissions
Accepted
Accepted
Accepted
Accepted
Code
Testcase
Testcase
Test Result
Note
Note
77. Combinations
Solved
Medium
Topics
Companies

Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.

 

Example 1:

Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.

Example 2:

Input: n = 1, k = 1
Output: [[1]]
Explanation: There is 1 choose 1 = 1 total combination.

 

Constraints:

    1 <= n <= 20
    1 <= k <= n


*/

/*SOLUTION*/
class Solution {

/*int factorial(int m)
{
    if(m == 0)
        return 1;
    if(m == 1)
        return m;
    int fact;
    fact = m * factorial(m-1);
    return fact;
}*/
public:
    void backTrack(vector<vector<int>> &res, vector<int>& ans, int n , int k, int idx)
    {
            if(ans.size() == k){
                res.push_back(ans);
                return;
            }
            for(int i = idx; i <= n; i++){
                ans.push_back(i);
                // note if this is idx+1, it will 
                // end up with duplicates like 2,2 etc
                // and also duplicates like 3,4 and 4,3
                //i+1 ensures it only looks forward from current digit while
                // forming combinations
                backTrack(res, ans, n, k, i+1);
                ans.pop_back();
            }
    }

    vector<vector<int>> combine(int n, int k) {
        //int fact_n = factorial(n);
        //int fact_k = factorial(k);
        //cout << "\n fact_n" << fact_n;
        //cout << "\n fact_k" << fact_k;
        assert(n >=1 && n <= 20);
        assert(k >=1 && k <= n);
        vector<vector<int>> res;
        vector<int> ans;
        backTrack(res, ans, n, k, 1);
        
        return res;
    }
};
