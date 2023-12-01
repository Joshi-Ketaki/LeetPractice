/*
516. Longest Palindromic Subsequence
Solved
Medium
Topics
Companies

Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".

Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".

 

Constraints:

    1 <= s.length <= 1000
    s consists only of lowercase English letters.


*/


class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
       int str1Len = text1.length();
       int str2Len = text2.length();
       assert(str1Len >= 0 && str1Len <= 1000);
       assert(str2Len >= 0 && str2Len <= 1000);

       vector<vector<int>> dp(str1Len+1, vector<int>(str2Len+1, 0));
       for(int i = str1Len-1; i >= 0; i--)
       {
           for(int j = str2Len-1; j >= 0; j--)
           {
               if(text1[i] == text2[j]) 
               {
                    dp[i][j] = 1 + dp[i+1][j+1];
               }
               else
               {
                   dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
               }
           }
       }
       return dp[0][0];
    }
  

    int longestPalindromeSubseq(string s) {
        // WAY 1:
        string s1 = s;
        reverse(s1.begin(), s1.end());
        return longestCommonSubsequence(s, s1);
    }
};
