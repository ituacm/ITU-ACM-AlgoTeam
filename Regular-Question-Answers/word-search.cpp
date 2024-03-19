// Author: Mehmet Tolga Kilinckaya
// Link: https://leetcode.com/problems/word-search/description/

class Solution {
public:
    // Depth-First Search (DFS) function to explore the board and find the word
    bool dfs(vector<vector<char>>& board, vector<vector<int>>& visit, string word,
             int row, int col, int n, int m, int ind) {
        // If the current cell is not visited, mark it as visited
        if (visit[row][col] == 0) {
            visit[row][col] = 1;

            // Define the possible moves (up, right, down, left)
            int rownum[4] = {-1, 0, 1, 0};
            int colnum[4] = {0, 1, 0, -1};

            // Iterate through all possible moves
            for (int i = 0; i < 4; i++) {
                int nrow = row + rownum[i];
                int ncol = col + colnum[i];
                int nind = ind + 1;

                // Check if the next move is within bounds, unvisited, matches the next character,
                // and continue DFS recursively
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    visit[nrow][ncol] == 0 && nind < word.length() && board[nrow][ncol] == word[nind]) {
                    if (dfs(board, visit, word, nrow, ncol, n, m, nind)) {
                        return true;
                    }
                } else if (nind == word.length()) {
                    // If we have successfully reached the end of the word
                    return true;
                }
            }
        }

        // Mark the current element as unvisited before backtracking
        visit[row][col] = 0;
        return false;
    }

    // Main function to check if the word exists on the board
    bool exist(vector<vector<char>>& board, string word) {
        // Initialize the dimensions of the board
        int n = board.size();
        int m = board[0].size();

        // Create a 2D array to track visited cells
        vector<vector<int>> visit(n, vector<int>(m, 0));

        // Iterate through each cell on the board
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If the cell is unvisited and matches the first character of the word,
                // initiate DFS to explore the possibilities
                if (visit[i][j] == 0 && board[i][j] == word[0]) {
                    if (dfs(board, visit, word, i, j, n, m, 0)) {
                        return true;
                    }
                }
            }
        }

        // If no match is found, return false
        return false;
    }
};
