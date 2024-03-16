// Author: Ali Emre Kaya
// Reviewer:
// Question Link: https://leetcode.com/problems/jump-game/

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // if size of the array 1, directly return true
        if(nums.size() == 1) return true;

        // current index you're standing at
        int i = 0;
        // each array element can be visit at most one time
        //so time complexity is O(n)
        while (i < nums.size()) {
            // these variables will keep track of the maximum jump 
            //reachable from the current index (i).
            int best_jump = 0;
            int best_jump_idx = i;

            // for loop will iterate over potential jumps from i to i + nums[i]
            for(int j = i + 1; j <= i + nums[i]; j++){
                // if j jump is reachs furher than current jump,
                //update variables
                if(j + nums[j] > best_jump){
                    best_jump = j + nums[j];
                    best_jump_idx = j;
                    // check if new jump can reach the end of the array
                    if(best_jump >= nums.size() - 1){
                        return true;
                    }
                }
            }
            // control if no jump can be made from the current position
            if (best_jump_idx == i) {
                return false;
            }
            
            // update i to the best jump index found
            i = best_jump_idx;
        }
        // if you can't access the end of array return false
        return false;
    }
};
