/*
20. Valid Parentheses
Solved
Easy
Topics
Companies
Hint

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.

 

Example 1:

Input: s = "()"
Output: true

Example 2:

Input: s = "()[]{}"
Output: true

Example 3:

Input: s = "(]"
Output: false

 

Constraints:

    1 <= s.length <= 104
    s consists of parentheses only '()[]{}'.


*/

// explanation of the question:
// this is not well formed: "[{]}"
// this is well formed: "[{}]"
class Solution {
public:
    bool isValid(string s) {
        unordered_map <char, char> mp ;
        mp['('] = ')'; mp['{'] = '}'; mp['['] = ']';
        stack<char> st;
        //not needed. function call is taking time unnecessarily
        //if(s.size()%2 !=0) return false;
        for(int i = 0; i < s.size(); i++)
        {
            if(mp.find(s[i]) != mp.end())
            {
                // key found
                st.push(s[i]);
            }
            else
            {
                if(st.empty()) return false;
                char topEle = st.top();
                st.pop();
                if(mp[topEle] != s[i])
                {
                    return false;
                }
                
            }
        }
        // "for input like "((" i.e. only opening brackets, the else part will
        // never execute. so nothing will be popped off the stack"
        if(!st.empty()) return false;
        return true;
    }
};
