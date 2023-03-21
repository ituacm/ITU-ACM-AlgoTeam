// Author: Berke Dönmez
// Problem Link: https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/

/*
    Solution: O(n) (n = target.length)

    Think in the opposite direction: make all elements zero by decrementing subarrays.
    (It helped me figuring out the solution :D)

    Each time, we would want to decrement one of the widest subarrays that doesn't
    contain any zeros. Here, "widest" means not extendable in neither direction
    (no non-zero elements outside).

    For instance, the following array contains 3 widest subarrays:
        [1, 2, 1, 0, 0, 3, 0, 1]
         -------        -     -
            1           2     3

    "We would want to decrement one of the widest subarrays."
    This is optimal because decrementing a smaller subarray can't be more optimal, since
    the operations performed on smaller subarrays could be combined into a single operation somehow.

    So, if we repeat this operation until all elements become zero, the answer is the number of operations performed.

    However, the issue is that after applying an operation to a subarray, the subarray
    might get split into several smaller subarrays because of zeros (which were 1's before the operation).
    Therefore, after each operation, the number of subarrays should be calculated again.
    This leads to approximately O(n * M) complexity where M is the largest element.
    This complexity isn't desirable.

    (Maybe there is some nice way to do this calculation, but I couldn't figure out any.)

    We can make some observations here.
    When would these splits take place?
    A subarray gets split when its local minimums (elements smaller than its neighbors)
    become zero.
    Note that if a subarray doesn't contain a local minimum, it won't ever split. Such subarrays
    look like a mountain if we imagine the elements as heights:

                                    ||
                              || || || ||
                              || || || || || ||
                           || || || || || || || ||
                        || || || || || || || || ||

    It's non-increasing in both directions with respect to the maximum height.
    They don't split but rather melt from both sides.

    On the other hand, a subarray "melts away" when all of its elements were equal to 1 before
    applying an operation.
    Realize that those last elements standing were once local maximums, and after the nearest
    local minimums became zero, the local maximums became the "peak"s of their "mountain"s.
    So, actually, the values of local maximums are enough to determine when their subarrays
    will completely melt away.

    In short, there are two types of elements to keep track of:

        1- Local minimums (smaller than both neighbors) -- they determine when a subarray will get split. Actually, they indicate the maximum number of operations to apply on multiple local maximums.
        2- Local maximums (larger than both neighbors) -- they determine when their mountain will melt away. They indicate the number of operations needed to melt their mountain.

    Finding only these types of elements is enough to solve the problem!
*/
class Solution {
public:
    int minNumberOperations(vector<int> &target) {
        int n = target.size();

        // First, find the indices of local maximums.
        vector<int> local_max_ids;
        for (int i = 0; i < n; i++) {
            /*
                It should be either the first element, the last element or
                greater than both neighbors.
                Actually, including equality helps for the next step!
            */
            if (!i || i + 1 == n || target[i] >= target[i - 1] && target[i] >= target[i + 1]) {
                local_max_ids.push_back(i);
            }
        }

        /*
            Notice that a local minimum is the minimum element between two consecutive local maximums.
            This fact is exactly what we use to find local minimums.

            How to find the answer?
            First, sum up the values of local maximums.
            Then, decrease the number of operations using local minimums, that is,
            apply some operations on multiple local maximums instead of a single local maximum.
        */
        int n_local_maxes = local_max_ids.size();
        int ans = target[local_max_ids[0]];
        for (int i = 1; i < n_local_maxes; i++) {
            // This is for the first step: summing up local maximums.
            ans += target[local_max_ids[i]];

            /*
                Find the minimum element (which is the local minimum) between the current and
                the previous local maximums.
            */
            int min_between = target[local_max_ids[i]];
            for (int j = local_max_ids[i]; j >= local_max_ids[i - 1]; j--) {
                min_between = min(min_between, target[j]);
            }

            /*
                This is for the second step: decrease operations by merging.
                "min_between" number of operations applied on the current local maximum
                can be merged with the operations applied on previous local maximums.
            */
            ans -= min_between;
        }

        return ans;
    }
};