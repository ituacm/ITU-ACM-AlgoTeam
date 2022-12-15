// Author: Ceren Yaşar
// Question Link: https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/
// Reviewer: Denis Davidoglu

// Time Complexity: O(m * n * log(k))
// m = nums1.size(), n = nums2.size()
// Space Complexity: O(k)

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, pair<int, int>>> pq;
        // our max heap will hold {sum, {number1, number2}}, sum denoting number1 + number2.
        // using a max heap, we will compare the top sum value with existing sum value and consequently will find
        // the k smallest sums at the end of all iterations

        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                int sum = nums1[i] + nums2[j];

                if (pq.size() < k) {
                    // if we haven't collected k values yet, we can safely assume that our sum value is one of the minimums so far
                    pq.push({sum, {nums1[i], nums2[j]}});
                } else if (sum < pq.top().first) {
                    // if we have collected k values in max heap but current sum is less than what we have on top of the heap, we can replace them
                    pq.pop();
                    pq.push({sum, {nums1[i], nums2[j]}});
                } else {
                    // if we have collected k values in pq and the current sum we have is not less than the top value in pq, we can break the loop
                    // because it is impossible to get a sum less than the current one in the next iterations (since both arrays are sorted)
                    break;
                }
            }
        }

        vector<vector<int>> result(pq.size());
        
        // our max heap holds the maximum sum value on top, but we need to store them in non-decreasing order
        // so we start assigning from the last element of our result array
        for (int i = result.size() - 1; i >= 0; i--) {
            result[i] = {pq.top().second.first, pq.top().second.second};
            pq.pop();
        }

        return result;
    }
};
