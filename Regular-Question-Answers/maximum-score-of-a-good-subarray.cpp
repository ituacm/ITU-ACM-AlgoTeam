// author: Serhat Sarı
// problem link: https://leetcode.com/problems/maximum-score-of-a-good-subarray/description/

/* Solution:
    We will use two pointers. At the beginning both of the pointers will show value in position K.
    We will keep iterating until both left and right pointers reaches the boundaries of the array.
    If left pointer reaches the position 0 we can only move right pointer to right.
    If right pointer isnt on the upper boundary of the array and possible new number on the right is bigger than
    the new possible number on the left side we move right pointer to right. Because we want the minimum number on
    this subarray to be as big as possible.

    At every iteration we will check the new minimum value in the subarray bounded by these 2 pointers.
    And we will calculate the current answer.
    When we leave the while loop our answer will be stored in ans variable.

    Time complexity: O(N).
    Because at every iteration we make one move, either move left pointer to left or right pointer to right.
    And our maximum number of iterations equals to size of the array.
    1 * N = O(N)
*/

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int left = k, right = k;
        int min_val = nums[k];
        int ans = min_val;

        while(left > 0 || right < nums.size()-1){
            if(left == 0 || (right < nums.size() - 1  && nums[right + 1 ] > nums[left - 1]))
                right++;
            else
                left--;

            min_val = min({min_val,nums[left],nums[right]});
            ans = max(ans, min_val * ( right - left + 1 ));
        }
        return ans;
    }
};
