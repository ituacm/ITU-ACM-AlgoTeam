// ITU ACM AlgoTeam
// Author: Novruz Amirov
// Question link: https://leetcode.com/problems/search-insert-position/
// Reviewer: Denis Davidoglu

class Solution {
   public:
    /*
        This is the binary search implementation question,
        because of O(logN) time complexity given in the question.

        Basically, in binary search we have 2 pointers left and right;
        left should always must be smaller or equal to right.
        The array should be in sorted as given in the question.
    */
    int searchInsert(vector<int>& nums, int target) {
        // declaring left and right pointers
        int left = 0;
        int right = nums.size() - 1;

        // left must be smaller or equal to right pointer
        while (left <= right) {
            // checking mid results in logN time complexity
            int mid = (left + right) / 2;

            if (nums[mid] == target)
                return mid;  // target was found
            else if (nums[mid] < target)
                left = mid + 1;  // target must be in right of mid
            else
                right = mid - 1;  // target must be in left of mid
        }

        // if not found in given array
        return left;

        /*
            Overall Time Complexity: O(LogN)
            Space Complexity: O(1)
        */
    }
};
