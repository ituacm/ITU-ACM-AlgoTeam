// Author: Ceren Yaşar
// Question Link: https://leetcode.com/problems/jump-game-ii/
// Reviewer: Denis Davidoglu

// Time Complexity: O(N*M) where N = nums.length and M = nums[i]
// Space Complexity: O(N)

class Solution {
   public:
    int jump(vector<int>& nums) {
        // jumps[i] stores the current minimum number of jumps to reach index i.
        // It is initialized with INT_MAX - 1 to make correct comparisons at the first assignment to each index.
        // Subtraction of 1 from INT_MAX ensures that there will be no overflow in line 34.
        vector<int> jumps(nums.size(), INT_MAX - 1);

        // Our current position, index 0, requires 0 steps to reach.
        jumps[0] = 0;

        for (int i = 0; i < nums.size(); i++) {
            // Number in nums[i] denotes the maximum number of allowed jumps from that position.
            // The furthest point you will be able to reach from index i is (i + nums[i]).
            // This means that you have a possible landing range of [1, nums[i]].
            int maxJumps = nums[i];

            // Iterating over every possible movement, i.e. from jumping 1 step ahead to jumping maxJumps steps ahead.
            for (int j = 1; j <= maxJumps; j++) {
                // If the current position index exceeds the limits, break out of the loop to avoid segmentation fault.
                if (i + j >= nums.size()) break;

                // We now know that it is possible to reach the index (i+j) with jumps[i]+1 number of jumps. To ensure
                // that we always store the minimum value so far, we should compare the number we have with the number that
                // is already stored for the location i+j, which is jumps[i+j].
                jumps[i + j] = min(jumps[i + j], jumps[i] + 1);
            }
        }

        // Because the problem statement guarantees that it is possible to reach jumps[nums.size()-1]; it is certain
        // that after the loop above, jumps[nums.size()-1] will store the minimum number of jumps to reach the last index.
        return jumps[nums.size() - 1];
    }
};
