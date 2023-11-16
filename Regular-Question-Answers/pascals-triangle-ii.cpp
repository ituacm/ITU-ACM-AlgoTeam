// Author: Ömer Faruk ERDEM
// Question Link: https://leetcode.com/problems/pascals-triangle-ii/
// Reviewer: Denis Davidoglu

// Time Complexity : O(n^2)
// Space Complexity : O(n^2)
class Solution {
   public:
    vector<int> getRow(int rowIndex) {
        // create a two dimensional array to store Pascal's triangle
        vector<vector<int>> pascalTriangle(rowIndex + 1);

        // Fill the Pascal's triangle according to its rule
        for (int i = 0; i <= rowIndex; i++) {
            for (int j = 0; j <= i; j++) {
                // Set first elements value as one
                if (j == 0) {
                    pascalTriangle[i].push_back(1);
                    continue;
                }
                // Set last elements value as one
                if (j == i) {
                    pascalTriangle[i].push_back(1);
                    continue;
                }
                // Set middle elements value sum of the its ancestors at last row.
                else {
                    pascalTriangle[i].push_back(pascalTriangle[i - 1][j - 1] + pascalTriangle[i - 1][j]);
                }
            }
        }
        // return the requested row
        return pascalTriangle[rowIndex];
    }
};
