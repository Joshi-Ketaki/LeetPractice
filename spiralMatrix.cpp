/*
//follow the pattern

54. Spiral Matrix
Solved
Medium
Topics
Companies
Hint

Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

 

Constraints:

    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 10
    -100 <= matrix[i][j] <= 100


*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int minR = 0, maxR = matrix.size()-1;
        int minC = 0, maxC = matrix[0].size()-1;

        vector<int> ans;

        while(minC <= maxC && minR <= maxR)
        {
            //right
            for(int i = minC; i <= maxC; i++)
            {
                ans.push_back(matrix[minR][i]);
            }
            minR++;
            if(minC > maxC || minR > maxR) break;
            //down
            for(int i = minR; i<= maxR; i++)
            {
                ans.push_back(matrix[i][maxC]);
            }
            maxC--;
            if(minC > maxC || minR > maxR) break;
            //left
            //note the limits
            for(int i = maxC; i >=minC; i--)
            {
                ans.push_back(matrix[maxR][i]);
            }
            maxR--;
            if(minC > maxC || minR > maxR) break;
            //up
            //notr the limits
            for(int i = maxR; i>=minR; i--)
            {
                ans.push_back(matrix[i][minC]);
            }
            minC++;

            if(minC > maxC || minR > maxR) break;
        }
        return ans;
    }
};
