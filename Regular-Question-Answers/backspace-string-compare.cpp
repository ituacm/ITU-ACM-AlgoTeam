// Author: Ali Kemal Coşkun
// Question Link: https://leetcode.com/problems/backspace-string-compare/
// Reviewer: Denis Davidoglu

// Time complexity: O(N)
// Space complexity: O(N)

// This question asks whether s is equal to t after performing necessary operations.
// When the '#' character arrives, the last character is removed.
// This is similar to LIFO principle of stack, so we can use stack for this question.

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s_stack;
        stack<char> t_stack;

        for (int i = 0; i < s.size(); i++)
            if (s[i] != '#') {
                s_stack.push(s[i]);
            } else if (!s_stack.empty()) {
                s_stack.pop();
            }

        for (int i = 0; i < t.size(); i++)
            if (t[i] != '#') {
                t_stack.push(t[i]);
            } else if (!t_stack.empty()) {
                t_stack.pop();
            }

        return s_stack == t_stack;
    }
};
