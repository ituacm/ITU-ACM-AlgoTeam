// Author: Berke Dönmez
// Problem Link: https://leetcode.com/problems/count-array-pairs-divisible-by-k/

// Time Complexity: O(MAX * log(MAX)) where MAX is the greatest integer in `nums`
// Space Complexity: O(MAX)

// Hey, there's actually more than one solution to this problem!
// However, I've explained a single one... The others are up to you to think about. :)

// Actually, let's make it a challenge, right?
// Find a different solution, then share it with us! We might surprise you with some gifts to congratulate, should I?

class Solution {
  public:
    long long countPairs(vector<int> &nums, int k) {
        // Take the greatest integer from `nums`.
        const int MAX = *max_element(nums.begin(), nums.end());

        // Construct a count array that stores the number of occurrences of numbers in `nums`.
        vector<int> cnt(MAX + 1);
        for (int n : nums)
            cnt[n]++;

        // This will store the total number of multiples of each number within [1, MAX] in `nums`.
        vector<int> cnt_multiples(k + 1, -1);

        // The number of pairs of different integers, and the number of pairs of same integers, respectively.
        long long cnt_different = 0, cnt_same = 0;

        // Assume we want to count ordered (x, y) value pairs s.t. x * y is divisible by k, instead of unordered (i, j)
        // index pairs. We can iterate over x's (which I named as `num`), and find the number of y's. This method would
        // count each index pair exactly twice where x != y, and each index pair exactly one where x = y. This is why
        // we'd like to count them separately (`cnt_different` and `cnt_same`).
        for (int num = 1; num <= MAX; num++) {
            // Looking for the number of y's s.t. num * y / k is an integer.
            // Notice that if num / k is simplified to (num / g) / (k / g) where g = gcd(num, k), then y must be
            // divisible by k / g. That's all!

            // May use the builtin GCD function.
            int g = __gcd(num, k);
            int m = k / g;

            // Calculate cnt_multiples[m] if it hasn't been yet. This is an important condition that affects the time
            // complexity.
            // Note: you can also completely fill in `cnt_multiples` with a separate "sieve" loop (where you
            // would go through the multiples of each integer from 1 to MAX). This is "just a bit" faster.
            if (cnt_multiples[m] == -1) {
                cnt_multiples[m] = 0;
                for (int x = m; x <= MAX; x += m) {
                    cnt_multiples[m] += cnt[x];
                }
            }

            // (In English) The number of (num, y) pairs where num != y and y is a multiple of m.
            // Notice how I didn't use an `if` statement, but used the condition to multiply by.
            cnt_different += (long long)(cnt_multiples[m] - cnt[num] * (num % m == 0)) * cnt[num];

            // This is where we should count the number of (num, num) pairs. Since we want to take different indices,
            // we use the C(cnt[num], 2) formula.
            if ((long long)num * num % k == 0)
                cnt_same += (long long)cnt[num] * (cnt[num] - 1) / 2;
        }

        // You get it, right? If not, please re-read the explanations above. :)
        return cnt_different / 2 + cnt_same;
    }
};