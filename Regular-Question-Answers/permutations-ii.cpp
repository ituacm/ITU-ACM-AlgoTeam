// Author: Ayşe Sarı
// Link: https://leetcode.com/problems/permutations-ii/description/
class Solution {
public:
    // This function calculates unique permutations in the given integer vector.
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        generateUniquePermutations(0, nums, result);
        return result;
    }

private:
    void generateUniquePermutations(int index, vector<int>& nums, vector<vector<int>>& result) {
        if (index == nums.size()) {
            result.push_back(nums);  // Add the current permutation to the result vector.
            return;
        }

        map<int, bool> used;  // Create a map to keep track of used elements.
        for (int i = index; i < nums.size(); ++i) {
            if (used[nums[i]]) {
                continue;  // Avoid using the same element again.
            }

            used[nums[i]] = true;  // Mark this element as used.
            swap(nums[index], nums[i]);  // Generate permutation by swapping elements.
            generateUniquePermutations(index + 1, nums, result);  // Process other elements recursively. O(N!) complexity
            swap(nums[index], nums[i]);  // Restore elements to their original positions.
        }
    }
};
