// Author: Fatih Baskın
// Reviewer:
// Question Link: https://leetcode.com/problems/single-number/

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        // If we sort the numbers, twice repeated numbers will occupy two integer wide space side by side.
        // ex:
        // numbers: 1 1 3 3 4 5 5
        // indexes: 0 1 2 3 4 5 6
        //                  ^
        // As can be seen above, singe number will break the trend of side by side same numbers.
        // Same numbers are located at 2*i'th and 2*i + 1'th indexes, i < n / 2.
        // Single number will break this trend, so we will look for this trend breaker.

        // Sorting operation takes log(n) time and checking for single number takes n/2 time, so complexity is O(log(n)).

        // Edge case, nums have only 1 element.
        if (nums.size() == 1)
            return nums[0];

        // Sort the nums vector.
        sort(nums.begin(), nums.end());

        // We need to have the curr_idx as current index starting from 0 and last_idx as last index of the nums vector.
        int last_idx = nums.size() - 1;
        int curr_idx = 0;
        while (curr_idx < last_idx)
        {
            // If the loop breaks, curr_idx would be the index of the trend breaker single number.
            if (nums[curr_idx] != nums[curr_idx + 1])
                break;
            // If current index obeys the trend, continue by adding 2, skipping the number next to it which is equal to current number.
            curr_idx += 2;
        }

        return nums[curr_idx];
    }
};