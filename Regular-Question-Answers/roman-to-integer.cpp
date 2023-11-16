// Author: Ömer Faruk Erdem
// Reviewer: Ahmet Furkan Kavraz
// Question Link: https://leetcode.com/problems/roman-to-integer/

class Solution {
   public:
    /* Utility function to get one single roman symbol's integer value.
     * Function takes character and returns its integer value.
     * Here I have used switch case but it could be done with many other ways to.
     * For example if else statements or map.
     */
    int getValue(char c) {
        switch (c) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
    }

    int romanToInt(string s) {
        // variable to get total value of the Roman numerals
        int totalValue = 0;

        for (int i = 0; i < s.size(); i++) {
            // Current symbols integer value
            int currentNum = getValue(s[i]);

            // Next symbols integer value
            int nextNum = getValue(s[i + 1]);

            /* We get next symbols integer value to decide if there is a case like "IV"
             * Because as the question explained Roman numerals are usually written largest to smallest from left to right
             * But  if there is a case where the left hand number is less than the right hand number then we substract that
             * left hand number from total value
             */
            if (currentNum >= nextNum) {
                totalValue += currentNum;
            } else {
                totalValue -= currentNum;
            }
        }
        return totalValue;
    }
};
