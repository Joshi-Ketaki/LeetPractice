/*
17. Letter Combinations of a Phone Number
Solved
Medium
Topics
Companies

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:

Input: digits = ""
Output: []

Example 3:

Input: digits = "2"
Output: ["a","b","c"]

 

Constraints:

    0 <= digits.length <= 4
    digits[i] is a digit in the range ['2', '9'].


*/
/*SOLUTION*/

class Solution {
public:
    void backTrack(vector<string> &res, string ans, string* digiMap, int idx, string digits)
    {
            // no more combinations to make. 
            // start pushing string in result vector
            if(idx >= digits.length())
            {
                res.push_back(ans);
                return;
            }
            int num = digits[idx] - '0';
            assert(num >1 && num <=9);
            string st = digiMap[num];
      
            for(int i =0; i < st.size(); i++)
            {
                ans.push_back(st[i]);
                backTrack(res, ans, digiMap, idx+1, digits);
                ans.pop_back();
            }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string ans="";
        if(digits == "") return res;
        assert(digits.length() >=0 && digits.length() <= 4);
        string digiMap[10] = {"", "","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        backTrack(res, ans, digiMap, 0, digits);
        return res;
    }
};
