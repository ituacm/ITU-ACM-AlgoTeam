// Author: Emre Çelik
// Question Link: https://leetcode.com/problems/base-7/
// Reviewer: Ceren Yaşar, Denis Davidoglu

// Time Complexity: O(logn)
// Memory Complexity: O(1)

class Solution {
   public:
    string convertToBase7(int num) {
        // Taking the absolute value of num because we will operate on its
        // distance to 0 and then convert it to its actual value,
        // which can be positive or negative.
        int n = abs(num);

        // Declaring ans string for our answer.
        string ans = "";

        // If number is 0 directly return "0" as a string.
        if (num == 0) {
            ans = "0";
            return ans;
        }

        // Creating our ans string with mod and divide n by 7.
        while (n > 0) {
            ans = to_string(n % 7) + ans;
            n = n / 7;
        }

        // Check number and if number is negative add "-" to our ans string.
        if (num < 0) {
            ans = "-" + ans;
        }

        return ans;
    }
};
