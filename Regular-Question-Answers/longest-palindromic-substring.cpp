// Author: Kemal Tahir Bıcılıoğlu
// Reviewer: 
// Question link: https://leetcode.com/problems/longest-palindromic-substring/

/*
    Approach is choosing a middle point for all chars, and traversing given string by going right and left step by step 
    and at each step we know the fact that string is palindrome if the right and the left substrings from the middle are the same. 
    So we check for 1 length mids and 2 length of mids,
    for example for abcabc, middle is ca, for abcab, middle is c, 
    so we need to check both the 1 length mids and the 2 length of mids.
*/

// Time complexity: O(n^2) for all chars, we call find_palindromes recursive function, this function can go up to all string so n*n = n^2
// Space complexity: O(n) string answer, it can be size of s which is n.

class Solution {
public:
    void find_palindromes(string s, string &answer, int left, int right){
        int length = s.length();
        int ans_length = answer.length();
        while(left >= 0 && right < length){  
            if(s[left] != s[right]){ // check if the left and  right of the mid is the same char
                break;
            }
            left--; 
            right++;
        }
        // before break, we increased the size of correct right and correct left by 2. 
        //(right + 1) - (left - 1) + 1= right-left+3 but it should be right - left +1, so decrease by 2. 
        if(ans_length < right - left - 1){ // compare new string and previos string, choose larger one.
            answer = s.substr(left + 1, right - left - 1);
        }
    }

    string longestPalindrome(string s) {
        int length = s.length();
        string answer;
        for(int i = 0; i < length; i++){
            find_palindromes(s, answer, i, i); // checking the strings with an odd length, aba
            find_palindromes(s, answer, i, i+1); // checking the strings with an even length, abba
        }
        return answer;
    }
};