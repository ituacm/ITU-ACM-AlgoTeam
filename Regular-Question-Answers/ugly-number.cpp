// Author: Ahmet Furkan Kavraz
// Question Link: https://leetcode.com/problems/ugly-number/

class Solution {
public:
    bool isUgly(int n) {
        // the number should be positive as written in the question
        if (n <= 0)
            return false;

        // remove the part of factors of 2, 3 and 5
        while (n % 2 == 0) n /= 2;
        while (n % 5 == 0) n /= 5;
        while (n % 3 == 0) n /= 3;

        // if the remaining number is 1, it should only have prime factors 2, 3 and 5
        return n == 1;
    }
};