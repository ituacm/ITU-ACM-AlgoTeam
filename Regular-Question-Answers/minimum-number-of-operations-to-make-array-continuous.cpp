/*
 * Author: Ceren Yaşar
 * Question Link: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/
 * 
 * Time Complexity: O(N * logN)
 * Space Complexity: O(N)
 * 
 * Here is the intuition for this problem:
 * If we want to make the minimum number of operations, we must find the maximum
 * number of numbers that we can keep.
 * Now let's examine the restrictions given in the question:
 * 1) Resulting array must consist of unique elements. If the array size is N, there will be N different numbers.
 * 2) The difference between the maximum element and the minimum element is N - 1 (N denotes size of the array)
 * So, if we know the minimum element, we can find the maximum of this resulting array.
 * Assume minimum is X: maximum will be X + N - 1
 * All the elements in between will be larger than X and less than X + N - 1.
 * There is one thing to notice here:
 * Since there are N elements, and we know two of them, we must find the remaining
 * N - 2 elements. We know the range of them. In order to fit N - 2 numbers into the 
 * range (X, X + N - 1), we must start counting from X until X + N - 1 and increment
 * by 1 at a time. Our resulting array doesn't have to be sorted, but if it was, this would 
 * be how it looked like. We want to transform the given array into this form, and in order to achieve
 * that in minimum number of operations, we must find the maximum length continuous sequence and
 * change the remaining ones.
 */

class Solution {
public:
    int minOperations(vector<int>& nums) {
        // sort the array to make it possible to compute maximum length continuous array
        sort(nums.begin(), nums.end());

        // in order to store only unique elements, we will use a hashmap and a vector
        unordered_map<int, bool> used_numbers;
        vector<int> unique_numbers;

        // this is the current maximum length of continuous subarray
        int max_sequence = 0;

        // the loop below is used to push unique elements of nums in sorted order
        for (int i: nums) {
            if (used_numbers[i]) continue;

            unique_numbers.push_back(i);
            used_numbers[i] = true;
        }

        // loop through unique numbers to compute maximum length continuous sequence
        for (int i = 0; i < unique_numbers.size(); i++) {
            // for each number in unique_numbers, we consider two cases:
            // 1) unique_numbers[i] can be the maximum number in the continuous array.
            // using this assumption, we compute the minimum number of the resulting array (low).
            // 2) unique_numbers[i] can be the minimum number in the continuous array.
            // using this assumption, we compute the maximum number of the resulting array (high).
            int low = unique_numbers[i] - nums.size() + 1, high = unique_numbers[i] + nums.size() - 1;

            // find positions in unique_numbers for low and high values
            int low_pos = lower_bound(unique_numbers.begin(), unique_numbers.end(), low) - unique_numbers.begin();
            int high_pos = lower_bound(unique_numbers.begin(), unique_numbers.end(), high) - unique_numbers.begin();
            
            // adjust positions if out of bounds
            if (high_pos >= unique_numbers.size()) high_pos = unique_numbers.size() - 1;
            if (low_pos < 0) low_pos = 0;
            
            // update high_pos to fit the range correctly
            while (unique_numbers[high_pos] > high) high_pos--;
            while (high_pos < unique_numbers.size() - 1 && unique_numbers[high_pos + 1] == high) high_pos++;
            
            // update max_sequence with the maximum continuous sequence length
            max_sequence = max(max_sequence, max((i - low_pos + 1),(high_pos - i + 1)));
        }

        // return the minimum number of operations required to transform the array
        return nums.size() - max_sequence;
    }
};
