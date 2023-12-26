// Author: Ayşe Sarı
// Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
/*
The dynamic programming approach efficiently calculates the maximum profit by considering the possibilities of buying and selling stocks for each transaction and each day, updating the maximum profit values based on the optimal decisions made at each step.
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
    
    if (n <= 1) {
        return 0;
    }

    // Create arrays to store the maximum profit after at most k transactions
    int k = 2;
    vector<vector<int>> dp(k + 1, vector<int>(n, 0));

    for (int i = 1; i <= k; ++i) {
        int maxDiff = -prices[0];

        for (int j = 1; j < n; ++j) {
            // Calculate the maximum profit for the current transaction and day
            dp[i][j] = max(dp[i][j - 1], prices[j] + maxDiff);
            // Update maxDiff to consider buying the stock at the current day
            maxDiff = max(maxDiff, dp[i - 1][j] - prices[j]);
        }
    }
    // The final result is stored in the last cell of the 2D vector
    return dp[k][n - 1];
}
  
};
