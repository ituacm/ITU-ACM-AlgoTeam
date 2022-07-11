// Author: Ahmet Furkan Kavraz
// Question Link: https://leetcode.com/problems/palindrome-number/

class Solution {
public:
    bool isPalindrome(int x) {
        
        // change number to the string
        string num = to_string(x);
        int l = 0, r = num.size() - 1;
        
        // do not need to check equality condition
        while (l < r){
            
            // falsity condition
            if (num[l++] != num[r--])
                return false;
        }
        // truth condition
        return true;
    }
};