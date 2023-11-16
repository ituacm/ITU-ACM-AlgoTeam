// Author: Bilgenur Çelik
// Reviewer: Ahmet Furkan Kavraz
// Question Link: https://leetcode.com/problems/two-sum/

// time comp. = o(n^2)
// initially lets look at this intuitive approach and improve it:
class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> result;

        // check evey sum of (nums[i],nums[k]) pair
        for (int i = 0; i < len - 1; i++) {
            for (int k = i + 1; k < len; k++) {
                // if target is found;
                if (nums[i] + nums[k] == target) {
                    // insert both indicies to resulting array.
                    result.push_back(i);
                    result.push_back(k);
                    // break the inner for loop
                    break;
                }
            }
            // if target was found to break the outer for loop:
            if (result.size() == 2) {
                break;
            }
        }
        return result;
    }
};

// time comp. = O(n)
class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        // unordered_map to store values and the indicies
        unordered_map<int, int> keep;

        // for every integer in nums
        for (int i = 0; i < nums.size(); i++) {  //->o(n)
            int other_number = target - nums[i];

            // search our map for the other_number
            // if found;
            if (keep.find(other_number) != keep.end()) {  // .find(key) -> o(1)
                // in map key was other_number and value was the index of that number in the array.
                int index_other = keep[other_number];
                // insert both indicies to resulting array.
                result.push_back(index_other);
                result.push_back(i);
                break;
            }

            // if not found map is filled with integer value and its index.
            keep[nums[i]] = i;
        }
        return result;
    }
};
