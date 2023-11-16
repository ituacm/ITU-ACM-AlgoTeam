// Author: Rojen Arda Şeşen
// Question Link: https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/
// Reviewer: Denis Davidoglu

class Solution {
   public:
    bool kLengthApart(vector<int>& nums, int k) {
        // Initializing a counter from -1
        // The counter will be set to 0 when we first encounter a '1' on the vector nums.
        int counter = -1;
        for (auto& num : nums) {
            if (num) {  // If current number is 1
                // If the distance is smaller than k and current '1' is not the first
                // '1' on the vector, we return false.
                if (counter >= 0 && counter < k) return false;
                // On each '1' encounter, we reset the counter
                counter = 0;
            }
            // We count the distance between ones by incrementing the counter on '0' encounter.
            else if (counter >= 0)
                counter++;
        }
        // If all distances are valid, we return true.
        return true;
    }
};
