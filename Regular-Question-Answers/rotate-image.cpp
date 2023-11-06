// Author: Ali Emre Kaya
// Reviewer: Fatih Baskın
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// Question Link: https://leetcode.com/problems/rotate-image/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        // Size of the matrix (both rows and columns).
        int size = matrix.size();

        // Transpose the matrix.
        for (int i = 0; i < size; i++) {
            for (int j = i; j < size; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse each row.
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size / 2; j++) {
                swap(matrix[i][j], matrix[i][(size - 1) - j]);
            }
        }
    }
};