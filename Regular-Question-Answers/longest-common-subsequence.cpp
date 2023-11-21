// Author: Ayşe Sarı
// Problem Link: https://leetcode.com/problems/longest-common-subsequence/
/*
This problem can be divided to subproblems so Dynamic Programming is used
Iterate through the sequences from right to left
Compare the characters and store and update a dp
If they match go next if not update dp
*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int a = text1.length();
        int b = text2.length();

        int dp[a + 1][b + 1];
        memset(dp, 0, sizeof(dp));

        for (int i = a - 1; i >= 0; i--) {
            for (int j = b - 1; j >= 0; j--) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        return dp[0][0];
    }
};
