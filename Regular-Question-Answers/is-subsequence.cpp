// Author: Bilgenur Çelik
// Question Link: https://leetcode.com/problems/is-subsequence/
// Reviewers: Novruz Amirov, Ömer Faruk Erdem, Denis Davidoglu

// Time comp. -> O(n) (n = length of the string t)
// Space comp. -> O(1)

class Solution {
   public:
    /* We want to know if the t string contains the s string's letters as a subsequence.
     *  With two pointers one pointing at the beginning of the t, another one to the s.
     *  Move along the t string's letters. If the letter matches the s pointer's letter, point to the next value of s.
     *  If the s pointer's value is equal to the length of the s, it is a subsequence.
     *  If yes return true, else false.
     */
    bool isSubsequence(string s, string t) {
        // base case:
        if (s == "") return true;

        // sPointer will increase if letters match.
        int sPointer = 0;

        // tPointer is the t's pointer. It will increase whether or not the characters match.
        for (int tPointer = 0; tPointer < t.length(); tPointer++) {
            // into a matching state:
            if (t[tPointer] == s[sPointer]) {
                sPointer++;

                // if the s array comes to an end, then it is a subsequence of t
                if (sPointer == s.length()) return true;
            }
        }

        // in any other case:
        return false;
    }
};
