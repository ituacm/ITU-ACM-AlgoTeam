//Author: Semih Gençten
//Question Link: https://leetcode.com/problems/counting-bits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1); // dp vector is initialized

        dp[0] = 0; // since binary representation of 0 is 0

        for(int i = 1; i <= n; i++){
            dp[i] = dp[ i / 2 ] + (i % 2); //As you can see below, even numbers' answers are always equal to the answer of half of the number.
        }                                  //Also you can see that the answers' of odd numbers are always one more than previous number's answer. 

        return dp;
    }
};

//0 -> 0   -> 0
//1 -> 1   -> 1
//2 -> 10  -> 1
//3 -> 11  -> 2
//4 -> 100 -> 1