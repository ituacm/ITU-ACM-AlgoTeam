// Author: Hacer Akıncı
// Question Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Reviewer: Denis Davidoglu

/*
    To find the longest substring without repeating characters,
    start from the first character of the string and keep going while there is no repeated character.
    To check repeated characters, we use a hashmap that keeps a char and its last index before iterator.
    If we encounter a character that is already in substring,
    then first we should update max value if current substring length is bigger than max value.
    After updating the max value, we should update our substring.
    For this, we should change the starting point of the new substring to the next character after the repeated character.
    Repeat the same process until the end.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // keep the last index of characters before ith index
        unordered_map<char, int> last_index;

        int start = 0, longest = 0, i;

        for (i = 0; i < s.size(); i++) {
            // first check if this character is in the map. if not, that means never seen so far
            // if it is in the map, check if it is in the current substring. If it is, there are repeated characters in current substring
            if (last_index.find(s[i]) != last_index.end() && last_index[s[i]] >= start) {
                // before changing the start point, update max value
                longest = max(longest, (i - start));

                // new substring start point is next to the repeated character
                start = last_index[s[i]] + 1;
            }
            // assign index to map, so in that way we just keep the last indeces.
            last_index[s[i]] = i;
        }

        // we just updated the longest variable in the for loop if there are repeated characters,
        // but in the end we should check max value in any case
        longest = max(longest, (i - start));

        return longest;
    }
};
