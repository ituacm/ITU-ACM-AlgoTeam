// Author: Emre ÇELİK
// Question Link: https://leetcode.com/problems/majority-element/
// Reviewers:

// Time Complexity : O(n)
// Space Complexity : O(1)

//   If nums.size()%2==0
//      | | | |
//          ^ this is important for us
//   If nums.size()%2==1
//      | | | | |
//          ^ this is important for us

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Firstly we are sorting our vector to find
        //the mid number if nums.size() is odd or 
        //mid+1 number if nums.size() is even.
        sort(nums.begin(), nums.end());
        //Return our data with (nums.size()/2)th index,
        //while we are working with 0 index.
        return nums[(nums.size()/2)];
    }
};