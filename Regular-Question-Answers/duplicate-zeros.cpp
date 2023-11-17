// Author: Denis Davidoglu
// Question Link: https://leetcode.com/problems/duplicate-zeros/

/* To get a linear time complexity O(n), instead of doing an        *
 * in-place algorithm, we can allocate memory for a second array,   *
 * which will be the result.                                        */

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> arr2;

        /* We fill the second array as long as it's size is less    *
         * than the original array's size.                          */
        for (int i = 0; arr2.size() < arr.size(); i++) {
            // Copy one element from the original array
            arr2.push_back(arr[i]);

            // If at this step arr2 has the needed size, loop breaks
            if (arr2.size() >= arr.size()) break;

            /* If the loop doesn't break and if the current element *
             * arr[i], which was already added, is zero, then zero  *
             * is added once again, thus every zero gets duplicated.*/
            if (arr[i] == 0) arr2.push_back(0);
        }

        // With no return in this function, result is written to arr
        arr = arr2;
    }
};
