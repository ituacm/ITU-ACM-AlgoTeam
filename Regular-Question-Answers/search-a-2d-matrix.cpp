// Author: Denis Davidoglu
// Question Link: https://leetcode.com/problems/search-a-2d-matrix/

/* This implementation uses two binary searches, although implementation *
 * with one search with the same complexity is possible too.            */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int mid;
        int n = matrix.size(), m = matrix[0].size();
        
        // Binary search for detecting the row with target                                              */
        int up = 0, down = n-1;
        while (down - up > 1) {
            mid = (up+down)/2;
            if (matrix[mid][0] > target) down = mid-1;
            else up = mid;
        }
        if (up+1 < n && matrix[up+1][0] <= target) up++;
        
        // On the row found, a regular binary search is carried out
        int left = 0, right = m-1;
        while (left <= right) { 
            mid = (left+right)/2;
            if (matrix[up][mid] > target) right = mid-1;
            if (matrix[up][mid] < target) left = mid+1;
            if (matrix[up][mid] == target) return true;
        }
    
        cout << up << " " << mid << endl;
        
        return false;
    }
};