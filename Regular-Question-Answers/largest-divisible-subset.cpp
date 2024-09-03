// Author: Racha Badreddine
// Reviewer:
// Question Link: https://leetcode.com/problems/largest-divisible-subset/

// Time Complexity Analysis: O(n^2)
// Sorting has O(n log n) complexity but is neglected 
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // Sort the array 
        sort(nums.begin(), nums.end());

        // Variable to store the array size
        int size = nums.size();

        // Vector to hold the largest divisible subsets starting at each index i
        vector<vector<int>> dp(size);

        // Vector to hold the largest divisible subset
        vector<int> result;

        // Iterate through elements starting from the end
        for(int i = size - 1; i >= 0; i--) {

            // The smallest divisible subset contains the element itself
            dp[i].push_back(nums[i]);

            // Iterate through the elements larger than the current one
            for(int j = i + 1; j < size; j++) {

                // If the element is divisible AND if adding the current element to the subset already stored in the jth element is larger than our current subset 
                if(nums[j] % nums[i] == 0 && (dp[j].size() + 1 > dp[i].size())) {
                    // Copy the subset to the current element
                    dp[i] = dp[j];
                    // Insert the ith element to the beginning of the subset
                    dp[i].insert(dp[i].begin(), nums[i]);
                }
            }

            // If the current subset is larger than the previous one, copy it to the result
            if(dp[i].size() > result.size()) result = dp[i];
        }

        // Return the largest divisible subset
        return result;
    }
};

