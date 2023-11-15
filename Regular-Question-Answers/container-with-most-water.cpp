// Author: Ali Emre Kaya

// Time Complexity = O(n)
// Space Complexity = O(1)
// Question Link = https://leetcode.com/problems/container-with-most-water/

/*
Use the 2 pointer method, keep the first and last index, 
    multiply the index difference between them by the smaller value 
    and put them in temp_area.
Compare these indexes with each other and replace 
    the index of the smaller one with the index next to it.
Do this steps until indexes are same.
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int idx_left = 0; // head index
        int idx_right = height.size()-1; // tail index
        int h_left = height[idx_left]; // height of the head
        int h_right = height[idx_right]; // height of the tail
        int width = idx_right - idx_left;

        // area will hold the maximum area
        int area = 0;
        while(width != 0){
            int temp_area;
            
            // temp area to hold current area
            temp_area = min(h_left, h_right) * width;

            // arranging area
            if(temp_area > area){
                area = temp_area;
            }

            // arranging indexes and height
            if(h_left > h_right){
                idx_right--;
                h_right = height[idx_right];
            }
            else{
                idx_left++;
                h_left = height[idx_left];
            }

            // arranging width acording to new indexes
            width = idx_right - idx_left;
        }

        return area;
    }
};