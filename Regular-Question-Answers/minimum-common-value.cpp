//Author: Ayşe Sarı
// Problem Link:https://leetcode.com/problems/minimum-common-value/ 
// Two pointers approach
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int a = nums1.size();  // Use size() instead of length() to get the size of vectors
        int b = nums2.size();
        int i = 0, j = 0;  // Initialize i and j

        while (i < a && j < b) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else if (nums1[i] == nums2[j]) {
                return nums1[i];
            }
        }

        return -1;  // Return -1 if no common element is found
    }
};
