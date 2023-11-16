// Author: Bilgenur Çelik
// Reviewer: Ahmet Furkan Kavraz
// Question Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// Time comp. -> O(n)
// Space comp. -> O(1)

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        // store maximum profit so far: (this will be the return value)
        int maxProfit = 0;

        // store profit of that ith day:
        int profitToday = 0;

        // to maximize profit, we should take the least minimum until that ith day
        int minUntilToday = INT_MAX;

        // this for loop will update the above integers.
        // from day 0 to last day:
        for (int i = 0; i < prices.size(); i++) {
            // update the min value if there is a smaller price
            minUntilToday = min(minUntilToday, prices[i]);

            // update profit_today
            profitToday = prices[i] - minUntilToday;

            // afterwards compare it with max_profit
            maxProfit = max(profitToday, maxProfit);
        }

        return maxProfit;
    }
};
