// Author: Denis Davidoglu
// Question Link: https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/

class Solution {
public:
    int minimumSum(int num) {
        vector<int> digits;
        while (num > 0) {
            //Save the last digit of the number
            digits.push_back(num % 10);
            //Delete the last digit of the number
            num /= 10;
        }
        
        /*The optimal way is to divide the four digits into 
        two numbers of two digits, thus the sum is always less 
        than or equal to 198(=99+99), compared to dividing 
        into one single-digit number and one three-digit number, 
        which brings the limit up to 1008(=999+9). We also put 
        the smaller digits to tens to minimize the result.*/
        sort(digits.begin(), digits.end());
        int new1 = digits[0]*10+digits[2];
        int new2 = digits[1]*10+digits[3];
        return new1+new2;
    }
};