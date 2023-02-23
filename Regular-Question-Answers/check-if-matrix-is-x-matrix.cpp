// Author: Berke Dönmez
// Problem Link: https://leetcode.com/problems/check-if-matrix-is-x-matrix/

/*
    Solution: O(n^2) (n = grid.length)

    If a cell has a non-zero value, we want it to be in the diagonals.
    Otherwise, we want it to be outside the diagonals.

    Let isInDiagonal(i, j) tell us whether the cell in the i-th row and the j-th column is in a diagonal.
    For instance, isInDiagonal(0, 0) = true, isInDiagonal(0, 1) = false for n = 3.
    With a bit of observation, we can see the following:
        1- The cells in the first diagonal (\) satisfy i = j (the row and column numbers are equal). It's because as the row number increases, the column number also increases by the same amount.
        2- The cells in the other diagonal (/) satisfy i + j = n - 1. (0-indexed) It's because as the row number increases, the column number decrases by the same amount.

    Combining these together, every cell (i, j) must satisfy either of the following in an X-Matrix:
        - Either grid[i][j] = 0 and isDiagonal(i, j) = false, or,
        - grid[i][j] != 0 and isDiagonal(i, j) = true.
    Let p = "grid[i][j] != 0", q = "isDiagonal(i, j) = true".
    We want p and q to have the same truth value.
*/
class Solution {
public:
    bool checkXMatrix(vector<vector<int>> &grid) {
        int n = grid.size();
        /*
            Instead of defining another member function inside the class and passing the required parameters,
            we can use lambda function!
            Notice that n isn't passed as a parameter.
        */
        auto isInDiagonal = [&](int row, int col) {
            return row == col || row + col == n - 1;
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                // This is where we check whether p != q.
                if ((grid[i][j] != 0) != isInDiagonal(i, j))
                    return false;
        }
        return true;
    }
};