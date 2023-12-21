/*
in place array/matrix modifications
boundary checks. using new values to interpret meaning s of old ones


289. Game of Life
Solved
Medium
Topics
Companies

According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

    Any live cell with fewer than two live neighbors dies as if caused by under-population.
    Any live cell with two or three live neighbors lives on to the next generation.
    Any live cell with more than three live neighbors dies, as if by over-population.
    Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.

 

Example 1:

Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]

Example 2:

Input: board = [[1,1],[1,0]]
Output: [[1,1],[1,1]]

 

Constraints:

    m == board.length
    n == board[i].length
    1 <= m, n <= 25
    board[i][j] is 0 or 1.

 

Follow up:

    Could you solve it in-place? Remember that the board needs to be updated simultaneously: You cannot update some cells first and then use their updated values to update other cells.
    In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches upon the border of the array (i.e., live cells reach the border). How would you address these problems?
yes...ths soln is inplace. you could have created a copy of the original board and used that for checking.

*/


class Solution {
public:
    int getLn(vector<vector<int>>& board, int i, int j, int m, int n)
    {
        // add boundary checks
        int ln=0;
        if(j < n-1 && (board[i][j+1] == 1 || board[i][j+1] == 3)) ln++;
        if(j > 0 && (board[i][j-1] == 1 || board[i][j-1] == 3)) ln++;

        if(i > 0 && (board[i-1][j] == 1 || board[i-1][j] == 3)) ln++;
        if(i < m-1 && (board[i+1][j] == 1 || board[i+1][j] == 3)) ln++;

        if(i > 0 && j > 0 && (board[i-1][j-1] == 1 || board[i-1][j-1] == 3)) ln++;
        if(i > 0 && j < n-1 && (board[i-1][j+1] == 1 || board[i-1][j+1] == 3)) ln++;

        if(i< m-1 && j > 0 && (board[i+1][j-1] == 1 || board[i+1][j-1] == 3)) ln++;
        if(i < m-1 && j < n-1 && (board[i+1][j+1] == 1 || board[i+1][j+1] == 3)) ln++;

        return ln;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size(), cols = board[0].size();
        for(int i =0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                int ln = getLn(board, i, j, rows, cols);
                if(board[i][j] == 1 && (ln < 2 || ln > 3))
                {
                    // we want to set this to be live i.e. 1
                    // note that we cannot change existing board 
                    // values such that the conditions of liveness would fail
                    // 1 and 0 will do that. other option is to use a new board 
                    // which is copy of original board and modify that
                    // we observe that if we use 2: new live and 3: new dead value
                    // that alogns with these conditions for liveness.
                    board[i][j] = 3; // new dead --> the next condition ln ==3 tells 3:dead
                }
                else if(board[i][j] == 0 && ln == 3)
                {
                    board[i][j] = 2; // new live
                }
            }
        }


        // adjust board in terms of values
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(board[i][j] == 2) board[i][j] = 1;
                if(board[i][j] == 3) board[i][j] = 0;
            }
        }

    }
};
