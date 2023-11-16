// Author: Ahmet Furkan Kavraz
// Question Link: https://leetcode.com/problems/maximum-xor-for-each-query/

class Solution {
   public:
    // find results for subarrays
    int findResult(int number, int maximumBit) {
        int result = 0;

        // k value can have at most 'maximumBit' bits
        for (int i = 0; i < maximumBit; i++) {
            // if corresponding bit is 0 in number
            if (!(number & (1 << i)))
                // make orresponding bit with 1 in result
                result |= (1 << i);
        }
        return result;
    }

    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        // find xor of all numbers in array
        int xorn = 0;
        for (int itr : nums)
            xorn ^= itr;

        // to store results
        vector<int> results;

        // reverse loop
        for (int i = nums.size() - 1; i >= 0; i--) {
            // call the findResult function for each value
            results.push_back(findResult(xorn, maximumBit));

            // removing the last element of subarray
            xorn ^= nums[i];
        }

        return results;
    }
};