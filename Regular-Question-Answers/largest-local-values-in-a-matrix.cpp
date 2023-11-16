// Author: Rojen Arda Şeşen
// Question Link: https://leetcode.com/problems/largest-local-values-in-a-matrix/
// Reviewer: Denis Davidoglu

// Simple brute force solution. We iterate over the local element to
// find the maximum for each entry of maxLocal array.

// Time Complexity: T(n) = O((n - 2)^2), for a given nxn matrix.
//   -> For each element of maxLocal array, we iterate over 9 elements
//   -> 9 * (n - 2) * (n - 2) iterations --> O((n - 2)^2)

class Solution {
   public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        // Creating an (n - 2) x (n - 2) matrix and initializing with INT_MIN
        vector<vector<int>> maxLocal(n - 2, vector<int>(n - 2, INT_MIN));

        // For each element of maxLocal we iterate through possible maximums
        for (int i = 0; i < n - 2; i++) {      // maxLocal row
            for (int j = 0; j < n - 2; j++) {  // maxLocal column

                // Rows of subarray of size 3x3, centering at (i + 1, j + 1)
                for (int k = i; k < i + 3; k++) {
                    // Columns of subarray
                    for (int l = j; l < j + 3; l++) {
                        if (grid[k][l] > maxLocal[i][j])
                            maxLocal[i][j] = grid[k][l];
                    }
                }
            }
        }
        return maxLocal;
    }
};
