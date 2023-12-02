// Author: Anıl Dervişoğlu
// Question Link: https://leetcode.com/problems/arithmetic-slices/

/*
    Problem Statement:
    An arithmetic subarray is a contiguous subsequence of an array where the difference between 
    consecutive elements is consistent. The subarray must have at least three elements to be 
    considered arithmetic.

    The task is to count the total number of such arithmetic subarrays within a given array.
*/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        // If there are less than 3 elements, we can't form an arithmetic subarray.
        if (nums.size() < 3)
            return 0;

        int ans = 0; // Holds the total count of arithmetic subarrays.

        // Loop through each element to find all possible arithmetic subarrays starting from that element.
        for (int i = 0; i < nums.size(); ++i) {
            int diff = 0, startIndex = i, subarrayLength = 2;

            // Ensure there's enough room to calculate a difference.
            if (startIndex + 1 < nums.size())
                diff = nums[startIndex + 1] - nums[startIndex];
            
            startIndex++;

            // Extend the subarray while the difference between consecutive elements is constant.
            while (startIndex + 1 < nums.size() && nums[startIndex + 1] - nums[startIndex] == diff) {
                subarrayLength++;
                startIndex++;
                // Update the outer loop's index to the end of the current subarray to avoid redundancy.
                i = startIndex;
            }

            // Update the count of arithmetic subarrays if the length is 3 or more.
            if (subarrayLength >= 3) {
                // The idea behind the following formula:
                // There are (n - 2) subarrays for length 3, (n - 1) subarrays for length 4...
                // (n - 2) + (n - 1) + ... + 3 + 2 + 1 = (n - 2) * (n - 1) / 2
                // So, there should be this many subarray with length >= 3 within an array of length n
                ans += (subarrayLength - 2) * (subarrayLength - 1) / 2;
            }
        }
        return ans;
    }
};
