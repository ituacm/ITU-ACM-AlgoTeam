// Author: Berke Dönmez
// Problem Link: https://leetcode.com/problems/sum-of-floored-pairs/
// Reviewer: Denis Davidoglu

/*
    Solution: O(M * log(M)) (M = max(nums))

    If we try to implement what is asked straightforward, it will obviously take O(n^2) operations.
    Well, that isn't feasible at all. We should somehow approach more efficiently.

    Take a look at the constraints:
        - 1 <= nums[i] <= 10^5
    Why is the upper bound so small?
    Of course, there is a reason. In fact, this constraint is both necessary and enough to solve the problem.

    Think about the floor function a bit.
    What floor does to a fraction p/q is that it ignores the remainder of p divided by q.
    Let's explain this in more detail:
        Suppose p = k*q + r where 0 <= r < q -- r is the remainder.
        Then, p/q = (k*q + r)/q. Here, what produces the integer part of p/q is k*q.
        The remainder r produces the fractional part. So, floor ignores r and assumes
        the numerator is just k*q.
        As a result, when k is fixed, changing r doesn't change floor(p/q).
        The following terms are all equal to k:
            - floor(k*q / q), floor((k*q + 1) / q), floor((k*q + 2) / q), ..., floor((k*q + q-1) / q)
        floor((k+1)*q / q) follows the last term, and it's equal to k+1.

        So, when we fix k and q, we know that there are q consecutive denominators that
        make the result k.
        Here is where the constraint becomes really, really helpful:
            We can find the total number of elements in nums that are equal to one of these
            q consecutive denominators. Since they are consecutive, we can do this very efficiently
            using prefix sums.
        Let cnt[i] be the number of elements up to i.
        We can fill in this prefix sum array in O(n). Then, the number of elements within
        [k*q, k*q + q-1] can be found by cnt[k*q + q-1] - cnt[k*q - 1].
        Don't get confused -- it's just how we use prefix sums: cnt[r] - cnt[l-1].
        Also, take into account the number of q's in nums:
            - For a fixed (k, q) pair, the number of floors equal to k is
              (cnt[q] - cnt[q-1]) * (cnt[k*q + q-1] - cnt[k*q - 1]).

        OK, this part is efficient, but what about the number of fixed (k, q) pairs?
        Yes, we can't avoid iterating over q's up to the maximum element.
        However, we need k to be at most floor(MAX / q) because beyond that, k*q is larger than the
        maximum element. Thus, it's totally safe to ignore the rest of the k's.
        Well, the sum of floor(MAX / q)'s converges MAX (1 + 1/2 + ... + 1/MAX) = MAX * log(MAX) (harmonic series).
        This is why it's all efficient!
*/
class Solution {
   public:
    int sumOfFlooredPairs(vector<int> &nums) {
        const int mod = 1e9 + 7;

        // You can find the maximum element as follows.
        // Of course, a for loop is always there as an option!
        int mx = *max_element(nums.begin(), nums.end());

        // The prefix sum array -- cnt[i] = number of elements that are at most i.
        vector<int> cnt(mx + 1);

        // First, process each element to obtain the non-prefix sum version of the array.
        for (int n : nums) cnt[n]++;

        // Then, convert it to a prefix sum array.
        for (int i = 1; i <= mx; i++) {
            cnt[i] += cnt[i - 1];
        }

        // Fun fact: If I'm not wrong, the actual result cannot exceed 64 bits.
        long long res = 0;

        // Iterate over q's.
        for (int q = 1; q <= mx; q++) {
            int n_elements_equal_q = cnt[q] - cnt[q - 1];

            // This isn't required at all, but decreases the run time dramatically!
            if (!n_elements_equal_q) continue;

            /*  [Consider these as floor divisions]
                (k*q) / q, (k*q + 1) / q, ..., ((k+1)*q - 1) / q
                Each equals k!
            */
            for (int k = 1; k * q <= mx; k++) {
                res += 1ll * k * n_elements_equal_q * (cnt[min(mx, (k + 1) * q - 1)] - cnt[k * q - 1]);
            }
        }
        return res % mod;
    }
};
