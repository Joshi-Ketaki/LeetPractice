/*
345. Reverse Vowels of a String
Solved
Easy
Topics
Companies

Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

 

Example 1:

Input: s = "hello"
Output: "holle"

Example 2:

Input: s = "leetcode"
Output: "leotcede"

 

Constraints:

    1 <= s.length <= 3 * 105
    s consist of printable ASCII characters.


*/

class Solution {
public:
    string reverseVowels(string s) {
        vector<char> otherS;
        vector<int> idx;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'
            || s[i] == 'A' || s[i] == 'E'|| s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                otherS.push_back(s[i]);
                idx.push_back(i);
            }
        }

        int sz = otherS.size();
        int j = sz-1;
        //for(int i = 0; i < s.size(); i++)
        for(int i = 0; i < sz; i++)
        {
            // this also works. additional cokmparison and iterates through entire array
            //if(j >= 0 && (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E'|| s[i] == 'I' || s[i] == 'O' || s[i] == 'U'))
            //{
                //s[i] = otherS[j--];

            //}
            if(j >= 0)
                s[idx[i]] = otherS[j--];
        }
        return  s;
    }
};
