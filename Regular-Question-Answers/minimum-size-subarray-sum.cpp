// Author: Berke Dönmez
// Problem Link: https://leetcode.com/problems/minimum-size-subarray-sum/

/*
    Solution 1: O(n)

    We can maintain two pointers l and r representing the left and the right endpoints of the subarray.
    Since every element is positivte, when we move r to the right, the sum increases.
    Similarly, when we move l to the right, the sum decreases.
    These two properties show us that when we move r to the right, we don't ever need l to move to the left.
    It's because when the sum gets increased because of r, all we would want is decrease the sum as long as it's
    greater than or equal to the target.

    Fun fact: this method is literally called the "two pointers" method :D (a.k.a. sliding window)
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int n = nums.size();

        /*
            We can increase r one by one with a for loop, and while doing that,
            increase l as much as possible by another while loop.
            So, there are actually two independent loops iterating separately -- one for each pointer.
        */

        /*
            To store the answer, we should maintain a variable.
            It's initial value should be something unreachably large enough so that:
                1- We can later check if no subarray is found.
                2- It's not less than the largest possible answer, which is n.
            I chose n+1 but you can choose anything larger than n, e.g., INT_MAX.
        */
        int ans = n + 1;
        int l = 0;   // Left pointer representing the left endpoint of the sliding subarray.
        int sum = 0; // The sum of subarray nums[l..r]. Thanks to the constraints, it can be at most 10^9 that fits in int.
        for (int r = 0; r < n; r++) {
            // Increment r one by one, and each time, update the sum.
            sum += nums[r];

            /*
                While the sum without the leftmost element in the subarray isn't less than the target,
                increment l. This minimizes the subarray length ending at r.
            */
            while (sum - nums[l] >= target) {
                sum -= nums[l++]; // We used post-increment: first use the current value, then increment.
            }

            // Whether sum is greater than or equal to the target should be checked.
            // For each r, we update the answer if it needs to be updated.
            if (sum >= target)
                ans = min(ans, r - l + 1);
        }

        // Here is how we check whether there exists any subarray!
        if (ans > n)
            ans = 0;

        return ans;
    }
};

/*
    Solution 2: O(n * log(n))

    Instead of maintaining two pointers, this solution focuses on finding the largest j for each position i such that:
        1- j < i
        2- nums[j] + nums[j+1] + ... + nums[i] >= target

    Notice that we can use prefix sums for the second condition:
        prefix_sum[i] - prefix_sum[j-1] >= target

    Since every element is positive, prefix sums are always increasing.
    This allows us to binary search j -> this is where log(n) comes from.
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int n = nums.size();
        int ans = n + 1, l = 0, sum = 0;

        /*
            We define prefix_sum as 1-indexed where prefix_sum[0] represents the empty prefix whose sum is 0.
            This prevents us from accessing the (-1)-th element: prefix_sum[j-1].
            Strongly recommended! :)
        */
        vector<int> prefix_sum(n + 1); // Every element is initialized to 0 even if we don't write it explicitly.
        for (int i = 0; i < n; i++) {
            prefix_sum[i + 1] = prefix_sum[i] + nums[i];

            // The maximum value to subtract in order to have subarray sum >= target.
            int target_to_subtract = prefix_sum[i + 1] - target;

            /*
                We search within [0..i] for the prefix sum closest to target_to_subtract.
                Since we want the largest j s.t. prefix_sum[j] <= target_to_subtract,
                we find the smallest j s.t. prefix_sum[j] > target_to_subtract with upper_bound,
                then go back to the previous index by subtracting 1.

                Since we search within [0..i] and upper_bound takes the right endpoint as exclusive,
                we pass prefix_sum.begin() + i + 1.

                Cheatsheet:
                    1- lower_bound(x) is the leftmost element <= x.
                    2- upper_bound(x) is the leftmost element > x.
            */
            int target_index = upper_bound(prefix_sum.begin(), prefix_sum.begin() + i + 1, target_to_subtract) - prefix_sum.begin();
            target_index--; // Now it's the largest j s.t. prefix_sum[j] <= target_to_subtract.

            /*
                However, there might not be any suitable j. This can happen when prefix_sum[i+1] itself is smallar than the target.
                In this case, we'll have target_index = -1.
                I left the "why" part to you. Figure it out yourselves! :)
            */
            if (target_index >= 0)
                ans = min(ans, i + 1 - target_index);
        }
        if (ans > n)
            ans = 0;
        return ans;
    }
};