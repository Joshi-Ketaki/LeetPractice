/*
42. Trapping Rain Water
Solved
Hard
Topics
Companies

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9

 

Constraints:

    n == height.length
    1 <= n <= 2 * 104
    0 <= height[i] <= 105


*/

class Solution {
public:
    int trap(vector<int>& height) {
        int p1 = 0, p2 = height.size() - 1;
        int maxL = height[p1], maxR = height[p2];
        int trapped = 0;

        while(p1 <= p2)
        {
            if(maxL < maxR)
            {
                maxL = max(maxL, height[p1]);
                trapped += maxL - height[p1];
                p1++;
            }
            else
            {
                maxR = max(maxR, height[p2]);
                trapped += maxR - height[p2];
                p2--;
            }
        }
        
        return trapped;
    }
};
