// Author: Toygun Görmüş
// Question Link : https://leetcode.com/problems/next-permutation/
// Reviewers: Bilgenur Çelik, Denis Davidoglu

/* Using two pointers will be efficient in this problem.
The two pointers will point to the first not sorted element and the first greater element after it. 
Thus, by swapping these numbers and sorting the rest of the array from the first not sorted element should yield the next permutation.  */

class Solution {
public:
    void nextPermutation (vector<int>& nums) {
        // If the array has only one element, the next permutation is itself. 
        if (nums.size() == 1) return;
    
        // We use l pointer to detect first not sorted element.
        int l = nums.size()-2;
        while (nums[l] >= nums[l+1]) {
            // Checking if the array is descending. If so, the reverse of the array is the next permutation.
            // (i.e. Input: nums = [3,2,1] Output: [1,2,3])
            if (l == 0) {
                reverse(nums.begin(), nums.end());
                return;
            }
            l--;   
        }
    
        // We use r pointer to detect the first greater element than left
        int r = nums.size()-1;
        while (nums[l] >= nums[r]) r--;
    
        // Swapping the numbers at indexes l and r to find the next permutation in lexicographical order
        swap(nums[l], nums[r]);
        // Sorting the rest of the array yields the answer
        sort(nums.begin()+l+1, nums.end());
    }
};

