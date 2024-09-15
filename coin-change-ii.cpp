// Author: Metin Furkan Amarat
// Question Link: https://leetcode.com/problems/coin-change-ii/
// Time Complexity and Space Complexity: O(N * amount)

class Solution {
   
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // Initialise the dp array, this is padded on both dimensions, all values initialised as -1, 
        // so we can differentiate between true 0 values and cells which have not yet been calculated.
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1)); 
        return calculate(0, amount, coins, dp);
    }
    int calculate(int i, int x, vector<int>& coins, vector<vector<int>> &dp ){
        // i --> 
        // The function is recursive, and calls itself with the amount - coins[i].
        // Therefore, if we hit 0, we have found a legitimate way of reaching the amount using the coins we have taken so far.
        if (x == 0)
            return 1;
        // Ran out of coins to pick, still have an amount. No new ways.
        if (i == coins.size())
            return 0;
        // Lastly, if we are in a situation we calculated before, we just return the value.
        if(dp[i][x] != -1)
            return dp[i][x];

        int take = 0; // The number of combinations we have if we take coins[i].
        if(x >= coins[i]) // We take the coin only if we have an amount large enough.
        {
            take = calculate(i, x - coins[i], coins, dp);
        }
        int skip = calculate(i + 1, x, coins, dp); // Number of combinations we have if we do not take coins[i], moving on with coins[i + 1].
        return dp[i][x] = take + skip; // assign the value to the 2d array cell.
    }
};