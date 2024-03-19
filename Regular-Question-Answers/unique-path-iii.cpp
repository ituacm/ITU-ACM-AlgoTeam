// Author: Feyza Sarı
// Reviewers: 
// Question Link: https://leetcode.com/problems/unique-paths-iii/

// Time Complexity: O(4^(m*n))
// Space Complexity: O(m*n)




// This solution explores all possible paths from the starting square to the ending square 
// and increments the result count whenever a valid path is found. 
// The DFS approach ensures that all paths are systematically explored.

// m and n represent the dimensions of the grid.
// eCount is used to keep track of the count of empty squares (squares with a value of 0) in the grid.
// res is the result variable that will store the number of unique paths.

// If an empty square was used, mark it as obstacles that we cannot walk over again.
//
class Solution {
    // Initializes m, n, eCount, and res.
    int m, n, eCount=1, res=0;
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size(), n=grid[0].size();
        // x and y are the starting square indices
        int x, y;

        // Iterates through the grid to find the starting square (value 1) 
        // and counts the number of empty squares.

        for (int i=0; i < m; i++)
            for (int j=0; j<n; j++){
                if (grid[i][j] ==1) x= i, y=j;
                else if (grid[i][j] ==0) eCount++;
            }
        // Call the DFS algorithm starting with start square (x,y) 
        DFS(grid, x,y,0);
        return res;        
    }

    void DFS(vector<vector<int>>& g, int i, int j,int count){
        // If the current position is out of bounds or an obstacle, the function returns.
        if ( i < 0 || i >= m ||  j < 0 || j >= n || g[i][j] == -1) return;
        // If the current position is the ending square (value 2) 
        // and all empty squares have been visited, increments the result count.
        if(g[i][j] == 2){
            if (count == eCount) res++;
            // If all empty squares have not been visited yet just return, it is not a valid path.
            return;
        }
        // mark the empty square as obstacle by setting its value to -1.
        g[i][j] = -1;
        // Count how many square are visited for comparing with total empty square number.
        count++;
        // Recursively explores the four possible directions (up, down, left, right) from the current position.
        DFS(g,i+1,j,count);
        DFS(g,i-1,j,count);
        DFS(g,i,j+1,count);
        DFS(g,i,j-1,count);
        //Restores the original value of the current square after the recursive exploration.
        g[i][j] = 0;
    }
};