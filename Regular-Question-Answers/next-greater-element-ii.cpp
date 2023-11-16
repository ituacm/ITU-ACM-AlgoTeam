// Author: Berke Dönmez
// Problem Link: https://leetcode.com/problems/next-greater-element-ii/
// Reviewer: Denis Davidoglu

/*
    The intended solution uses monotonic stack to solve in O(n).

    However, there exists another O(n * log(n)) solution that utilizes sparse table and binary search.
    We shared it as a bonus solution below the actual solution. It isn't explained though :P
*/

class Solution {
   public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        int n = nums.size();
        /*
            If we think of a brute-force solution, we can just iterate over next elements and
            find the first element with a greater value:
                for (int i = 0; i < n; i++) {
                    for (int j = i+1; j < n; j++) {
                        if (nums[j] > nums[i]) {
                            next_greater[i] = nums[j];
                            break;
                        }
                    }
                }

            And to provide circularity, we can additionally loop through 0 to i-1:
                for (int i = 0; i < n; i++) {
                    for (int j = i+1; j < n; j++) {
                        if (nums[j] > nums[i]) {
                            next_greater[i] = nums[j];
                            break;
                        }
                    }
                    if (next_greater[i] == -1) {
                        for (int j = 0; j < i; j++) {
                            if (nums[j] > nums[i]) {
                                next_greater[i] = nums[j];
                                break;
                            }
                        }
                    }
                }

            Furthermore, we can simplify the code like so:
                for (int i = 0; i < n; i++) {
                    // Loop through exactly n-1 numbers
                    for (int j = i+1; j < i+n; j++) {
                        if (nums[j % n] > nums[i]) {
                            next_greater[i] = nums[j % n];
                            break;
                        }
                    }
                }

            But... this is SLOW. As you can see, it performs roughly n^2 operations.
            Although the constraints allow such a solution, we may seek a more efficient solution!
        */

        /*
            We can think of the following idea: for each element "x" whose next greater number hasn't been found
            yet, if the current element is larger than x, then the current element is what we are looking for.

            So, our first aim is to store the elements whose next greater number hasn't been found yet.
            Let's call our storage "waiting_for_next_greater".
            Notice that if we store the elements with the same order they appear in nums,
            waiting_for_next_greater is going to be a non-increasing array.

            Why?

            Assume there are two elements in waiting_for_next_greater that violate this condition: x and y.
            That is, x < y. But then, we would have actually found the next greater number for x, because
            y is already greater than x. So, x can't be inside waiting_for_next_greater.

            With that being said, since waiting_for_next_greater is going to be non-increasing, we can
            traverse waiting_for_next_greater from right to left. Meanwhile, as long as the last element inside
            waiting_for_next_greater is smaller than the current element (which has not been added to waiting_for_next_greater yet),
            we assign the current element as the next greater number for the last element, and remove the last element from
            waiting_for_next_greater.

            Since these operations are suitable for a stack (last element is processed first),
            we can use stack for waiting_for_next_greater!

            P.S. In fact, waiting_for_next_greater is called a "monotonic stack".
            A "monotonic" structure is called so because it's always increasing/decreasing/non-increasing/non-decreasing etc.

            Since each element is processed at most 2 times (added to and removed from waiting_for_next_greater),
            this algorithm works in O(n)!
            Note that if the while loop in handle_current_element gets executed, it always pops an element.
            (This is where right-to-left traversal shines!)
            Therefore, we don't make any unnecessary iterations, which guarantees the O(n) complexity.
        */

        // We may store just indices, no need to store elements' values because using indices, we can use nums to access values!
        vector<int> next_greater(n, -1);
        stack<int> waiting_for_next_greater;

        /*
            Lambda function in C++.
            I use it whenever I'm bored of many parameters and want to write in Python style :D
        */
        auto handle_current_element = [&](int current_element) {
            // waiting_for_next_greater.size() acts as !waiting_for_next_greater.empty() :)
            while (waiting_for_next_greater.size() && nums[waiting_for_next_greater.top()] < current_element) {
                next_greater[waiting_for_next_greater.top()] = current_element;
                waiting_for_next_greater.pop();
            }
        };

        for (int i = 0; i < n; i++) {
            /*
                While there exists an element waiting for the next greater number to be found,
                Iterate over waiting_for_next_greater to use the current element for possible assignments.
            */
            handle_current_element(nums[i]);

            // Then, the current element's next greater number hasn't been found yet. Add it to waiting_for_next_greater.
            waiting_for_next_greater.push(i);
        }

        /*
            So... what about circularity?
            Now, we can just re-iterate over nums again to find next greater numbers for those remaining inside waiting_for_next_greater.
            In fact, it's almost the same loop. The only difference is that we don't push elements to waiting_for_next_greater anymore.
        */
        for (int i = 0; i < n; i++)
            handle_current_element(nums[i]);

        return next_greater;
    }
};

/*
    Bonus O(n * log(n)) solution: sparse table & binary search!
*/
class Solution {
   public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        int n = nums.size();
        const int LG = log2(n) + 2;
        int range_max[n][LG];

        for (int i = 0; i < n; i++)
            range_max[i][0] = nums[i];
        for (int j = 1; j < LG; j++)
            for (int i = 0; i < n; i++) {
                int r = min(n - 1, i + (1 << (j - 1)));
                range_max[i][j] = max(range_max[i][j - 1], range_max[r][j - 1]);
            }

        auto find_max = [&](int l, int r) {
            int range_length = r - l + 1;
            int lg = log2(range_length);
            return max(range_max[l][lg], range_max[r - (1 << lg) + 1][lg]);
        };

        auto find_index_of_first_greater = [&](int lower_bound, int l, int r) {
            int left = l;
            while (l < r) {
                int mid = (l + r) / 2;
                int mx = find_max(left, mid);
                if (mx > lower_bound)
                    r = mid;
                else
                    l = mid + 1;
            }
            return l;
        };

        vector<int> next_greater(n, -1);
        for (int i = 0; i < n; i++) {
            int next_greater_idx = find_index_of_first_greater(nums[i], i, n);
            if (next_greater_idx == n) {
                next_greater_idx = find_index_of_first_greater(nums[i], 0, i);
                if (next_greater_idx == i)
                    next_greater_idx = -1;
            }
            if (next_greater_idx != -1)
                next_greater[i] = nums[next_greater_idx];
        }
        return next_greater;
    }
};
