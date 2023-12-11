/*
14. Longest Common Prefix
Solved
Easy
Topics
Companies

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

 

Constraints:

    1 <= strs.length <= 200
    0 <= strs[i].length <= 200
    strs[i] consists of only lowercase English letters.

no DP...just string cmp.
see other approaches in the appl high freq sample
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string substring1 = "";
        for(int c = 0; c < strs[0].size(); c++)
        {
            char firstChar = strs[0][c];
            for(int str = 1; str < strs.size(); str++)
            {
                if(firstChar != strs[str][c])
                {
                    return strs[0].substr(0,c);
                }

            }
        }
        return strs[0];
    }
};

//see other approaches also in the sample
