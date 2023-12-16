/*367. Valid Perfect Square
Solved
Easy
Topics
Companies

Given a positive integer num, return true if num is a perfect square or false otherwise.

A perfect square is an integer that is the square of an integer. In other words, it is the product of some integer with itself.

You must not use any built-in library function, such as sqrt.

 

Example 1:

Input: num = 16
Output: true
Explanation: We return true because 4 * 4 = 16 and 4 is an integer.

Example 2:

Input: num = 14
Output: false
Explanation: We return false because 3.742 * 3.742 = 14 and 3.742 is not an integer.

 

Constraints:

    1 <= num <= 231 - 1
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        // this will not work because we want to make sure its an integer
        //if(num == sqrt(num) * sqrt(num)) return true;
        for (int i = 0; i <= sqrt(num); i++)
        {
            if(i*i == num) return true;
        }
        return false;
    }
};

// binary search way also possible

class Solution {
public:
    bool isPerfectSquare(int num) {
        // this will not work because we want to make sure its an integer
        //if(num == sqrt(num) * sqrt(num)) return true;
        /* Fastest
        for (int i = 0; i <= sqrt(num); i++)
        {
            if(i*i == num) return true;
        }
        return false;*/


        int high = num, low =1;
        // note this is lon long int because mid*mid can exceed integer range
        long long int mid;
        //if(num == 1) return true;
        while(low <= high)
        {
            mid = low+(high-low)/2;
            if(mid * mid == num)
            {
                return true;
            }
            else if(mid * mid < num) low = mid+1 ;
            else high = mid-1;
        }
        
        return false;
    }
};
