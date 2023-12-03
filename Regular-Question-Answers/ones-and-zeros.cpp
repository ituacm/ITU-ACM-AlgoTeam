// Author: Hacer Akıncı
// Question Link: https://leetcode.com/problems/ones-and-zeroes/

/*
    3D Dynammic Programming Question

    dp[i][j][k] is equal to the maximum subset size of the strings (from ith string to the end of the strs that includes at most j 0's and k 1's.
    So the answer is dp[0][m][n]. Why?
    Because we are looking all the strings (from the first index to the last index), and we use at most m 0's and n 1's.

    Let's look at the Example 1:
    strs = ["10","0001","111001","1","0"], m = 5, n = 3
    To find dp[0][5][3], start with first index. The first string is "10", and this string may or may not be included in the final subset. 
    So compute the two possibilities:
        1. Do not include the string: We can still use 5 0's and 3 1's. So, we compute dp[1][5][3].
        2. Include the string: We should find the maximum of remaining strings. The remaining array could use at most 4 0's and 2 1's. So, we compute dp[1][4][2].
        
    We want to find the larger subset of two possibilities, so take the maximum of both.
        dp[0][5][3] = max(dp[1][5][3], 1 + dp[1][4][2])
                                        ^  
                                        (we add one because we include first string)

    What is the stopping point for computing dp[i][j][k]?
    - When i comes to the end of the strs array and no string is left, we do not have to compute any further operation.

    Let's calculate the complexities:
        Time complexity = O(Nmn) where N is the lenght of the strs. 
        - In the worst case we fill the entire table. Since we do not repeat the same operation by checking dp array, the time complextiy is equal to the size of the dp array.
        Space complextiy = O(Nmn) 
        - We store the dp array.
*/
class Solution {
public:
    vector<vector<vector<int>>> dp;
    int findMaxForm(vector<string>& strs, int m, int n) {
        dp.resize(size(strs), vector<vector<int>>(m+1, vector<int>(n+1)));
        return helper(strs, m, n, 0);
    }
    int helper(vector<string>& strs, int m, int n, int idx){
        if(idx == size(strs)) return 0;

        if(dp[idx][m][n]) return dp[idx][m][n];

        int zeros = count(begin(strs[idx]), end(strs[idx]), '0'), ones = size(strs[idx]) - zeros;
        dp[idx][m][n] = helper(strs, m, n, idx+1);

        if(m - zeros >= 0 && n - ones >= 0)
            dp[idx][m][n] = max(dp[idx][m][n], 1 + helper(strs, m-zeros, n- ones, idx+1)); 
        return dp[idx][m][n];
    }
};
