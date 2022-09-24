// Author: Bilgenur Çelik
// Question Link: https://leetcode.com/problems/is-subsequence/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        // Two pointers will help us.

        // base case:
        if(s == ""){
            return true;
        }

        // sPointer will increase if letters match.
        int sPointer = 0;

        // i is the t's pointer. It will increase whether or not they match.
        for (int i = 0; i < t.length(); i++){
            // into a matching state:
            if (t[i] == s[sPointer]){
                // increase sPointer
                sPointer++;

                // if the s array comes to an end, then it is a subsequence of t
                if(sPointer == s.length())
                    return true;
            }
        }

        // in any other occasion:
        return false;
    }
};
