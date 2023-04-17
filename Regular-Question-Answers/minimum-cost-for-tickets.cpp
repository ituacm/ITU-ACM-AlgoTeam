// Author : Ömer Faruk ERDEM
// Question Link : https://leetcode.com/problems/minimum-cost-for-tickets/
// Reviewer: Denis Davidoglu

// Time Complexity : O(n)
// Space Complexity : O(n)
    /*
        If we simplify the question's statement: 
        We have to group days so that we can know what we will pay 
        We have grouping options:
        - group by 1 day
        - group by 7 consecutive day starting from current day
        - group by 30 consecutive day starting from current day
        And each of the grouping options has different costs

        To find the minimum cost of grouping we can use top-down aproach   
    */
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int size = days.size() ; 
        
        // To store minimum cost of traveling the rest of the days, beginning from that day
        vector<int> dp(size, -1);

        // Start from the day 1
        return rec(days, costs, dp, days[0]);
    }

    //  Helper function
    int rec(vector<int>& days, vector<int> &costs,vector<int>&dp, int minDay) {
        // Here minDay parameter represents the day we have came so far.
        // So we need to find the next day (that is larger than minDay) in our vector.  

        int startIndex = 0;

        // iterator for the minimum element that is greater than minDay value 
        auto itr = lower_bound(days.begin(), days.end(), minDay); 

        // if there is no such element, return 0
        if (itr == days.end())  return 0;
        
        startIndex = itr - days.begin();

        // we have found the next day that is in our list 
        int startday = days[startIndex]; 

        // if the answer of the minimum cost of traveling remaining days is evaluated before, then return it 
        if (dp[startIndex] != -1) return dp[startIndex];

        // There are three cases that we will consider
        
        // 1-) Take one day pass and don't pay until the next day
        int dailypass   = costs[0] + rec(days, costs, dp, startday+1);
         
        // 2-) Take weekly pass and don't pay until the end of the week
        int weeklypass  = costs[1] + rec(days, costs, dp, startday+7);

        // 3-) Take monthly pass and don't pay until the end of the month
        int monthlypass = costs[2] + rec(days, costs, dp, startday+30);

        // make the answer of startIndex the minimum value of these 3 cases and return it 
        return dp[startIndex] = min(dailypass, min(weeklypass, monthlypass));
    }
};
