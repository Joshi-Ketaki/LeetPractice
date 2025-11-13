/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

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

Example 4:

Input: s = "([])"

Output: true

Example 5:

Input: s = "([)]"

Output: false

 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.*/

// Intuiition: explained in comments

// TC: O(n)  S.C: O(n) - in worst case such as "((((((...." we will store all elements on stack

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        // map s.t. the key is the close bracket and value is the 
        // opening bracket which will be pushed when encountered
        unordered_map<char, char> brackets = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        if(s.size() == 1) return false;
        for(int ch = 0; ch < s.size(); ch++)
        {
            // if opening bracket see, push
            if( s[ch] == '(' || s[ch] == '{' || s[ch] == '[')
            {
                st.push(s[ch]);
            } 
            // if closing bracket seen pop.
            // order should be in accordance to the pushed order
            else
            {
                if(st.empty() || st.top() != brackets[s[ch]])
                    return false;
                st.pop();
            }
        }
        // note we return st.empty() because in cases such as '(('
        // the pop may never have happened, but if you return true here
        // that is incorrect
        return st.empty();
    }
};
