// Author: Novruz Amirov
// Question Link: https://leetcode.com/problems/binary-search/
// Reviewers: Emre Çelik, Denis Davidoglu

/*
    Problem Description:
        We are given a SORTED vector, and a Target value,
        and we need to find if the given Target number
        is already given in vector or not. We need to
        find it in time complexity of O(log n). It means
        Linear search, which has time complexity of O(n)
        will not work, therefore Binary Search must be used.
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // left pointer, initially points to 0,
        // which is the starting point of vector.
        int left = 0; 
        
        // right pointer, intially points to the end of
        // the vector, which is 1 less than the size of vector.
        int right = nums.size() - 1;
        
        // the vector will be searched untill, left and right
        // pointer meets in middle.
        while (left <= right) { 
            
            // each time mid pointer will be decremented
            // to the size divided by 2, that will cause
            // the time complexity to be log n.
            int mid = (left + right) / 2;
            
            if (nums[mid] == target) { 
                // if target was found, stop the program.
                return mid; 
            }
            else if (nums[mid] > target) {
                // because the vector is sorted, if target is smaller
                // than the mid, then the left part will be searched.
                right = mid - 1;
            }
            else {
                // because the vector is sorted, if target is greater 
                // than the mid, then the right part will be searched.
                left = mid + 1;
            }
        }
        
        return -1; // the program comes here only when the target was not found.
        
        // The Time Complexity of the program is: O(log n).
        // The Space Complexity of the program is: O(1).
    }
};
