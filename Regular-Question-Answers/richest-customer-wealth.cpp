// Author: Rojen Arda Şeşen
// Question Link: https://leetcode.com/problems/richest-customer-wealth/
// Reviewer: Denis Davidoglu

// Time Compexity: O(n x m) where accounts is an n x m matrix.

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = INT_MIN;
        // Looping through each customer
        for (int i = 0; i < accounts.size(); i++) { 
            int sum = 0; // ith customer's total wealth.
            // Summing each customer's wealth from all accounts.
            for (int j = 0; j < accounts[i].size(); j++) { 
                sum += accounts[i][j];
            }
            // If the new sum is greater than the previous maximum value, update the maximum value.
            if (sum > maxWealth) maxWealth = sum;
        }
        return maxWealth;
    }
};
