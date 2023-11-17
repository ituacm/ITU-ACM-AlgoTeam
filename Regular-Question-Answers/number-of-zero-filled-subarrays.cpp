// Author: Toygun Görmüş
// Question Link: https://leetcode.com/problems/number-of-zero-filled-subarrays/submissions/
// Reviewers: Hacer Akıncı, Denis Davidoglu

/* We want to find the 0 sequences inside the array and evaluate each of them in terms of subarray numbers.
For example let's think about the 0 sequence [0,0,0]. There are 3 possible zero-filled subarrays containing 1 elements.
Likewise, there are 2 possible zero-filled subarray containing 2 elements. Finally, there is 1 possible zero-filled
subarray that contains 1 element. This pattern is valid for the rest.
*/

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        // We initialize two counters. One is for counting consecutive zeros. One is for counting total subarrays.
        long long zero_count = 0;
        long long subarrays = 0;

        /* As we traverse the array, we increment zero_count while we encounter a zero.
        If it is anything else than a zero, meaning that the sequence has ended, we calculate the sum of numbers
        from 1 to n (where n is the length of zero sequence), then add it to the total subarray count. */
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zero_count++;
            } else {
                subarrays += zero_count * (zero_count + 1) / 2;
                zero_count = 0;
            }
        }
        // We eliminate the case where the array ends with a zero sequence by calculating with zero_count one last time.
        subarrays += zero_count * (zero_count + 1) / 2;
        return subarrays;
    }
};
