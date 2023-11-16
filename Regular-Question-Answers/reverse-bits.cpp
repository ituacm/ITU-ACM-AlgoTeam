// Author: Fatih Baskın
// Question Link: https://leetcode.com/problems/reverse-bits/
// Reviewers: Denis Davidoglu & Ceren Yaşar

/**
 * In this question, we have been asked to reverse bits of a given number.
 * Ex: 01010000 --> 00001010
 *
 * For these operations, we will use unsigned 32 bit numbers (uint32_t)
 * We will use bit manipulations extensively.
 * & : logical and
 * | : logical or
 * << : left shift (multiplying by two)
 * >> : right shift (dividing by two)
 *
 * Time complexity: O(n) (n is number of bits, in this case n = 32)
 * Space complexity: O(1)
 */

class Solution {
   public:
    uint32_t reverseBits(uint32_t n) {
        // We will store the number here
        uint32_t result = 0;
        // Left mask will be 10000....000 (1 bit on the left, rest is 0, 2^31 = 2147483648)
        uint32_t maskL = 2147483648;
        // Right mask will be 0000....001 (1 bit on the right, rest is 0, 2^0 = 1)
        uint32_t maskR = 1;
        /**
         * If result of ANDing number and mask is not zero, mark that bit from left.
         * Ex : (8 bits)   10101100
         *         maskR : 00000100
         * result of AND : 00000100
         * Result is not 0, our right mask was at 3rd bit from right (shifted two times to left)
         * So we will shift MaskL 2 times to right, and OR result (uint32_t) with mask
         *        result : 00000000
         *         maskL : 00100000
         *  result of OR : 00100000
         */
        for (int i = 0; i < 32; i++) {
            // If ANDing number and maskR shifted left by i times is not 0
            if (n & (maskR << i)) {
                // OR result with maskL shifted right i times
                result |= (maskL >> i);
            }
        }
        // Finally return result
        return result;
    }
};
