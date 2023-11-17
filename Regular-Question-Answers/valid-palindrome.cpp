// Author: Fatih Çakır
// Question Link: https://leetcode.com/problems/valid-palindrome/

// Time comp -> O(n)
// Space comp -> O(1)

class Solution {
public:
    bool isPalindrome(string s) {
        // Two-pointer method

        int left = 0;                // Pointer for the first character
        int right = s.length() - 1;  // Pointer for the last character

        // Comparing characters from both ends to the middle
        while (left < right) {
            while (left < right && !isalnum(s[left])) {
                left++;  // Skip non-alphanumeric characters from the left
            }
            while (left < right && !isalnum(s[right])) {
                right--;  // Skip non-alphanumeric characters from the right
            }

            if (tolower(s[left]) != tolower(s[right])) {
                return false;  // Not a palindrome
            }

            left++;
            right--;
        }

        return true;  // String is a palindrome
    }
};
