// Author: Denis Davidoglu
// Question Link: https://leetcode.com/problems/a-number-after-a-double-reversal/
// Reviewer: Bilgenur Çelik

class Solution {
public:
    // The core of solution to the problem is the function below.
    int reverse(int n) {
        vector<int> digits;
        int exponent = 0, result = 0;

        // By this method the digits are extracted from the number
        // from the least to the most significant.
        while (n > 0) {
            digits.push_back(n%10);
            n /= 10;
        }

        // Here we calculate the number with same digits but the 
        // order of significance is inverse.
        for (int i = digits.size()-1; i >= 0; i--) {
            result += pow(10, exponent)*digits[i];
            exponent++;
        }
        return result;
    }

    bool isSameAfterReversals(int num) {
        int reversed1 = reverse(num);
        int reversed2 = reverse(reversed1);
        return (num == reversed2);
    }
};
