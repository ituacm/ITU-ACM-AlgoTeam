// Author: Emre Çelik
// Question Link: https://leetcode.com/problems/count-servers-that-communicate/
// Reviewer: Ceren Yaşar, Denis Davidoglu

// Time Complexity: O(n*m)
// Memory Complexity: O(n*m)

class Solution {
   public:
    int countServers(vector<vector<int>>& grid) {
        // Declaring n and m as number of columns and rows.
        int n = grid.size();
        int m = grid[0].size();
        // Declaring row and col vectors with the number of servers in that row or column.
        vector<int> row(n), col(m);

        // Search our grid to calculate number of server for row and col vectors.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Decreasing row[i] and col[j] if grid[i][j] has server.
                if (grid[i][j] == 1) {
                    row[i]++;
                    col[j]++;
                }
            }
        }

        // Number of servers that communicate with at least one of the other servers.
        int total = 0;

        /* Checking if ith row and jth column of our our grid have at least 2 servers
        to communicate with each other.*/
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && (row[i] >= 2 || col[j] >= 2)) {
                    // If states are ensured, decrease total by 1.
                    total++;
                }
            }
        }

        return total;
    }
};
