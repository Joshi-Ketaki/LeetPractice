/*
647. Palindromic Substrings
Solved
Medium
Topics
Companies
Hint

Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

 

Constraints:

    1 <= s.length <= 1000
    s consists of lowercase English letters.


*/

class Solution {
public:
    int countPal(int l, int r, string s, int resCount)
    {
        while(l >=0 && r < s.length() && s[l]==s[r])
        {
            resCount++;
            l--;
            r++;
        }
        return resCount;
    }
    
    int countSubstrings(string s) {
        assert(s.length() >= 1 && s.length() <= 1000);
        int resCount = 0;
        int l,r,i;
        for(i = 0; i < s.length(); i++)
        {
            l = r = i;
            resCount = countPal(l, r, s, resCount);

            l = i; r = i+1;
            resCount = countPal(l, r, s, resCount);
        }
        return resCount;
    }
};
