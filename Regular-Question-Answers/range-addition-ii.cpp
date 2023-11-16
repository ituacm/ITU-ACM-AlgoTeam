// Author: Berke Dönmez
// Problem Link: https://leetcode.com/problems/range-addition-ii/
// Reviewer: Denis Davidoglu

class Solution {
   public:
    int maxCount(int m, int n, vector<vector<int>> &ops) {
        /*
            Notice that every operation affects the top left cell (matrix[0][0]), so this cell will
            contain the maximum integer.
            Therefore, the problem actually boils down to finding the number of cells
            that get incremented after every operation, just like matrix[0][0].

            How to find such cells?

            An operation [a_i, b_i] affects the cells within the rows [1, a_i] and the columns [1, b_i].
            So, for a cell (x, y) to get incremented after each operation, the following must hold:
                x <= a_1 && x <= a_2 && x <= a_3 && ... && x <= a_(ops.length)
                y <= b_1 && y <= b_2 && y <= b_3 && ... && y <= b_(ops.length)

            Note that for a number to be less than or equal to each number in a group,
            it's enough for this number to be less than or equal to the minimum number in that group.
            Therefore, the following are enough for us:
                x <= min(a_i)
                y <= min(b_i)

            We actually solved the problem by now :D
            Just find the minimums of a_i and b_i. The number of (x, y)'s will then be the product.
        */

        /*
            When finding the "minimum" in a problem, we'd better initialize the variable
            that will eventually store the minimum to a value large enough, e.g., equal to the
            upper bound of numbers to process (or larger).

            For this purpose, we often use INT_MAX (or LLONG_MAX if we're dealing with 64-bit integers)
            for the initial value.
            However, in this problem, we may just prefer n and m because they are the upper bounds for operations.
            It's up to you to choose! :)
        */
        int min_n = n, min_m = m;

        /*
            When we feel too lazy to write the actual type (in this case, vector<int>),
            we can just use the keyword "auto" in C++. The compiler will infer the type for us!

            C++ <3
        */
        for (auto &op : ops) {
            int a = op[0], b = op[1];
            min_m = min(min_m, a);
            min_n = min(min_n, b);
        }
        return min_n * min_m;
    }
};
