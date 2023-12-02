/*
9. Palindrome Number
Solved
Easy
Topics
Companies
Hint

Given an integer x, return true if x is a
palindrome
, and false otherwise.

 

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

 

Constraints:

    -231 <= x <= 231 - 1

*/
class Solution {
public:
    bool isPalindrome(int x) {
       if(x < 0 || x > 0 && x%10==0) return false;
       int ans = 0;
       while(x > ans)
       {
           ans = ans * 10 + x%10;
           //cout << "\nx" << x;
           x = x/10;
       }
       //cout << "\nans and x" << ans <<  "\t" <<x;
       return (x == ans || x == ans/10);
     }
};
