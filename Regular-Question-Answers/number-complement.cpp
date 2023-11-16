// Author: Bilgenur Çelik
// Question Link: https://leetcode.com/problems/number-complement/
// Reviewer: Denis Davidoglu

class Solution {
   public:
    int findComplement(int num) {
        /* Complement of an integer is the inverted binary state of the integer.
        Mathematically we can get (2^m - 1) at maximum, m = binary digit size of the number.
        Thus substract num from maximum to get the result.
        */
        // binary lenght
        int binLenght = 0;

        // hold a temp value for division
        int temp = num;

        while (temp > 0) {
            binLenght++;
            // division by two
            temp = temp >> 1;
        }

        return (pow(2, binLenght) - 1) - num;
    }
};
