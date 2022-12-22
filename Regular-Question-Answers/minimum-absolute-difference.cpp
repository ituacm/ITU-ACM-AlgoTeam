// Author: Rojen Arda Şeşen
// Question Link: https://leetcode.com/problems/minimum-absolute-difference/
// Reviewer: Denis Davidoglu

// We will first sort the given array.
// Since the array is sorted, minimum difference will be one of the
// differences between adjacent elements.

// Time Complexity --> O(nlogn) (Sorting --> O(nlogn), Looping --> O(n))
// Space Complexity --> O(k), where k is the number of pairs with minimum difference.

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int minDiff = INT_MAX;  // Minimum Difference
        vector<vector<int>> minDiffPairs;   // Pairs with the minimum difference.

        sort(arr.begin(), arr.end());   // Sorting the array.

        for (int i = 1; i < arr.size(); i++)
            // Updating minDiff if we encounter a smaller difference.
            if (arr[i] - arr[i - 1] < minDiff)
                minDiff = arr[i] - arr[i - 1];

        // Adding pairs with the minimum absolute difference to the list.
        for (int i = 1; i < arr.size(); i++)
            if (arr[i] - arr[i - 1] == minDiff)
                minDiffPairs.push_back({arr[i- 1], arr[i]});

        return minDiffPairs;
    }
};
