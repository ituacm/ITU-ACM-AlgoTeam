// Author: Rojen Arda Şeşen
// Question Link: https://leetcode.com/problems/russian-doll-envelopes/
// Reviewer: 

// Time Complexity: O(nlogn)
// Space Complexity: O(n)

/**************************************************************************************************

    The question requires us to fit the envelopes within each other. In order for an envelope to fit
    within another envevlopes, its dimensions must be strictly smaller than the oter. This question
    is similar to the longest increasing subsequence problem. We can sort the envelopes in ascending order
    with respect to their widths and in descending order with respect to their heights and apply the 
    "patience sorting" algorithm on the sorted list to aquire the longest increating subsequence. The
    reason why we sort the envelopes in reverse orders is because we want to find the longest increasing
    subsequence of the heights of the envelopes. 
    An example:
    
    envelopes = [[5,4],[6,4],[6,7],[2,3]]
    Sort the envelopes in ascending order with respect to their widths and in descending order with
    respect to their heights:
    sorted_envelopes = [[2,3],[5,4],[6,4],[6,7]]
                           ^     ^     ^     ^
    [3, 4, 4, 7] -> LIS of this array is [3, 4, 7] -> LIS of envelopes: [[2,3], [5,4], [6,7]]
    Now that the width are in ascending order, finding the longest increasing subsequence of the heights
    will lead us to the answer of the problem. In order the find the LIS, we use the patience sorting
    algorithm. In each step, we check if there the current height can be placed on the bottom of a stack.
    Leftmost stack with a bottom value greater than the current value is the adequate stack. If there
    is no such a stack, we create a new stack with the current height, else we place the height to the
    bottom of the found stack. The number of stacks is the answer of the problem. Search of the adequate
    stack can be done with binary search. This way, in each step we can find the adequate stack in O(logn)
    and in total the time complexity of the algorithm will be O(nlogn).
    More information on the patience sorting algorithm:
    - https://leetcode.com/discuss/general-discussion/1129459/patience-sorting-dp-optimisation
    - https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=&cad=rja&uact=8&ved=2ahUKEwi4_oTopKD-AhXZX_EDHSa3DdcQFnoECBAQAQ&url=https%3A%2F%2Farxiv.org%2Fpdf%2F0705.4524&usg=AOvVaw3VoMMqYM-XbMzPKBJ6jiTG

***************************************************************************************************/

class Solution {
    int binarySearch(vector<int>& arr, int target) {
        // Creating left and right indices for binary search
        int left = 0, right = arr.size() - 1;
        // Loop terminates when the left index is greater than the right index
        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] == target)
                return mid;
            // If the target is on the right side of the mid, we update the left index
            else if (target > arr[mid])
                left = mid + 1;
            // If the target is on the left side of the mid, we update the right index
            else 
                right = mid - 1;
        }
        return left;
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Sorting the envelopes in ascending order with respect to their widths and in descending order
        // with respect to their heights
        sort(
            envelopes.begin(),
            envelopes.end(),
            // Using a lambda function to compare the envelopes
            // Lambda function returns the comparison of the 2nd indices if the 1st
            // indices are equal, else it returns the comparison of the 1st indices
            [](const vector<int>& a, const vector<int>& b) {
                return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
            }
        ); // O(nlogn)
        // Creating a vector to store the bottom values of each stack
        // We only need the bottom values of the stacks since we do the comparison based on bottom values
        vector<int> dp;
        for (int i = 0; i < envelopes.size(); i++) {
            int index = binarySearch(dp, envelopes[i][1]); // O(logn)
            // If current value can't fit on a stack, we create a new stack
            if (index == dp.size())
                dp.push_back(envelopes[i][1]);
            // Else we place the current value to the bottom of the found stack
            else {
                dp[index] = envelopes[i][1];
            }
        }
        // Returning the size of the stack, i.e. length of the LIS, as mentioned above.
        return dp.size();
    }
};