// Author: Mehmet Tolga Kýlýnçkaya
// Link: https://leetcode.com/problems/pascals-triangle/description/

class Solution {
public:
    vector<vector<int>> generate(int N) {
        // Initialize a vector 'dp' to represent the current row of Pascal's Triangle
        vector<int> dp;
        dp.push_back(1);

        // Initialize a vector 'res' to store the Pascal's Triangle
        vector<vector<int>> res;
        res.push_back(dp);

        // Base case: if N is 1, return the initial row
        if (N == 1){
            return res;
        }

        // Add the second row (1, 1) to 'res'
        dp.push_back(1);
        res.push_back(dp);

        // Generate Pascal's Triangle for the remaining rows
        for (int i = 2; i < N; i++){
            // Initialize each row with the first element as 1
            dp.push_back(1);

            // Calculate the elements within the row
            for (int x = i-1; x > 0; x--){
                // Each element is the sum of the two elements above it in the previous row
                dp[x] = dp[x] + dp[x-1];
            }

            // Add the last element (1) to the current row and append the row to 'res'
            dp.push_back(1);
            res.push_back(dp);
        }

        // Return the Pascal's Triangle stored in 'res'
        return res;
    }
};
