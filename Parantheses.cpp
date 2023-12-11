/*
map and stack usage

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
        unordered_map <char, char> mp;
        mp['('] = ')';
        mp['['] = ']';
        mp['{'] = '}';
        stack<char> st;
        // we need stack to check order also
        for(int i = 0; i < s.size(); i++)
        {
            // if open bracket
            if(mp.find(s[i]) != mp.end()) {
                st.push(s[i]);
            }
            // if close bracket, check if corresponding open bracket was there before
            else
            {
                if(st.empty()) return false;
                else
                {
                    char corrOpen = st.top();
                    st.pop();
                    //cout << "\nTop:" << corrOpen;
                    //cout << "\nClose" << s[i];
                    //cout << "\n  mp[coorOpen]" << mp[corrOpen];
                    //cout << "\n s[i]" << s[i];
                    // invalid pair i.e. open and close bracket don't match
                    if(mp[corrOpen] != s[i]) 
                    {
                        return false;
                    }
                }
            }
        }
        // stack should be empty to ensure all open-close brackets are popped off
        // eg. "["
        if(!st.empty()) return false;
        return true;
    }
};
