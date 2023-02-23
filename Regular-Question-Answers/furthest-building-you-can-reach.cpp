// Author: Berke Dönmez
// Problem Link: https://leetcode.com/problems/furthest-building-you-can-reach/

/*
    Solution: O(H * log(L)) (H = heights.length, L = number of ladders)

    Let's focus on consecutive height differences instead of the heights themselves.

    No matter how big the difference is, a single ladder can be used to overcome it.
    On the other hand, if we use bricks, the difference affects the number of bricks.
    These two facts highlight that we should use the ladders to overcome the largest differences. This way, we minimize the bricks needed.
    Let's take an example to understand better:
        Let the consecutive differences be [5, 3, 2, 6, 4], and suppose we have 2 ladders and 9 bricks.
        The only solution to overcome all height differences is using the ladders for 5 and 6, and the bricks for 2, 3 and 4.
        Any other distribution will require more brick usage. This is because we would sacrifice at least one ladder for a smaller difference,
        and use bricks to the difference (which is bigger) that the ladder was supposed to be used for.

    Why are we even trying to minimize the brick usage?
    It's because we should consider the worst case scenario and seek the most optimal solution.
    It may not be the case that only the most optimal solution saves us.
    However, to know about whether we can overcome all height differences, only the most optimal solution can help us.
    That's because if we can't reach a building using the most optimal solution, it means none of the other solutions will work.
    We couldn't know this using a suboptimal solution, because there would exist a more optimal solution and we should have tried it to see if it worked.

    So, assigning the ladders to largest height differences... how?
    Notice that with each new building, a new height difference is added to differences list.
    Thus, those "largest" differences might change with every new difference.
    Let's take the sample example: [5, 3, 2, 6, 4]. Process each difference one by one and inspect the largest 2 differences:
        1- [5]
        2- [5, 3]
        3- [5, 3, 2]
        4- [6, 5, 3, 2] -> 3 has left its place for 6!
        5- [6, 5, 4, 3, 2]
    Well, how to maintain the largest L differences? (We have L ladders.)
    We can use a min-heap and limit its size to L (this is where log(L) comes from). When a new difference comes in, and it's larger than the smallest difference among the L differences,
    we should pop the smallest difference and push the new difference.
    Since a popped difference is not going to be re-added to the heap (because it's definitely not among L largest differences), we should consume
    bricks to overcome that difference.

    As you might have seen, we don't directly decide what to overcome a new difference -- because it depends!
    We first use a ladder. Then, whenever it's popped from the heap that stores the largest L differences, we use bricks for it instead (to always use ladders for the largest L differences).
    This might sound a bit confusing. In fact, it's the main part that confused me while solving the problem. Take some time and try to understand :D

    Alright, if it all sounded fine until now, how to actually find the furthest reachable building?
    The building at which the number of bricks becomes inadequate is the first building we can't reach, and we know the number of bricks isn't enough anymore when the difference popped from the min-heap is larger.
    And, the furthest reachable building precedes the first unreachable building :D

    It's actually a fun problem. I pretty much enjoyed brainstorming about it.
    Hope you had fun too! :)
*/
class Solution {
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders) {
        int n = heights.size();

        /*
            In C++, priority_queue acts as a max-heap as default.
            To use it as a min-heap, either use the following:
                priority_queue<int, vector<int>, greater<int>>
            Or store negated values: -5 instead of 5, -10 instead of 10, 7 instead of -7 etc.
            Negating works because if a > b, then -a < -b. The originally largest value becomes the smallest value.

            I used negating because it seems more practical :)
        */
        priority_queue<int> max_diffs;

        // We start on top of the first building, no need to check whether we can reach the first building.
        for (int i = 1; i < n; i++) {
            int diff = heights[i] - heights[i - 1];

            // No need to use bricks/ladders.
            if (diff <= 0)
                continue;

            /*
                Instead of checking whether the new difference is larger than the smallest difference in max_diffs,
                directly push the new difference and then pop the smallest difference.
                This helps us writing less code!
                Hope it's easy to figure out why this works :D
            */
            max_diffs.push(-diff);

            /*
                If there were L differences inside max_diffs before, adding the new difference leads to L+1 differences.
                We should now use bricks for the smallest difference.
            */
            if (max_diffs.size() > ladders) {
                // Don't forget to also negate when getting the smallest value!
                int min_diff = -max_diffs.top();
                max_diffs.pop();

                // We don't have enough bricks left, which shows the (i-1)-th building is the furthest one.
                if (bricks < min_diff) {
                    return i - 1;
                }

                // Use the bricks now.
                bricks -= min_diff;
            }
        }

        // We had enough bricks to reach the last building!
        return n - 1;
    }
};