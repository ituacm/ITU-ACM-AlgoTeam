// Author: Fatih Baskın
// Question Link: https://leetcode.com/problems/reverse-integer/
// Reviewer: Denis Davidoglu

class Solution
{
public:
    int reverse(int x)
    {
        // Since the environment does not let us to store 64-bit numbers, this means we can't use long long variable type.
        // Normal integers are in the range of -2^31 <= x <= 2^31 - 1, this is about 2 * 10^9.

        // You can get a number's rightmost digit by taking modulo by 10.
        // You can erase a number's rightmost digit by doing integer division by 10.
        // We will use this logic during the operations.
        // ex: 123 % 10 = 3, 123 / 10 = 12

        // Checking for an overflow is unnecessary if -1e9 < x < 1e9
        // Overflow (going over the boundaries) might occur if the condition above is not met.
        // ex: 1000000003, reverse of this number would yield 3000000001, which is above 2^31 - 1.

        // To mitigate overflow probability, a mask and boundary numbers could be used.
        // To get the leftmost digit, a mask of 1e9 and -1e9 can be used.
        // Number would be divided by the mask to get leftmost digit.
        // To shift selected digit right, firstly number could be taken modulo by mask and mask can be divided by 10.
        // ex: number 234 and mask 100, 234 / 10 = 2, 234 % 100 = 34, 100 / 10 = 10, 34 / 10 = 3

        // This shifting and modulo operations will occur log10(n) times, so complexity is O(log(n)).

        // Overflow check:
        if (x <= -1e9 || x >= 1e9) {
            int mask;
            int limit;

            // We should determine mask and limit values
            if (x >= 0) {
                // If x is positive, limit = INT_MAX, mask = 1e9.
                limit = INT_MAX;
                mask = 1e9;
            } else {
                // If x is negative, limit = INT_MIN, mask = -1e9.
                limit = INT_MIN;
                mask = -1e9;
            }

            // We should work on the copy of x, so we won't modify original x.
            // We will check x from right to left and limit numbers from left to right.
            int x_cpy = x;

            while (x_cpy != 0) {
                // Rightmost digit of x
                int x_digit = x_cpy % 10;
                x_cpy /= 10;

                // Leftmost digit of limit
                int limit_digit = limit / mask;
                limit %= mask;
                mask /= 10;

                // We can work with negative numbers, modulo can yield a negative number.
                // But will always get a positive number from limit divided by mask.
                // Again, to fix that issue we will make sure x_digit is positive.
                if (x_digit < 0) x_digit *= -1;

                // If the obtained x_digit > limit_digit, we will get an overflow by reversing, so return 0.
                if (x_digit > limit_digit) return 0;
                // If obtained x_digit is smaller than limit_digit, no way that this operation can generate an overflow.
                // So break the loop and continue.
                if (x_digit < limit_digit) break;
            }
        }

        // If x passed overflow check, continue calculation.
        // Result will be kept as integer res.
        int res = 0;

        // x will reach zero eventually, we will stop when we reach 0.
        while (x != 0) {
            // By the operation explained above, doing the operation as explained.
            // Since we are adding to the right, we need to shift result to left in each operation, which means multiplication by 10.
            res = (res * 10) + (x % 10);
            x /= 10;
        }

        return res;
    }
};
