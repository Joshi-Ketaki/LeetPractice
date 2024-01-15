/*
5. Longest Palindromic Substring
Solved
Medium
Topics
Companies
Hint

Given a string s, return the longest
palindromic
substring
in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:

Input: s = "cbbd"
Output: "bb"

 

Constraints:

    1 <= s.length <= 1000
    s consist of only digits and English letters.
*/
class Solution {
public:
    char* getSubstring(int l, int len, string s)
    {
        char subString[100];
        int i;
        cout << "s: " << s;
        for(i = l; i < len; i++)
        {
            subString[i] = s[i];
        }
        subString[i] = '\0';
        cout << "\n substring returning" << subString;
        return subString;
    }
   string longestPalindrome(string s) {
        int len = s.length();
        assert(len >= 1 && len <= 1000);
        // think of current charachter as center and expand to eft and roght
        // while checkign the palindrome

        int maxLen = 0;
        string longestPal = "";
        int l, r;

        for(int i = 0; i <len; i++)
        {
            // odd length
            // start from current charachter as center and move in both directions
            l = i; r= i;
            while(l >=0 && r < len && s[l] == s[r])
            {
                if(r-l+1 > maxLen){
                    maxLen = r-l+1;
                    longestPal = s.substr(l, r-l+1);
                }
                l--;
                r++;
            }

            // even length
            //start from central two charachters and move in both directions
            l = i; r = i+1;
            while(l >=0 && r < len && s[l]==s[r])
            {
                if(r-l+1 > maxLen){
                    maxLen = r-l+1;
                    longestPal = s.substr(l, r-l+1);
                }
                l--;
                r++;
            }
        }
        return longestPal;
        /*int resLen = 0;
        string res;
        int l, r;


        for(int i = 0; i < len; i++)
        {
            // odd length pal string
            l = i; r = i;
            while(l >=0 && r < len && s[l] == s[r])
            {
                if(resLen < (r-l+1)){
                    res = s.substr(l, r-l+1);
                    resLen = r-l+1;
                }
                l--;
                r++;
            }
            // even length pal string
            l = i; r = i+1;
            while(l >=0 && r < len && s[l] == s[r])
            {
                if(resLen < r-l+1){
                    res = s.substr(l, r-l+1);
                    resLen = r-l+1;
                }
                l--;
                r++;
            }
        }
        return res;*/
    }
};
    /*string longestPalindrome(string s) {
        int len = s.length();
        assert(len >= 1 && len <= 1000);
        int resLen = 0;
        string res;
        int l, r;


        for(int i = 0; i < len; i++)
        {
            // odd length pal string
            l = i; r = i;
            while(l >=0 && r < len && s[l] == s[r])
            {
                if(resLen < (r-l+1)){
                    res = s.substr(l, r-l+1);
                    resLen = r-l+1;
                }
                l--;
                r++;
            }
            // even length pal string
            l = i; r = i+1;
            while(l >=0 && r < len && s[l] == s[r])
            {
                if(resLen < r-l+1){
                    res = s.substr(l, r-l+1);
                    resLen = r-l+1;
                }
                l--;
                r++;
            }
        }
        return res;
    }*/
};
