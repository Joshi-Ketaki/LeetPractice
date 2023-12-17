/*
205. Isomorphic Strings
Solved
Easy
Topics
Companies

Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"
Output: true

Example 2:

Input: s = "foo", t = "bar"
Output: false

Example 3:

Input: s = "paper", t = "title"
Output: true

 

Constraints:

    1 <= s.length <= 5 * 104
    t.length == s.length
    s and t consist of any valid ascii character.


*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<int, int> mpS, mpT;
        if(s.size() != t.size()) return false;
        for(int i = 0; i < s.size(); i++)
        {
            /*if(!mpS.count(s[i]) && !mpT.count(t[i]))
            {
                mpS[s[i]] = t[i];
                mpT[t[i]] = s[i];
            }
            if(mpS[s[i]] != t[i] || mpT[t[i]] != s[i])
            {
                cout<< "\n mismatch " << s[i] << "\t" << t[i];
                return false;
            }*/
            if(mpS.count(s[i]))
            { 
                if(mpS[s[i]] != t[i]) return false;
            }   
            else
            {
                mpS[s[i]] = t[i];
            }

            if(mpT.count(t[i]))
            { 
                if(mpT[t[i]] != s[i]) return false;
            }   
            else
            {
                mpT[t[i]] = s[i];
            } 
        }
        return true;
    }
};
