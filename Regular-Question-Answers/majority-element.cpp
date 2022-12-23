// Author: Emre ÇELİK
// Question Link: https://leetcode.com/problems/majority-element/
// Reviewer: Denis Davidoglu

// Time Complexity : O(nlogn)
// Space Complexity : O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Array can be first sorted to make alike elements adjacent 
        sort(nums.begin(), nums.end());
        
        // If the majority elements appears more than n/2 times,
        // no matter where they begin, there will always be one
        // in the middle of sorted array.
        return nums[(nums.size()/2)];
    }
};
