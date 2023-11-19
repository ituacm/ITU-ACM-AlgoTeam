// Author: Ceren Yaşar
// Reviewers: Fatih Baskın, Ömer Faruk Erdem, Denis Davidoglu
// Question Link: https://leetcode.com/problems/unique-paths/

// Time Complexity: O(m*n)
// Memory Complexity: O(m*n)

class Solution {
    int calculatePaths(int x, int y, vector<vector<int>>& mem) {
        /*
         * Base Case:
         * Think of an m*n grid:
         * There is only one way to reach position (1, 1).
         * To reach (1, 2), you should take one step down.
         * To reach (1, m), you should take m-1 steps down.
         * Hence, there is only one way to reach the positions with
         * m value 1. The same goes for n values as well.
         */
        if (x == 1 || y == 1)
            return 1;

        /*
         * We can only move right or down.
         * If we are at position (a, b), there are two possibilities to consider:
         * our previous step was either right or down.
         * So all possible ways to reach (a, b) should be the summation of these
         * two possibilities: (a-1, b) + (a, b-1)
         * Here, we compute these values if not previously computed. This method of
         * remembering what we have computed so far is called memoization.
         */
        if (!mem[x - 1][y])
            mem[x - 1][y] = calculatePaths(x - 1, y, mem);
        if (!mem[x][y - 1])
            mem[x][y - 1] = calculatePaths(x, y - 1, mem);

        mem[x][y] = mem[x - 1][y] + mem[x][y - 1];

        return mem[x][y];
    }

public:
    int uniquePaths(int m, int n) {
        // 1-based indexing to avoid confusion
        vector<vector<int>> mem(m + 1, vector<int>(n + 1));

        return calculatePaths(m, n, mem);
    }
};
