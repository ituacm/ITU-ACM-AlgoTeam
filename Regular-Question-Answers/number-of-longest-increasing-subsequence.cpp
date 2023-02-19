// Author: Berke Dönmez
// Problem Link: https://leetcode.com/problems/number-of-longest-increasing-subsequence/

class Solution {
public:
    int findNumberOfLIS(vector<int> &nums) {
        /*
            The constraints allow us to implement an O(n^2) algorithm.
            Let lis_length[i] be the length of the longest increasing subsequence ending at position i.
            Let number_of_lis[i] be the number of LISs ending at position i.

            To find lis_length[i], we can iterate over all previous positions j (j < i) and whenever we encounter such j satisfying nums[j] < nums[i],
            lis_length[j] + 1 is a candidate for lis_length[i]. It corresponds to appending nums[i] to a LIS ending at j -- a LIS ending at i can be formed as so.

            To find number_of_lis[i], while iterating over j's (nums[j] < nums[i]), we can do the following:
                1- If lis_length[j] + 1 == lis_length[i], then we should also count those new LISs formed by adding nums[i] to the LISs ending at j, that is, increase number_of_lis[i] by number_of_lis[j].
                2- If lis_length[j] + 1 > lis_length[i], then we have longer LISs now. Instead of adding their count to number_of_lis[i], we must reset number_of_lis[i] to number_of_lis[j].
        */

        int n = nums.size();
        int max_lis_length = 0; // Length of the final LISs
        int ans = 0;

        // Initially, every element itself forms a LIS, hence the initial values of 1's.
        vector<int> lis_length(n, 1);
        vector<int> number_of_lis(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                /*
                    Instead of putting everything inside an extra scope like this:
                    if(nums[i] > nums[j]){
                        ...
                    }

                    Write the opposite condition and continue if it holds.
                */
                if (nums[i] <= nums[j])
                    continue;

                int candidate_lis_length = lis_length[j] + 1;
                if (lis_length[i] < candidate_lis_length) {
                    lis_length[i] = candidate_lis_length;
                    number_of_lis[i] = number_of_lis[j]; // Reset because LIS is longer now
                } else if (lis_length[i] == candidate_lis_length) {
                    number_of_lis[i] += number_of_lis[j]; // Increase
                }
            }
            max_lis_length = max(max_lis_length, lis_length[i]);
        }

        /*
            Finally, we should re-iterate over all positions because each can be the ending position of a LIS.
            For instance, think about nums = [1, 1, 1].
        */
        for (int i = 0; i < n; i++) {
            if (max_lis_length == lis_length[i])
                ans += number_of_lis[i];
        }
        return ans;
    }
};