

// Author: Hilal Parlakçı
// Reviewer: Selman Demir
// Question Link: https://leetcode.com/problems/rotate-array


/------------ Solution1 --------------/

// This solution uses additional space to store the rotated array.
// It involves creating a new array and filling it with the elements
// from the original array in the desired rotated order.
// This approach is straightforward but requires extra space proportional
// to the size of the input array.

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        
        k = k % n;
        // When k is a multiple of n, a full rotation of the array occurs, meaning it returns to its original state.
        // That's why we take the modulo to avoid unnecessary rotations.
        
        if (n < 2 || k == 0) return;
        // If the size of the array is 1 or less, any rotation will not affect the original position of the array elements.
        // Additionally, we check if there is a request for rotation by verifying whether k is 0.
        
        vector<int> ans;
        // Temporary array to store the rotated result.
        
        // nums = [1, 2, 3, 4, 5, 6, 7], k = 3
        
        // Collect the last 'k' elements from the array.
        for (int i = n - k; i < n; i++) {
            ans.push_back(nums[i]);
        }
        // ans: [5, 6, 7]
        
        // Collect the first 'n - k' elements and append them to the result.
        for (int i = 0; i < n - k; i++) {
            ans.push_back(nums[i]);
        }
        // ans: [5, 6, 7, 1, 2, 3, 4]
        
        // nums: [1, 2, 3, 4, 5, 6, 7]
        nums.swap(ans);
        // Swaps the content of the original array with the temporary array in O(1) time complexity.
    }
};


/------------ Solution2 --------------/

// This solution optimizes space usage by performing the rotation in-place.
// It reverses parts of the array to achieve the desired rotation without
// needing additional space.

// Time Complexity : O(n)
// Space Compexity : O(1)


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        // When k is a multiple of n, a full rotation of the array occurs, meaning it returns to its original state.
        // That's why we take the modulo to avoid unnecessary rotations.
        
        if (n < 2 || k == 0) return;
        // If the size of the array is 1 or less, any rotation will not affect the original position of the array elements.
        // Additionally, we check if there is a request for rotation by verifying whether k is 0.

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
        
        /* 
         Example:
         nums = [1, 2, 3, 4, 5, 6, 7] , k = 3
         -> rotated nums = [5, 6, 7, 1, 2, 3, 4]
         
         1. Reverse the entire array to bring the end elements to the beginning.
         
            [7, 6, 5, 4, 3, 2, 1]
            
            * We can split the array into two parts at the kth element to get a clear vision.
         
            [7, 6, 5, // 4, 3, 2, 1]
         
            * We can see that both the back and front parts are reversed versions of the target rotated array.
         
            * To get the correct rotation we only need to reverse both back and front part individually.
         
         2. Reverse the first k elements.
         
            [5, 6, 7  // 4, 3, 2, 1]
         
         3. Reverse the remaining n - k elements.
         
            [5, 6, 7 , 1, 2, 3, 4 ]  Rotated array achieved.
         
        */
        
    }
};
