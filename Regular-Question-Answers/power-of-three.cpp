// Author: Rojen Arda Şeşen
// Question Link: https://leetcode.com/problems/power-of-three/

// n is a power of k if log(n) base k  is an integer.
// log k (n) = x --> k^(x) = n --> if x is an integer, n is a power of k.
// We will be using double precision floating point numbers to calculate logarithms.
// There may be errors in floating point representation, therefore we will check
// equality based on a treshold.

// Time complexity of this code is O(1), assuming the time complexity of log function
// is O(1). Space complexity is also O(1).

class Solution {
   public:
    bool isPowerOfThree(int n) {
        double result;
        result = log(n) / log(3);

        if (abs(result - round(result)) < 0.0000000001)
            return true;
        else
            return false;
    }
};
