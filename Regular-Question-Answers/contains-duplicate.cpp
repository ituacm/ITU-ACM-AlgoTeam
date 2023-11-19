// Author: Mehmet Tolga kýlýnçkaya
// Reviewer:
// Question Link: https://leetcode.com/problems/contains-duplicate/

// time complexity -> O(n)
class Solution {
public:
    // Function to check if a vector contains duplicate elements
    bool containsDuplicate(vector<int>& nums) {
        // Create an unordered set to store the numbers we've seen
        unordered_set<int> seen;

        // Iterate through each number in the vector
        for (int num : nums) {
            // Check if the current number is already in the 'seen' set
            if (seen.count(num) > 0)
                return true;  // If found, return true (a duplicate is present)

            // If not found, add the number to the 'seen' set
            seen.insert(num);
        }

        // If the loop completes without finding duplicates, return false
        return false;
    }
};
