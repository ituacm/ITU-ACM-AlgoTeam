// Author: Denis Davidoglu
// Reviewer: Ahmet Furkan Kavraz
// Question Link: https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        /* The first thing that might come to our mind is to go through each 
        time[i] and simplify by taking mod 60. But instead of keeping storing 
        the data in a large array we could store just the amount of numbers that 
        have a specific remainder. It is more space- and time-efficient. */
        vector<int> remainders(60, 0);
        int result = 0;
        for (auto t:time)
            remainders[t % 60]++;
        
        /* Here we match the complement numbers. We go only until the half of 59 
        so that we fulfill the condition of pairs to not repeat in inverse order.*/
        for (int i = 1; i <= 29; i++)
            result += remainders[i]*remainders[60-i];
        
        /*Not forgetting about the elements with remainders 0 and 30, which are 
        complements of themselves. We calculate the number of combinations of size 2.*/
        result += (long long)remainders[0]*((long long)remainders[0]-1)/2;
        result += (long long)remainders[30]*((long long)remainders[30]-1)/2;
        return result;
    }
};