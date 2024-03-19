// Author: Mehmet Tolga kýlýnçkaya
// Reviewer:
// Question Link: https://leetcode.com/problems/single-element-in-a-sorted-array

// Time Complexity  -> 0(n) , Space Complexity -> 0(1)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // Check if the input array has only one element; if so, return that element.
        if (nums.size() == 1) {
            return nums[0];
        }

        // Iterate through the array by increments of 2, checking for non-duplicate elements.
        for (int i = 0; i < nums.size(); i += 2) {
            // Compare the current element with the next element.
            if (nums[i] != nums[i + 1]) {
                // Return the current element if it's not a duplicate.
                return nums[i];
            }
        }

        // If no non-duplicate element is found, return an invalid value (-1 in this case).
        return -1;
    }
};
