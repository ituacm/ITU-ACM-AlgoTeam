// Author: Berke Dönmez
// Problem Link: https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered/
// Reviewer: Denis Davidoglu

/*
    Solution 1: O(N * right) where N = ranges.length

    We can maintain a boolean array is_covered that tells us whether integers within [1, right] are covered by
    at least one range. Initially, every integer is uncovered, that is, is_covered[i] = false.

    Then, for every range [start, end], we can mark points within the range as covered.
    To optimize a bit, we can start marking from max(start, left) and end at min(right, end),
    because we don't care about any integer outside [left, right].
    For every range, this takes at most "right - left + 1" number of operations, hence the time complexity.

    After taking care of ranges, we can check whether any integer within [left, right] remained uncovered.
*/
class Solution {
public:
    bool isCovered(vector<vector<int>> &ranges, int left, int right) {
        /*
            Defining is_covered as 1-indexed is more convenient.
            It'll prevent possible confusions such as:
                - "Wait, what does is_covered[i] represent?"
                - "Which element should I update to mark the integer x: x-1 or x?"
            This way, everything is more straightforward: is_covered[x] tells whether x is covered.
            On the other hand, since given ranges are inclusive, there's no need to adjust the boundaries of for loops
            to suit a 0-indexed array.

            Tip: vector<bool> initializes to false, no need to declare explicitly!
        */
        vector<bool> is_covered(right + 1);
        for (auto &range : ranges) {
            int start = range[0], end = range[1];

            /*
                The optimization here (max(start, left) and min(right, end))
                also prevents out-of-bounds error and thus, is safer!
            */
            for (int cur = max(start, left); cur <= min(right, end); cur++)
                is_covered[cur] = true;
        }

        // Check whether any integer within [left, right] remained uncovered.
        for (int cur = left; cur <= right; cur++)
            if (!is_covered[cur]) return false;
        return true;
    }
};

/*
    Solution 2: O(N + right) where N = ranges.length

    We can actually optimize the first part that takes care of given ranges, marks integers within them as covered.

    Instead of marking as covered, we can calculate how many ranges cover every integer.
    Of course, this can be done via maintaining an integer array instead of boolean, and incrementing the number of ranges
    that cover a point instead of marking as covered. But, this would lead to the same time complexity.

    The trick here is to focus on the starting and ending points of ranges:
        The range [start, end] starts at "start", covers all integers until "end", finishes covering at "end+1".

    Let's call the array storing the number of ranges covering integers [1, right] "n_ranges_covering".
    Initially, n_ranges_covering[i] = 0 for all i.

    For every range [start, end], we can increment n_ranges_covering[start] and decrement n_ranges_covering[end+1]:
        n_ranges_covering[start]++;
        n_ranges_covering[end+1]--;
    Why "end+1" instead of "end"?
    Because note that "end" is also covered. This range "starts uncovering" (ends covering) at "end+1".

    This trick is essential for interval problems. Very useful to know about!

    Two operations per range lead to a total of 2 * N operations = O(N) complexity.

    After we do this for all ranges, the number of ranges covering i is the following sum:
        n_ranges_covering[1] + n_ranges_covering[2] + ... + n_ranges_covering[i]
    Because whenever a range starts, we should include it. Similarly, when a range ends, we should exclude it.

    As you can see, this is straightforward prefix sum, which can be calculated in O(right)!
*/
class Solution {
public:
    bool isCovered(vector<vector<int>> &ranges, int left, int right) {
        vector<int> n_ranges_covering(right + 1);
        for (auto &range : ranges) {
            int start = range[0], end = range[1];

            // These if's are necessary that prevent going out of bounds!
            if (start <= right)
                n_ranges_covering[start]++;
            if (end + 1 <= right)
                n_ranges_covering[end + 1]--;
        }

        // Stands for the number of ranges covering the current point. It's the variable that stores the prefix sum :)
        int cur_n_ranges = 0;

        /*
            Notice that we started from 1 but not "left".
            This way, we guarantee counting intervals start before "left".
            This is necessary for accurate prefix sum calculation!
        */
        for (int i = 1; i <= right; i++) {
            cur_n_ranges += n_ranges_covering[i];
            if (left <= i && !cur_n_ranges) return false;
        }
        return true;
    }
};
