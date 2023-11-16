// Author: Ahmet Furkan Kavraz
// Question Link: https://leetcode.com/problems/add-binary/

class Solution {
   public:
    string addBinary(string a, string b) {
        // change the least significant bit to most significant bit
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string result;
        bool carry = false;

        // iterate through bits of both numbers
        for (int i = 0; i < min(a.size(), b.size()); i++) {
            // calculate the bit value
            int bit = carry + (a[i] - '0') + (b[i] - '0');

            // push the bit value and update carry bit
            result.push_back((bit % 2) + '0');
            carry = bit / 2;
        }

        // if `a` have remaining bits
        for (int i = min(a.size(), b.size()); i < a.size(); i++) {
            // only line is different from previous iteration
            int bit = carry + (a[i] - '0');

            // push the bit value and update carry bit
            result.push_back((bit % 2) + '0');
            carry = bit / 2;
        }

        // if `b` have remaining bits
        for (int i = min(a.size(), b.size()); i < b.size(); i++) {
            int bit = carry + (b[i] - '0');

            // push the bit value and update carry bit
            result.push_back((bit % 2) + '0');
            carry = bit / 2;
        }

        // lastly if carry bit exist
        if (carry)
            result.push_back('1');

        // reverse the bits of result
        reverse(result.begin(), result.end());

        return result;
    }
};