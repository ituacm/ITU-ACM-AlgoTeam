// Author       : Fatih Baskın
// Reviewer     :
// Question Link: https://leetcode.com/problems/hamming-distance/

/* Hamming distance is the number of different bits between two numbers
 * If you XOR two numbers, different bits will be 1 and same bits will be 0.
 * 0^0 = 0, 1^1 = 0, 0^1 = 1
 * With XOR and builtin popcount (returns number of 1s), we can find hamming distance.
 */

class Solution 
{
public:
    int hammingDistance(int x, int y) 
    {
        return __builtin_popcount(x^y);
    }
};
