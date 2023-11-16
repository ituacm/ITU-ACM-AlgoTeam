// Author: Ceren Yaşar
// Question Link: https://leetcode.com/problems/plus-one/description/
// Reviewer: Denis Davidoglu

// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {
        digits[digits.size() - 1]++;
        // increment the least significant digit by one

        // this for loop iterates over the digits to check if there is any digit larger than 9
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] > 9) {
                // if digit i is larger than 9, it should be assigned to 0 and the following digit must be incremented

                digits[i] = 0;
                if (i >= 1) {
                    // to avoid segmentation fault, we check if i was the most significant digit. in other words, the first index.
                    // if not, we can safely increment digits[i-1].
                    digits[i - 1]++;
                } else {
                    // if i was the most significant digit and is larger than 9, it must be 10 since we only increment by 1.
                    // so in order to indicate a valid digit, we must push 1 to the beginning of the array.
                    // this is equivalent to multiplying the number by 10, which means adding 0 to the end and assigning digits[0] to 1.
                    digits.push_back(0);
                    digits[0] = 1;
                }
            }
        }
        return digits;
    }
};
