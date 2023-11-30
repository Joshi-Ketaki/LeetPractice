/*
72. Edit Distance
Solved
Medium
Topics
Companies

Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

    Insert a character
    Delete a character
    Replace a character

 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

 

Constraints:

    0 <= word1.length, word2.length <= 500
    word1 and word2 consist of lowercase English letters.

*/

class Solution {
public:
    int min3(int a, int b, int c)
    {
        int tempMin = min(a,b);
        tempMin = min(tempMin, c);
        return tempMin;
    }
    int minDistance(string word1, string word2) {
        int strLen1 = word1.length();
        int strLen2 = word2.length();
        assert(strLen1 >= 0 && strLen1 <= 500);
        assert(strLen2 >= 0 && strLen2 <= 500);
        int dp[strLen1+1][strLen2+1];
        int cnt =  strLen2;
        
        for(int j = 0; j < strLen2+1; j++)
        {
            dp[strLen1][j] = strLen2 - j;
        }

        for(int i = 0; i < strLen1+1; i++)
        {
            dp[i][strLen2] = strLen1 - i;
        }
        
        for(int i = strLen1 - 1; i >= 0; i--)
        {
            for(int j = strLen2 - 1; j>= 0; j--)
            {
                if(word1[i] == word2[j])
                {
                    dp[i][j] = dp[i+1][j+1];
                }
                else
                {
                    dp[i][j] = 1 + min3(dp[i+1][j], dp[i][j+1], dp[i+1][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};
