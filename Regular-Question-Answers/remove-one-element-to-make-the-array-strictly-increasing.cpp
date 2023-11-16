// Author: Berke Dönmez
// Problem Link: https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing/
// Reviewer: Denis Davidoglu

/*
    Solution 1: O(n^2) (n = nums.length)

    The trivial method for checking whether an array, nums, is strictly increasing is to check whether nums[i] < nums[i+1] for all valid i.
    It is asked to remove exactly one element and check if nums can become strictly increasing.

    For every element, we can "remove" it and check the rest is strictly increasing using the method explained above.
    Well, we aren't obliged to actually remove elements. Removal can be achieved by ignoring.
    If the i-th element is removed, then we can continue without doing anything when the iteration comes to i.

    We are going to do this for all elements: n number of checks for each element leads to O(n^2) complexity.
*/
class Solution {
    vector<int> nums;

   public:
    /*
        It becomes much more readable when we extract the checking mechanism to another function.

        This function takes a single parameter: position_to_remove. It is what it is: tells which element (position) is to be ignored (removed).
        It returns whether "nums" becomes strictly increasing after "position_to_remove" is removed.
        The function doesn't actually remove the element, though.
    */
    bool isIncreasingAfterRemoval(int position_to_remove) {
        /*
            Either start from i = 0 and go until nums.size() - 2, and check if nums[i] < nums[i+1],
            or start from i = 1 and go until nums.size() - 1, and check if nums[i] > nums[i-1].
            It's up to you to choose!
            I prefer the second option because then the break condition stays the same: i < nums.size().
        */
        for (int i = 1; i < nums.size(); i++) {
            // If the current element is removed, just continue.
            if (i == position_to_remove)
                continue;

            // The previous position (index) is normally i-1. But the previous element is removed, we should decrement it to get i-2.
            int previous_position = i - 1 - (i - 1 == position_to_remove);

            // If the previous element doesn't exist, there's nothing to check (only occurs when i = 1 and position_to_remove = 0).
            if (previous_position == -1)
                continue;

            // This is the situation that violates strict increase.
            if (nums[i] <= nums[previous_position])
                return false;
        }

        // Everything's fine :)
        return true;
    }
    bool canBeIncreasing(vector<int> &nums) {
        this->nums = nums;

        // For every element, remove it and check if nums became strictly increasing.
        for (int i = 0; i < nums.size(); i++)
            if (isIncreasingAfterRemoval(i))
                return true;
        return false;
    }
};

/*
    Solution 2: O(n) (n = nums.length)

    After a bit of preprocessing, we can optimize isIncreasingAfterRemoval to O(1)!

    What do we actually want to check?
    See the big picture:
        1- The elements before the removed element must be strictly increasing.
        2- The elements after the removed element must be strictly increasing.
        3- In addition, with respect to the removed element, the preceding element must be smaller than the succeeding element.
    Notice that (1) and (2) corresponds to prefix and suffix, respectively. These are what can be preprocessed!

    For the prefix until the i-th element to be strictly increasing, the prefix until the (i-1)-th element should be strictly increasing,
    and the (i-1)-th element should be smaller than the i-th element.

    Similarly, for the suffix starting from the i-th element to be strictly increasing, the suffix starting from the (i+1)-th element should be strictly increasing,
    and the i-th element should be smaller than the (i+1)-th element.

    There are some edge cases regarding the implementation, though. We'll get into details throughout the code :)

    Using these, the preprocessing can be done in O(n). Then for each element, the checking part can be done in O(1), leading to a total of O(n) complexity.
*/
class Solution {
    vector<int> nums;

    /*
        is_increasing_prefix[i] = Is the prefix until the (i-1)-th element increasing?
        is_increasing_prefix[0] corresponds to the empty prefix, and it's increasing. (base case)

        is_increasing_suffix[i] = Is the suffix starting from the i-th element increasing?
        is_increasing_suffix[n] corresponds to the empty suffix, and it's increasing. (base case)
    */
    vector<bool> is_increasing_prefix, is_increasing_suffix;

   public:
    bool isIncreasingAfterRemoval(int position_to_remove) {
        /*
            Recall the 3-rd condition: the preceding element must be smaller than the succeeding element.

            There are two edge cases:
                1- The preceding element doesn't exist.
                2- The next element doesn't exist.
            Both cases don't violate the condition.

            In C++, there is this thing called "lazy evaluation":
                1- cond1 || cond2 || cond3 || ... || cond(n): expressions after the first "true" will be ignored.
                2- cond1 && cond2 && cond3 && ... && cond(n): expressions after the first "false" will be ignored.
            Using this, we can neglect checking whether we went out of bounds when accessing the previous and the next elements.
            We used it for neighboring_elements_are_fine :)
            It helps so much when it comes to convenient coding.
        */
        bool previous_element_exists = position_to_remove - 1 >= 0;
        bool next_element_exists = position_to_remove + 1 < nums.size();
        bool neighboring_elements_are_fine = !previous_element_exists || !next_element_exists || nums[position_to_remove - 1] < nums[position_to_remove + 1];

        /*
            Can you see how we defined is_increasing_prefix and is_increasing_suffix helped here?
            Hint: what extra controls should have been required for position_to_remove = 0 or position_to_remove = n-1?
        */
        // Conditions:          (1)                                         (2)                                      (3)
        return is_increasing_prefix[position_to_remove] && is_increasing_suffix[position_to_remove + 1] && neighboring_elements_are_fine;
    }

    bool canBeIncreasing(vector<int> &nums) {
        this->nums = nums;
        int n = nums.size();
        is_increasing_prefix.assign(n + 1, true);
        is_increasing_suffix.assign(n + 1, true);

        /*  Recall!
            For the prefix until the i-th element to be strictly increasing, the prefix until the (i-1)-th element should be strictly increasing,
            and the (i-1)-th element should be smaller than the i-th element.
        */
        for (int i = 0; i < n; i++)
            /*
                (Regarding the expression "i ? nums[i] > nums[i-1] : true")
                If i != 0, then the previous element exists. The condition should be nums[i] > nums[i-1].
                Otherwise, we should take "true" as there's nothing else to violate.
            */
            is_increasing_prefix[i + 1] = is_increasing_prefix[i] && (i ? nums[i] > nums[i - 1] : true);

        /*
            Recall!
            Similarly, for the suffix starting from the i-th element to be strictly increasing, the suffix starting from the (i+1)-th element should be strictly increasing,
            and the i-th element should be smaller than the (i+1)-th element.
        */
        for (int i = n - 1; i >= 0; i--)
            /*
                (Regarding the expression "i+1 < n ? nums[i] < nums[i+1] : true")
                If i+1 < n, then the next element exists. The condition should be nums[i] < nums[i+1].
                Otherwise, we should take "true" as there's nothing else to violate.
            */
            is_increasing_suffix[i] = is_increasing_suffix[i + 1] && (i + 1 < n ? nums[i] < nums[i + 1] : true);

        for (int i = 0; i < n; i++)
            if (isIncreasingAfterRemoval(i))
                return true;

        return false;
    }
};
