/*
200. Number of Islands
Solved
Medium
Topics
Companies

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

 

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 300
    grid[i][j] is '0' or '1'.
*/

/*SOLUTION:*/
//Pass 2:

class Solution {
public:
    void check(vector<vector<char>>& grid, int i, int j, int r, int c)
    {
        grid[i][j] = '2';
        if(i > 0 && grid[i-1][j] == '1')
            check(grid, i-1, j, r, c);
        if(j > 0 && grid[i][j-1] == '1')
            check(grid, i, j-1, r, c);
        if(i < r-1 && grid[i+1][j] == '1')
            check(grid, i+1, j, r, c);
        if(j < c-1 && grid[i][j+1] == '1')
            check(grid, i, j+1, r, c);
    }


    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int numIslands = 0;
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(grid[i][j] == '1')
                {
                    check(grid, i, j, r, c);
                    numIslands++;
                }
            }
        }
    return numIslands;
    }
};









    /*void keepTabs(vector<vector<char>>& grid, int i, int j, int rows, int cols){
        grid[i][j] = '2';
        if(i > 0 && grid[i-1][j] == '1'){
            keepTabs(grid, i-1, j, rows, cols);
        }
        if(i < (rows-1) && grid[i+1][j] == '1'){
            keepTabs(grid, i+1, j, rows, cols);
        }
        if(j > 0 && grid[i][j-1] == '1'){
            keepTabs(grid, i, j-1, rows, cols);
        }
        if(j < (cols-1) && grid[i][j+1] == '1'){
            keepTabs(grid, i, j+1, rows, cols);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        assert(rows >= 1 && cols <= 300);
        int numIslands = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == '1'){
                    keepTabs(grid, i, j, rows, cols);
                    numIslands++;
                }
            }
        }
        return numIslands;*/
