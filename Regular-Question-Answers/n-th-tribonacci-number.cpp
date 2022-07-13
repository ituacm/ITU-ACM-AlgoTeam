// Author: Ahmet Furkan Kavraz
// Question Link: https://leetcode.com/problems/n-th-tribonacci-number/

class Solution {
public:
    // for dynamic programming
    unordered_map<int, int> cache;
    
    int tribonacci(int n) {
        
        // base cases
        if (n == 0)
            return 0;
        if (n == 1 or n == 2)
            return 1;
        
        // if in cache no need to calculate one more time
        if (cache[n])
            return cache[n];
        
        // otherwise calculate and update cache value
        return cache[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
    }
};