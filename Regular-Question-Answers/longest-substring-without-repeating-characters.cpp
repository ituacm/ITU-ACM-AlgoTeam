// Author: Feyza Sarı
// Question Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Reviewers: Bilgenur Çelik, Denis Davidoglu

// Sliding Window Algorithm:
class Solution {
public:
    int lengthOfLongestSubstring(string strng) {
        // create a vector for checking if the character is already in the substring
        // -1 for the character that we did not see before
        // we store the place of the character for every character that we saw
        vector<int> mpp(256, -1);

        // left is the beginning of the current substring
        // right is the end of the current substring
        // thus length of current substring is right-left+1
        // lengthOfSubstring is the maximum length of the substring without repeating
        int left = 0, right = 0; n = strng.size(); lengthOfSubstring = 0; 
        // we should search while we are in the given string
        while (right < n) {
             // if the character is repeating left will be the next character of the repating character
            if (mpp[strng[right]] != -1)
                left = max(mpp[strng[right]] + 1, left);

            mpp[strng[right]] = right; // store the place of the characters

            // if the current substring is longer than the previous ones update the maximum length
            lengthOfSubstring = max(lengthOfSubstring, right - left + 1); 
            right++; // add a new character to the substring to check if it is repeating or not
        }
    return lengthOfSubstring; // return the maximum length
  }
};
