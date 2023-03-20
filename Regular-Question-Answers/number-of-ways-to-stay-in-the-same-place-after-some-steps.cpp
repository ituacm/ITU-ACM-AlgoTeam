// Author: Berke Dönmez
// Problem Link: https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/

/*
    Solution: O(steps * min(arrLen, steps))

    The main idea is to maintain a dp array representing the number of ways to arrive at each point.
    The state transitions are:
        - Move left.
        - Move right.
        - Stay.
    It's all detailed inside the implementation.

    Have fun! :)
*/
class Solution {
    // The modulus value provided in the statement.
    const int mod = 1e9 + 7;

    // A convenient helper. Works faster than the modulo operator (%)!
    void add(int &a, int b) {
        a += b;
        if (a >= mod)
            a -= mod;
    }

public:
    int numWays(int steps, int arrLen) {
        /*
            The furthest reasonable position is half the number of steps, because
            we must go back to 0 afterward.
            However, arrLen might not allow us to go that far.
            This is why we take their min!
        */
        int furthest_proper_position = min(arrLen - 1, steps / 2);

        /*
            dp[i] = number of ways to go arrive at position i.
            dp actually has an extra state representing the current step.
            However, since we only care about the previous step,
            we can maintain an extra array ("ndp" below), and update it using the
            dp array for the previous step ("dp" itself).

            That is, "dp" represents the s-th step, and "ndp" represents the
            (s+1)-th step.
        */
        vector<int> dp(furthest_proper_position + 1);

        // We start at 0, so initially there's 1 way to arrive at position 0.
        dp[0] = 1;

        // Repeatedly compute the dp of the next step "steps" number of times.
        while (steps--) {

            /*
                This is the dp array representing the next step.
                It's all initialized to zero, because we'll use the previous step's
                states to fill in.
            */
            vector<int> ndp(furthest_proper_position + 1);

            // For each position pos, calculate ndp[pos].
            for (int pos = 0; pos <= furthest_proper_position; pos++) {
                /*
                    Three options:
                        1- Come here from left (move right).
                        2- Come here from right (move left).
                        3- Stay.

                    Note that these options must be performable.
                    For instance, you can't use the first option for pos = 0.
                    Hence, the if statements.
                */

                // First option
                if (pos > 0)
                    add(ndp[pos], dp[pos - 1]);

                // Second option
                add(ndp[pos], dp[pos]);

                // Third option
                if (pos + 1 <= furthest_proper_position)
                    add(ndp[pos], dp[pos + 1]);
            }

            /*
                After this, dp represents the state for the current step.
                For the next step, it will represent the previous step.

                Note: "dp = ndp" is O(n) whereas dp.swap(ndp) is O(1) (swaps pointers)!
            */
            dp.swap(ndp);
        }

        return dp[0];
    }
};

/*
    This solution solves a different version of the problem,
    where you are allowed to go to negative positions (those on the left of 0).

    I finished coding it, and then realized I solved a different problem :DD
*/
class Solution {
    // The modulus value provided in the statement.
    const int mod = 1e9 + 7;

    // A convenient helper. Works faster than the modulo operator (%)!
    void add(int &a, int b) {
        a += b;
        if (a >= mod)
            a -= mod;
    }

public:
    int numWays(int steps, int arrLen) {
        /*
            The furthest reasonable position is half the number of steps, because
            we must go back to 0 afterward.
            However, arrLen might not allow us to go that far.
            This is why we take their min!
        */
        int furthest_proper_position = min(arrLen, steps / 2);

        // -furthest_proper_position ... furthest_proper_position
        int n_positions = 2 * furthest_proper_position + 1;

        vector<int> dp(n_positions);

        /*
            We use index_offset for mapping negative positions to proper index values.
            A suitable value for index_offset is the absolute value of the leftmost position,
            which is furthest_proper_position.

            With index_offset, we map the position range:
                [-furthest_proper_position, furthest_proper_position]
            to the index range:
                [0, 2*furthest_proper_position]

            You could prefer hashmap, though.
            However, arrays are the fastest! Use arrays whenever you can.
        */
        int index_offset = furthest_proper_position;
        dp[index_offset] = 1; // The index "index_offset" corresponds to position 0.

        while (steps--) {
            vector<int> ndp(n_positions);
            for (int pos = -furthest_proper_position; pos <= furthest_proper_position; pos++) {
                // "index" is within [0, n_positions).
                int index = pos + index_offset;
                if (index > 0)
                    add(ndp[index], dp[index - 1]);
                add(ndp[index], dp[index]);
                if (index + 1 < n_positions)
                    add(ndp[index], dp[index + 1]);
            }
            dp.swap(ndp);
        }

        return dp[index_offset];
    }
};