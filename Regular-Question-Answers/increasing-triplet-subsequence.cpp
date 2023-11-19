// Author: Fatih Çakır
// Question Link: https://leetcode.com/problems/increasing-triplet-subsequence/

// Time comp -> O(n)
// Space comp -> O(1)

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;   // Initialize with the maximum possible value
        int second = INT_MAX;  // Initialize with the maximum possible value

        for (int num : nums) {
            if (num <= first) {  // Smallest number of triplet subsequence
                first = num;
            } else if (num <= second) {  // Second number of triplet subsequence
                second = num;
            } else {  // Third number of triplet subsequence
                // Found a triplet subsequence: nums[i] < nums[j] < nums[k]
                return true;
            }
        }

        // No triplet subsequence found
        return false;
    }
};
