// Author: Emre Çelik
// Question Link: https://leetcode.com/problems/k-items-with-the-maximum-sum/
// Reviewer: Denis Davidoglu

// Time Complexity: O(1)

class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        // If k is equal or less than the number of 1's, return answer as k.
        if (numOnes >= k) {
            return k;
        }
        // If k is equal or less than the number of 1's plus the number of 0's,
        // return answer as a number of 1's.
        if (numOnes + numZeros >= k) {
            return numOnes;
        }
        // If k is more than the number of 1's plus the number of 0's, return 
        // the number of ones minus (k minus number of 1's minus number of 0's).
        return numOnes - (k-numOnes-numZeros);
    }
};
