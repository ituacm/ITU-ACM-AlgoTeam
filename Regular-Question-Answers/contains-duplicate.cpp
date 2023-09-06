// Author: Mehmet Tolga kýlýnçkaya
// Reviewer:
// Question Link: https://leetcode.com/problems/contains-duplicate/

//time complexity -> O(n^2) (Brute Force)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Get the size of the input vector.
        int n = nums.size();

        // Iterate through the vector to check for duplicates.
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                // Compare the elements at indices i and j.
                if (nums[i] == nums[j])
                    // Return true if a duplicate is found.
                    return true;
            }
        }
        // If no duplicates are found after checking all pairs, return false.
        return false;
    }
};
