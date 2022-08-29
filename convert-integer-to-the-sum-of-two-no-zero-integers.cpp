// Author: Denis Davidoglu
// Question Link: https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/

class Solution {
public:
    bool hasZero(int n) {
        while (n > 0) {
            if (n % 10 == 0) return true;
            n /= 10;
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n) {
      /* We try to divide n into sum of two fractions, (n/divisor) + (n - n/divisor) 
      picking different divisors. At some point we get a pair with no zeros, 
      which is returned. */
        int divisor = 2;
        while (hasZero(n/divisor) || hasZero(n - n/divisor)) divisor++;
        return {n/divisor, n - n/divisor};
    }
};