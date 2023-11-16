// Author       : Fatih Baskın
// Reviewer     : Rojen Arda Şeşen
// Question Link: https://leetcode.com/problems/hamming-distance/

/* Hamming distance is the number of different bits between two numbers
 * If you XOR two numbers, different bits will be 1 and same bits will be 0.
 * 0^0 = 0, 1^1 = 0, 0^1 = 1
 * With XOR and builtin popcount (returns number of 1s), we can find hamming distance.
 *
 * __builtin_popcount example:
 * A therotical variable x represented with 8 bits: 0100 1001
 * If we call __builtin_popcount function, it will return 3 because there are 3 bits
 * set as 1.
 */

class Solution {
   public:
    int hammingDistance(int x, int y) {
        return __builtin_popcount(x ^ y);
    }
};
