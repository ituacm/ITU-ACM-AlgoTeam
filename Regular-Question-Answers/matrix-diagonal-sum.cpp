// Author:Ali Emre Kaya 
// Reviewer: 
// Question Link: https://leetcode.com/problems/matrix-diagonal-sum/

// Time Complexity = O(n) -> O(mat.size())
// Space Complexity = O(1)

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        
        // if square matrix's column and row size is odd,
        //primary and secondary diagonals intersect in middle of the matrix,
        //we have to count this intersection number only once
        if(mat.size() % 2) {
            sum -= mat[(mat.size()-1)/2][(mat.size()-1)/2];
        }
        
        for(int i = 0; i < mat.size(); i++){
            // sum the numbers that are on the primary diagonal
            sum += mat[i][i];
            // sum the numbers that are on the secondary diagonal
            sum += mat[i][mat.size()-1-i];
        }
        return sum;
    }
};