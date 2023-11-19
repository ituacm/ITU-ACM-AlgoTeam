// Author: Bilgenur Çelik
// Reviewer: Ahmet Furkan Kavraz
// Question Link: https://leetcode.com/problems/3sum/

// time comp. -> O(n^2)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Sort the Array = O(n log(n))
        sort(nums.begin(), nums.end());

        // Base case 1
        if (nums.size() < 3) {
            return {};
        }
        // Base case 2 -> target is 0 and cant be achieved with positive 3 integers.
        if (nums[0] > 0) {
            return {};
        }
        // to store results:
        vector<vector<int>> result;

        // for every integer in nums = O(n)
        for (int i = 0; i < nums.size(); i++) {
            // Base case 2
            if (nums[i] > 0) {
                break;
            }
            // for repeated numbers continue, thus process below is skipped and i is increased;
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            // Make two pointers high and low
            int low = i + 1, high = nums.size() - 1;

            // Search between two pointers,
            while (low < high) {  // O(n)
                // compare (sum of i'th low'th and high'th elements) to 0
                int sum = nums[i] + nums[low] + nums[high];

                // if sum is greater than 0 to decrese sum, decrese high
                if (sum > 0) {
                    high--;
                }
                // if sum is smaller than 0 to increase sum, increase low
                else if (sum < 0) {
                    low++;
                }
                // if sum == 0:
                else {
                    // push the found triplet vector to result.
                    result.push_back({nums[i], nums[low], nums[high]});

                    // To avoid duplicate triplets, navigate to last occurences of num[low] and num[high] respectively
                    int last_low_occurence = nums[low];
                    int last_high_occurence = nums[high];

                    // But check the condition from outer loop which is (low < high) also
                    // if there are multiple nums[low] values, skip them
                    while (low < high && nums[low] == last_low_occurence) {
                        low++;
                    }
                    // if there are multiple nums[low] values, skip them
                    while (low < high && nums[high] == last_high_occurence) {
                        high--;
                    }
                }
            }
        }
        // Return the result vector
        return result;
    }
};
