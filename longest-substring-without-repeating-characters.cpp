// Author: Feyza Sarı
// Question Link:
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

// Sliding Window Algorithm:
class Solution {
public:
    int lengthOfLongestSubstring(string strng) {
        // creating a vector for checking if the character is in alrady in substring
        // -1 for character that we did not see before
        // we store place of the character for every character that we saw
        vector<int> mpp(256, -1);

        // left is beggining of current substring
        // right is end of current substring
        // thus lenght of current substring is right-left+1
        int left = 0, right = 0;
        int n = strng.size();
        int lenghtOfSubstring = 0; // maximum lenght of the substring without repeating
        // we search while we are in the given string
        while (right < n) {
            if (mpp[strng[right]] != -1) // if the character is repeating
                left = max(
                mpp[strng[right]] + 1,
                left); // left will be the next character of the repating character

            mpp[strng[right]] = right; // storing place of the characters

            lenghtOfSubstring = max(lenghtOfSubstring,
                right - left + 1); // if current substring is longer than the
                                 // previous ones update the maximum lenght
            right++; // add a new character to substing for checkin if it is repating
               // or not
        }
    return lenghtOfSubstring; // return the maximum lenght
  }
};
