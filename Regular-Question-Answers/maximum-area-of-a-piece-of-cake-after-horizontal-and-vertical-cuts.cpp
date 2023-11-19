// Author: Berke Dönmez
// Problem Link: https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/
// Reviewer: Denis Davidoglu

/*
    Solution: O(n * log(n) + m * log(m)) (n = horizontalCuts.length, m = verticalCuts.length)

    Every piece of cake can be identified with two consecutive horizontal and two consecutive vertical cuts.
    Two cuts are considered consecutive if there is no other cut in between.
    So, there are (n+1) * (m+1) pieces of cake.

    To maximize the piece's area, we can focus on finding the maximum difference between every two consecutive cuts (separately for both directions).
    Then, the answer will be the product of the two maximum differences (one for vertical, one for horizontal).

    However, the initial orders of cuts (the input orders) aren't necessarily increasing/decreasing, which is why we should first sort them.
    Hence the complexity.
*/
class Solution {
public:
    int maxConsecutiveDiff(vector<int> &cuts) {
        int max_diff = 0;
        for (int i = 1; i < cuts.size(); i++)
            max_diff = max(max_diff, cuts[i] - cuts[i - 1]);
        return max_diff;
    }
    int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts) {
        /*
            To ease the implementation (handing the first and the last cuts), we also consider the sides of the original cake
            as cuts, and insert them into the arrays.
        */
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int mod = 1e9 + 7;

        /*
            Notice how we used 1ll to convert the expression's result to 64 bits.
            You could also use casting: (long long) ...
            Or, you can even change the result type of maxConsecutiveDiff to long long instead of int.

            I wouldn't recommend the last option, though. It's because when you are sure the result fits in 32 bits,
            I consider it more understandable to declare the narrowest type.
            Yet, even I sometimes do that to make sure EVERYTHING works perfectly :D
        */
        return 1ll * maxConsecutiveDiff(horizontalCuts) * maxConsecutiveDiff(verticalCuts) % mod;
    }
};
