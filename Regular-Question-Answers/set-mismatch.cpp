// Author: Berke Dönmez
// Problem Link: https://leetcode.com/problems/set-mismatch/
// Reviewer: Denis Davidoglu

/*
    I've prepared two different solutions.
    The second one is recommended!
*/

class Solution {
   public:
    vector<int> findErrorNums(vector<int> &nums) {
        /******************
            Solution 1
            Time Complexity: O(n * log(n)) (sorting)
        ******************/
        /*
            First, sort the numbers to get them in the form of {1, 2, ..., n}.
            Besides, sorting never hurts :D It eases our thinking.
        */
        sort(nums.begin(), nums.end());

        /*
            Then, there is going to be exactly one position, p, at which nums[p] != p+1. (0-indexed)
            It's because exactly one element is repeated, thus, exactly one element gets affected.
            Moreover, the repeated element is either at position p-1 or p+1, because note that we have a sorted array!
            Therefore, finding the duplicate element is easy: just find the adjacent elements with the same value.
        */
        int n = nums.size();
        int duplicate = -1;
        for (int i = 1; i < n; i++)
            if (nums[i] == nums[i - 1]) {
                duplicate = nums[i];
                break;
            }

        /*
            Now, how to find the missing number?
            We can find it by how much the overall sum changed:
            Suppose the missing number is m, and the duplicate is d.
            The original sum was n * (n+1) / 2.
            This gets changed by d - m. We can subtract this from d to get m.
        */
        int original_sum = n * (n + 1) / 2;                         // Since n <= 10**4, overflow can't occur.
        int current_sum = accumulate(nums.begin(), nums.end(), 0);  // You may prefer loops!
        int diff = current_sum - original_sum;
        int missing = duplicate - diff;

        /******************
            Solution 2
            Time Complexity: O(n)
        ******************/
        /*
            Each element is in the range [1, n], which enables us to use an array to store the number counts.
            The duplicate number occurs 2 times whereas the missing number occurs 0 times.
        */

        /*
        vector<int> occurrences(n+1);
        for (int num: nums)
            occurrences[num]++;

        int duplicate, missing;
        for (int i = 1; i <= n; i++) {
            if (!occurrences[i]) missing = i;
            if (occurrences[i] == 2) duplicate = i;
        }
        */

        return {duplicate, missing};
    }
};
