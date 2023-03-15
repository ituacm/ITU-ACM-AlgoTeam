// Author: Berke Dönmez
// Problem Link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
// Reviewer: Denis Davidoglu

/*
    Solution: O(n) (n = nums.length)

    If we focus on the equality of the elements and not the final value that all will be equal to,
    we can use the following idea:
        By incrementing all but one element, we relatively decrement the excluded element.
    It's safe to think of this because we only care about relative differences.
    Incrementing n-1 elements does not change differences between these elements, it only changes the difference between
    them and the excluded element by 1.
    What decrementing does is exactly the same!

    So, how many decrements do we need to make all elements equal?
    Trivially, we wouldn't want to decrement the minimum element because it also forces all other elements to be decremented,
    and this might not be required if we don't decrement the minimum element. All this would cause is extra cost!

    If we aren't going to decrement the minimum element, then the only option is to make all other elements equal to the
    minimum element :D

    Hence the solution: the sum of the differences between the minimum element and every other element.
*/
class Solution {
public:
    int minMoves(vector<int> &nums) {
        /*
            The function "min_element" returns an iterator to an element with the smallest value (might be multiple).
            Then, using the "*" operator, we can access the value!

            You can also use a single loop to find the minimum value:
                int minimum_value = nums[0];
                for (int num: nums)
                    minimum_value = min(minimum_value, num);
        */
        int minimum_value = *min_element(nums.begin(), nums.end());
        int ans = 0;
        for (int num : nums)
            // It always holds that num >= minimum_value, no need to use abs.
            ans += num - minimum_value;

        return ans;
    }
};
