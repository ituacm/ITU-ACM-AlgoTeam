// Author: Murat Biberoğlu
// Question: https://leetcode.com/problems/maximum-69-number/
// Reviewer: Denis Davidoglu

class Solution {
public:
    // To make given number largest under given move, we need to convert first 6 to 9
    int maximum69Number(int num) {
        stack<int> digits;  // LIFO Data Structure

        // Put all digits to stack, most significant digit at the top
        while (num) {
            digits.push(num % 10);
            num /= 10;
        }

        // true means we didn't converted a 6 to 9 yet
        // false means we converted a 6 to 9
        bool flag = true;
        while (!digits.empty()) {
            int d = digits.top();
            digits.pop();

            // if digit is 6 and flag is true then,
            // convert digit to 9 and mark flag as false
            if (d == 6 && flag) {
                d = 9;
                flag = false;
            }

            // append digit to the end of number
            num *= 10;
            num += d;
        }
        return num;
    }
};
