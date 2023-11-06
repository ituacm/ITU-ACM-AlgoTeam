// Author: Ali Emre Kaya
// Reviewer: Kemal Tahir Bıcılıoğlu
// Time Complexity: O(m + n)
// Space Complexity: O(1)
// Question Link: https://leetcode.com/problems/merge-sorted-array/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idx1 = m - 1; // Pointer for nums1.
        int idx2 = n - 1; // Pointer for nums2.
        int idx = m + n - 1; // Pointer for add number.

        // Two-pointer method in valid indexes.
        // Arrangement on nums1.
        while(idx1 >= 0 && idx2 >= 0) {

            // Add the larger number to end of the nums1.
            if(nums1[idx1] >= nums2[idx2]) {
                nums1[idx] = nums1[idx1];
                idx--;
                idx1--; 
            } else {
                nums1[idx] = nums2[idx2];
                idx--;
                idx2--;
            }
        }
        
        // When numbers in nums1 are exhaused but nums2 still has some numbers,
        // add remaining numbers from nums2 to beginning of nums1.
        while(idx2 >= 0) {
            nums1[idx] = nums2[idx2];
            idx--;
            idx2--;
        }
    }
};