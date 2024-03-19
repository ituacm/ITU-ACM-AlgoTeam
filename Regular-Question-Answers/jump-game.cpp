// Author: Ali Emre Kaya
// Reviewer: Fatih Baskın
// Question Link: https://leetcode.com/problems/jump-game/

// Time Complexity: O(n)
// Space Complexity: O(1)

/*
The problem gives us an array which has numbers, those numbers represent the maximum jump.
We will try to reach the end of the list with using this jumps.
Note that you can never go back since nums[i] >= 0 for every i.
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // if size of the array 1, directly return true
        if(nums.size() == 1) return true;

        // each array element can be visit at most one time, so time complexity is O(n)
        // curr_idx is current index you're standing at
        for(int curr_idx = 0; curr_idx < nums.size();){
            // these variables will keep track of the maximum jump, reachable from the current index.
            int best_jump = 0;
            int best_jump_idx = curr_idx;

            // for loop will iterate over potential jumps from (curr_index) to (curr_index + nums[curr_idx])
            for(int reach_idx = curr_idx + 1; reach_idx <= curr_idx + nums[curr_idx]; reach_idx++){
                // if reachable jump is reachs furher than current jump, update variables
                if(reach_idx + nums[reach_idx] > best_jump){
                    best_jump = reach_idx + nums[reach_idx];
                    best_jump_idx = reach_idx;
                    // check if new jump can reach the end of the array
                    if(best_jump >= nums.size() - 1){
                        return true;
                    }
                }
            }
            // control if no jump can be made from the current position
            if (best_jump_idx == curr_idx) {
                return false;
            }
            
            // update current index to the best jump index found
            curr_idx = best_jump_idx;
        }
        // if you can't access the end of array return false
        return false;
    }
};
