// Author: Berke Dönmez
// Problem Link: https://leetcode.com/problems/arranging-coins/
// Reviewer: Denis Davidoglu

/*
    We want to find the max n_rows such that,
        1 + 2 + 3 + ... + n_rows <= n
    (the difference between these corresponds to the number of coins in the last row.)
    this sum can be simplified as:
        n_rows * (n_rows + 1) / 2 <= n

    There are several different ways to find n_rows, I've prepared three solutions.
    Let's see 'em :)
*/

/*
    Solution 1: O(sqrt(n))
    The sum  n_rows * (n_rows + 1) / 2 is approximately n_rows^2.
    And we want it to get close to n. So, n_rows is going to be close to sqrt(n).

    As a consequence, we can just increment n_rows and check if the inequality holds.
    It takes ~sqrt(n) iterations.
*/
class Solution {
public:
    int arrangeCoins(int n) {
        int n_rows = 0;

        /*
            Since we're dealing with integers, we cast the expression to long long by multiplying by 1ll,
            which stands for 64-bit 1 (1 long long), in order to avoid overflow.
            Though, you may prefer defining n_rows as long long instead of int :D

            Another option is to cast with (ll): (ll) n_rows * (n_rows + 1) / 2.
            Anyway, I prefer 1ll :)
        */
        while (1ll * n_rows * (n_rows + 1) / 2 <= n)
            n_rows++;

        /*
            Now, notice that the answer is actually n_rows - 1, because we incremented it
            as long as the condition held.

            If we want the answer to be n_rows instead, we can change the condition so that
            it checks whether the NEXT n_rows, which is n_rows + 1, satisfies the condition:
            while(1ll * (n_rows + 1) * (n_rows + 2) / 2 <= n) n_rows++;
        */
        return n_rows - 1;
    }
};

/*
    Solution 2: O(log(n))

    As n_rows grows, so does the sum. Therefore, the answer is binary searchable.
    To detail this, we can say that if a value of n_rows satisfies the inequality,
    so do all values less than that value. Similarly, if a value does not satisfy the inequality,
    all values greater than that value also won't satisfy.

    Let's demonstrate this:

    n_rows:     1   2   3   4   ... k   (k+1)   (k+2)   ...
    satisfies:  1   1   1   1   ... 1   0       0       ...

    Our aim is to find k!

    How to apply binary search?
    Maintain two pointers l and r. Initialize them to such values that the answer is definitely
    within [l, r]: 0 and n are suitable!

    Let n_rows = (l+r) / 2. (Actually we need +1, it's explained inside the code.)
    If n_rows satisfies the inequality, then set l = n_rows because we want the answer to stay within [l, r],
    and the answer >= n_rows.
    Otherwise (it doesn't satisfy), set r = n_rows - 1. Because the answer < n_rows.

    Repeat this until l and r become equal. Since we always guarantee the answer to stay within [l, r],
    in the end, l (or r) becomes the answer.
*/
class Solution {
public:
    int arrangeCoins(int n) {
        int l = 0, r = n;
        while (l < r) {
            /*
                So, we set n_rows = (l + r + 1) / 2 instead of (l + r) / 2.
                Why?
                It's just to prevent infinite loop when r = l + 1, and always l = n_rows gets executed.
                You may also use (l + r) / 2 + 1.
            */
            int n_rows = ((long long)l + r + 1) / 2;  // cast to long long to avoid overflow!
            if (1ll * n_rows * (n_rows + 1) / 2 <= n)
                l = n_rows;
            else
                r = n_rows - 1;
        }

        return l;
    }
};

/*
    Solution 3: O(1)

    Let's multiply both sides by 2:
        n_rows * (n_rows + 1) <= 2n

    This implies n_rows is somewhat close to sqrt(2n).
    Just check the neighbouring values to find the actual answer.
*/
class Solution {
public:
    int arrangeCoins(int n) {
        int n_rows = sqrt(2ll * n);  // 2*n might overflow, use 2ll * n or (long long) 2 * n!

        // While n_rows does not satisfy the inequality, decrement.
        while (1ll * n_rows * (n_rows + 1) / 2 > n)
            n_rows--;

        // While n_rows + 1 satisfies the inequality, increment.
        while (1ll * (n_rows + 1) * (n_rows + 2) / 2 <= n)
            n_rows++;

        return n_rows;
    }
};
