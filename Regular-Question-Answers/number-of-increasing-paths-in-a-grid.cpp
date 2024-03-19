/**
 * Author: Ömer Faruk ERDEM
 * Question Link: https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/
 * 
 * Time Complexity: O(N*M)
 * Space Complexity: O(N*M) 
 * 
*/

/**
 * In the question we are asked to find the number of increasing paths in a grid.
 * These paths can start and end at any cell in the grid.
 * So we need to find the number of increasing paths starting from each cell.
 * 
 * INTUITION:
 * First, our aim is to find sum of the all increasing paths starting from each cell.
 * We will do that by using DFS.
 * For example if we are at (i, j) cell and we can go to all of its neighbouring cells,
 * by only one condition: The next cell must be larger than the current cell.
 * And our result for the current cell will be the sum of the results of the next cells.
 * Because if I know the number of increasing paths starting from the next cell and the next cell is
 * larger than the current cell, That means there are "n" paths starting from the current cell.
 * (Assuming "n" is the number of paths starting from the next cell).
 * 
 * Once we understand the algorithms now we can implement it.
 * 
 * IMPLEMENTATION:
 * We will use DFS to find the number of increasing paths starting from each cell.
 * We will use Dynamic Programming to avoid overlapping subproblems.
 * We will use a 2D array dp, where dp[i][j] is the number of increasing paths starting from (i, j).
 * Initially, all the values in dp will be -1. And we will fill it with the help of DFS.
 * And we will do modulus operation by the number '1e9+7' to avoid overflow.
*/

class Solution {
public:
    // create helper variables
    const int MOD = 1e9 + 7;
    // This array will help us to go to the neighbouring cells.
    // It will create the directions: (0, 1), (1, 0), (0, -1), (-1, 0)
    // which are right, down, left, up respectively.
    const vector<int> directions = {0, 1, 0, -1, 0};
    int rowSize, colSize;        
    // Our 2D dp array. Will be resized and filled with -1 at the beginning.
    vector<vector<int>> dp;

    int countPaths(vector<vector<int>>& grid) {
        rowSize = grid.size();
        colSize = grid[0].size();
        int ans = 0;

        // Resize the dp array and fill it with -1 according to the size of the grid.
        dp.resize(rowSize, vector<int>(colSize, -1));

        // For each cell, find the number of increasing paths starting from it.
        for (int i = 0; i < rowSize ; ++i) {
            for (int j = 0; j < colSize ; ++j) {
                ans += DFS(grid, i, j);
                ans %= MOD; // Take modulus at each step to avoid overflow.
            }
        }

        return ans;
    }

    int DFS(vector<vector<int>> &grid, int i, int j) {
        // if we already know the number of paths starting from (i, j), return it.
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Since each cell is an increasing path with length 1. We add 1 to the result.
        dp[i][j] = 1; 

        // For each neighbouring cell, check if we can go to it.
        for (int k = 0; k < 4; ++k) {
            // Use the directions array to generate the neighbouring cell's index difference.
            const int x = i + directions[k];
            const int y = j + directions[k + 1];

            // Boundary check. If it goes out of the grid, skip it.
            if (x < 0 || x == rowSize || y < 0 || y == colSize) {
                continue;
            }
            
            // If the next cell is not larger, skip it. We search for increasing paths.
            if (grid[x][y] <= grid[i][j]) {
                continue;
            }
            
            /**
             * If the next cell is larger, and lets say there are "n" paths starting from the next cell.
             * That means there are also "n" paths starting from the current cell.
             * Because our current cell is smaller than the next cell. And it will create increasing path
             * if we draw a path from the current cell to the next cell.
            */
            dp[i][j] += DFS(grid, x, y); //Add the number of paths starting from the next cell.
            dp[i][j] %= MOD; // Take modulus to avoid overflow at each adding operation.
        }

        // Return number of paths starting from the current cell.
        return dp[i][j]; 
    }
};
