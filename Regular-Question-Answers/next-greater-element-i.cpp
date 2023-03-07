// Author: Bilgenur Çelik
// Question Link: https://leetcode.com/problems/next-greater-element-i/
// Reviewer: Denis Davidoglu

/*
 * This question is a simple monotonic decreasing stack implementation.
 *
 * If we encounter a greater element than the top of the stack
 * pop it until it is ready to be pushed into the stack.
 *
 * 5 4 6 3 1 2
 * 5-4 is in stack
 * 6 is greater than both thus 5 and 4 will be popped and mapped as 6
 * 6-3-1 will be in stack
 * 2 will make 1 popped and mapped as 2.
 *
 * in the end 5->6, 4->6, 6->0, 3->0, 1->2, 2->0
 * for num1 elements return corresponding mapped results.
 *
 * */
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> monotonic_stack;

        // We could also use map
        int arr[10005] = {0};

        for (int i : nums2) {
            while (!monotonic_stack.empty() && i > monotonic_stack.top()) {
                arr[monotonic_stack.top()] = i;
                monotonic_stack.pop();
            }
            monotonic_stack.push(i);
        }
        for (int &i : nums1) {
            if (arr[i] == 0) i = -1;
            else i = arr[i];
        }

        return nums1;
    }
};
