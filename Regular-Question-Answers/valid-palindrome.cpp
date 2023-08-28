// Author: Fatih Çakır
// Question Link: https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    bool isPalindrome(string s) {
        string cleanString = ""; 

        // Clear input string by removing all non-alphanumeric characters
        // Converting all uppercase letters into lowercase letters
        for (char c : s) {
            if (isalnum(c)) {
                cleanString += tolower(c);
            }
        }

        // Two-pointer method

        int left = 0; // Pointer for the first character
        int right = cleanString.length() - 1; // Pointer for the last character
                                            
        // Comparing characters from both ends to the middle
        while (left < right) {
            if (cleanString[left] != cleanString[right]) 
                return false; // Not a palindrome
            
            left++;
            right--;
        }

        return true; // String is a palindrome
    }
};
