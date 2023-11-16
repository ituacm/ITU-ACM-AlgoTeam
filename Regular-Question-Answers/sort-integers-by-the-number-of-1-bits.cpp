// Author: Murat Biberoğlu
// Question Link: https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
// Reviewer: Denis Davidoglu

class Solution {
   public:
    vector<int> sortByBits(vector<int> &arr) {
        merge_sort(arr, 0, arr.size() - 1);
        return arr;
    }

    // updated merge funtion
    void merge(vector<int> &nums, int const l, int const mid, int const r) {
        // Get sizes of sub arrays
        int len1 = mid - l + 1;
        int len2 = r - mid;

        // create space for subarrays
        int *subarr1 = new int[len1];
        int *subarr2 = new int[len2];

        // copy the values of sub arrays
        for (int i = 0; i < len1; i++) {
            subarr1[i] = nums[i + l];
        }
        for (int i = 0; i < len2; i++) {
            subarr2[i] = nums[mid + 1 + i];
        }

        int index1 = 0;
        int index2 = 0;
        int array_index = l;

        // make comparision and merge the array
        while (index1 < len1 && index2 < len2) {
            // create bitsets of numbers
            bitset<14> b1(subarr1[index1]);
            bitset<14> b2(subarr2[index2]);

            // if the first number has less ones than the second number, put the first number to sorted array
            if (b1.count() < b2.count()) {
                nums[array_index] = subarr1[index1];
                index1++;
            }
            // if the first number has more ones than the second number, put the second number to sorted array
            else if (b1.count() > b2.count()) {
                nums[array_index] = subarr2[index2];
                index2++;
            }
            // if the first and the second numbers have equal number of ones, then put the smaller one to sorted array
            else {
                if (subarr1[index1] < subarr2[index2]) {
                    nums[array_index] = subarr1[index1];
                    index1++;
                } else {
                    nums[array_index] = subarr2[index2];
                    index2++;
                }
            }
            array_index++;
        }

        // fill the remaining part if any
        while (index1 < len1) {
            nums[array_index] = subarr1[index1];
            index1++;
            array_index++;
        }
        while (index2 < len2) {
            nums[array_index] = subarr2[index2];
            index2++;
            array_index++;
        }

        delete[] subarr1;
        delete[] subarr2;
    }

    // regular merge sort function
    void merge_sort(vector<int> &nums, int const l, int const r) {
        if (l >= r) return;

        int mid = (l + r) / 2;
        merge_sort(nums, l, mid);
        merge_sort(nums, mid + 1, r);
        merge(nums, l, mid, r);
    }
};
