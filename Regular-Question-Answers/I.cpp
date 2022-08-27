// Author: Bilgenur Çelik
// Question Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

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
        for(int i=0; i<prices.size(); i++){
            // update the min value if there is a smaller price
            min_until_today = min(minUntilToday, prices[i]);

            // update profit_today and afterwards compare it with max_profit
            profitToday = prices[i] - minUntilToday;
            maxProfit = max(profitToday, maxProfit);
        }

        return maxProfit;
    }
};

// Time comp. -> O(n)
// Space comp. -> O(1)
