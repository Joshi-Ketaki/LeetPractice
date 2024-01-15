/*
130. Surrounded Regions
Solved
Medium
Topics
Companies

Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

 

Example 1:

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation: Notice that an 'O' should not be flipped if:
- It is on the border, or
- It is adjacent to an 'O' that should not be flipped.
The bottom 'O' is on the border, so it is not flipped.
The other three 'O' form a surrounded region, so they are flipped.

Example 2:

Input: board = [["X"]]
Output: [["X"]]

 

Constraints:

    m == board.length
    n == board[i].length
    1 <= m, n <= 200
    board[i][j] is 'X' or 'O'.
*/

/*
SOLUTION
*/
//Pass 2:
class Solution {
public:
        void check(vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j, int r, int c)
        {
            if(visited[i][j] == 1) return;
            visited[i][j] = 1;
            if(i > 0 && board[i-1][j] == 'O')
                check(board, visited, i-1, j, r,c);
            if(j > 0 && board[i][j-1] == 'O')
                check(board, visited, i, j-1, r,c);
            if(i < r-1 && board[i+1][j] == 'O')
                check(board, visited, i+1, j, r,c);
            if(j < c-1 && board[i][j+1] == 'O')
                check(board, visited, i, j+1, r, c);
        }

        void solve(vector<vector<char>>& board) {
             int r = board.size();
             int c = board[0].size();
             vector<vector<int>> visited(r, vector<int>(c, 0));

             for(int i = 0; i < r; i++)
             {
                 for(int j = 0; j < c; j++)
                 {
                     if(i == 0 || j == 0 || i == r-1 || j == c-1)
                     {
                        if(board[i][j]=='O' && visited[i][j]!=1)
                            check(board, visited, i, j, r, c);
                     }
                 }
             }

            for(int i = 0; i < r; i++)
            {
                for(int j = 0; j < c; j++)
                {
                    if(board[i][j]=='O' && visited[i][j]!=1)
                        board[i][j] = 'X';
                }
            
            }

        }
};
/*class Solution {
public:
    
    void markVisited(vector<vector<char>>& board, vector<vector<int>> &visited, int i, int j, int rows, int cols)
    {
        if(visited[i][j] == 1)
            return;
        // mark that O as visited, i.e cannot be flipped
        visited[i][j] = 1;

        // mark its adjacent 'O' as visited i.e. cannot be flipped
        if(i > 0 && board[i-1][j] == 'O')
        {
            markVisited(board, visited, i-1, j, rows, cols);
        }
        if(j > 0 && board[i][j-1] == 'O')
        {
            markVisited(board, visited, i, j-1, rows, cols);
        }
        if(i < rows-1 && board[i+1][j] == 'O')
        {
            markVisited(board, visited, i+1, j, rows, cols);
        }
        if(j < cols-1 && board[i][j+1] == 'O')
        {
            markVisited(board, visited, i, j+1, rows, cols);
        }

    }

    void solve(vector<vector<char>>& board) {

       int rows = board.size();
       int cols = board[0].size();
       assert(rows >= 1 && cols <= 200);
       vector<vector<int>> visited(rows, vector<int>(cols,0));

       for(int i = 0; i < rows; i++)
       {
           for(int j = 0; j < cols; j++)
           {
                if(i == 0 || j == 0 || i == rows-1 || j == cols-1 )
                {
                    if(visited[i][j]!=1 && board[i][j] == 'O') 
                    {
                        markVisited(board, visited, i,j, rows, cols);
                    }
                }
           }
       }

       // mark remaining as can be flipped
       for(int i = 0; i < rows; i++)
       {
           for(int j = 0; j < cols; j++)
           {
                if(visited[i][j]!=1 && board[i][j] == 'O')
                {
                    cout << "here";
                    board[i][j] = 'X';
                }       
           }
        }
       
    }
};*/
