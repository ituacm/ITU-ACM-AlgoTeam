// Author: Murat Biberoğlu
// Reviewer: Ahmet Furkan Kavraz
// Question Link: https://leetcode.com/problems/reverse-vowels-of-a-string/

class Solution {
   public:
    /**
     * two pointers method
     * we are setting pointers as l(left) = 0 and r(right) = s.length - 1
     *
     * if we have two vowels at l and r we need to swap them and then
     * we need to increment l to find next vowel at left
     * we need to decrement r to find next vowel at rigth
     *
     * if we have a vowel at l and a consonant at r
     * we need to decrement r to find next vowel at rigth
     *
     * if we have a vowel at r and a consonant at l
     * we need to increment l to find next vowel at left
     *
     * if we have two consonants at l and r
     * we need to increment l to find next vowel at left
     * we need to decrement r to find next vowel at rigth
     */
    string reverseVowels(string s) {
        int length = s.length();
        int left = 0;
        int rigth = length - 1;

        // when l > r we need to stop because
        // we might get back the vowels' position to inital case
        while (left < rigth) {
            if (isVowel(s[left]) && isVowel(s[rigth])) {
                swap(s[left], s[rigth]);
                left++;
                rigth--;
                continue;
            }

            if (isVowel(s[left])) {
                rigth--;
                continue;
            }

            if (isVowel(s[rigth])) {
                left++;
                continue;
            }

            left++;
            rigth--;
        }
        return s;
    }

    /**
     * checks the given letter, if it is vowel return true else false
     */
    bool isVowel(const char letter) {
        if (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' ||
            letter == 'u' || letter == 'A' || letter == 'E' || letter == 'I' ||
            letter == 'O' || letter == 'U') {
            return true;
        }
        return false;
    }
};