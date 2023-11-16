// Author: Emre Çelik
// Reviewer: Ahmet Furkan Kavraz
// Question Link: https://leetcode.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times/

class Solution {
   public:
    bool containsPattern(vector<int> &arr, int m, int k) {
        // initialize size of arr to n.
        int n = arr.size();

        // checking if size of array is bigger than m*k, return false.
        if (n < m * k) {
            return false;
        }

        // count variable that counts times of repeating
        int count = 0;

        // checking (n-m) because we are looking for (m+i)th element
        for (int i = 0; i < n - m; i++) {
            // increasing count if ith and (i+m)th element are same
            if (arr[i] == arr[i + m]) {
                count++;
            }

            // if ith and (i+m)th element are not same count is setting to zero
            else {
                count = 0;
            }

            // we are looking for k-1 because we did not count (i+m)th element while decreasing.
            if (count >= (k - 1) * m) {
                return true;
            }
        }
        return false;
    }
};
