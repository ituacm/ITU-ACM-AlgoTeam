// Author: Ali Emre Kaya
// Reviewer: Ali Kemal Coşkun

// Time Complexity = O(n)
// Space Complexity = O(1)
// Question Link = https://leetcode.com/problems/container-with-most-water/

/*
Use the 2 pointer method, keep the first and last index,
    multiply the index difference between them by the smaller value
    and put them in temp_area.
Compare these indexes with each other and replace
    the index of the smaller one with the index next to it,
    because we are trying to find the largest area,
    and we can find this by keeping the larger length constant
    and changing the length of the smaller one.
An example;
    height = [1,8,6,2,5,4,8,3,7] for these heights, queries will be:
    (1,7) - (8,7) - (8,3) - (8,8) - (6,8) - (2,8) - (5,8) - (4,8) - (equal-indexes)
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int idx_left = 0;                   // head index
        int idx_right = height.size() - 1;  // tail index
        int h_left = height[idx_left];      // height of the head
        int h_right = height[idx_right];    // height of the tail
        int width = idx_right - idx_left;

        // area will hold the maximum area
        int area = 0;
        while (width != 0) {
            int temp_area;

            // temp area to hold current area
            temp_area = min(h_left, h_right) * width;

            // arranging area
            if (temp_area > area) {
                area = temp_area;
            }

            // arranging indexes and height
            if (h_left > h_right) {
                idx_right--;
                h_right = height[idx_right];
            } else {
                idx_left++;
                h_left = height[idx_left];
            }

            // arranging width according to new indexes
            width = idx_right - idx_left;
        }

        return area;
    }
};