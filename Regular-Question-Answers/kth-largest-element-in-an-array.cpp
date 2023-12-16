// Author: Ahmet Furkan Kavraz
// Question Link: https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // this function works as quicksort partition function
        // it selects a pivot and separates arrays into to half,
        // one piece contains smaller elements than pivot, other contains bigger elements
        nth_element(nums.rbegin(), nums.rbegin() + k - 1, nums.rend(), greater<int>());

        // return the result
        return nums[nums.size() - k];
    }
};