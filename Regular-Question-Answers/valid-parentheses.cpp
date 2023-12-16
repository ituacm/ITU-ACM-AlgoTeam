// Author: Fatih Baskın
// Question Link: https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        /**
         * This type of questions can be solved easily with stacks.
         * In stack data structure, you can only access the last(top) element.
         * You can either push a new element or pop a element.
         *
         * We will use this property to construct our stack with opening parantheses.
         * Then remove top elements if we encounter correct closing paranthesis.
         *
         * If wrong type of closing paranthesis is encountered or stack is not empty
         * after the process, we can say that answer is false, otherwise answer is true.
         *
         * Complexity of this algorithm is O(n), n corresponds to string lenght.
         */

        int string_lenght = s.size();

        // Corner case: if string consists of odd number of chars then there are
        // mismatching number of opening and closing parantheses.
        if (string_lenght % 2 == 1) {
            return false;
        }

        stack<char> parantheses;

        // From here we are checking individual characters of the string s
        for (int i = 0; i < string_lenght; i++) {
            // Push the current char into stack if it is '(' or '{' or '['
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                parantheses.push(s[i]);
            } else  // If it is not an opening paranthesis then there are three cases
            {
                // Case 1: If the stack is empty, there is no paranthesis to close, return false.
                if (parantheses.empty()) {
                    return false;
                }

                // Case 2: last paranthesis (top) on the stack matches the current closing paranthesis.
                char top = parantheses.top();
                if ((s[i] == '}' && top == '{') || (s[i] == ']' && top == '[') || (s[i] == ')' && top == '(')) {
                    // If current char in the string matches top element of the stack, then pop the last element.
                    parantheses.pop();
                } else  // Case 3: If doesn't match, then return false
                {
                    return false;
                }
            }
        }

        // If stack is not empty after checking all characters then return false
        if (!parantheses.empty()) {
            return false;
        }

        // By this point, if the algorithm didn't encounter a case which would return false
        // then return ture.
        return true;
    }
};