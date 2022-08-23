// Author: Fatih Baskın
// Reviewer:
// Question Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/

/** Information about Reverse Polish Notation (Postorder Notation)
 *
 *  For ex: 4 + 6 x 2
 *  First: 6 x 2 = 12
 *  Then: 4 + 12 = 16 
 *
 *  This notation is called inorder notation.
 *  This notation is problematic and counterintuitive for implementing mathematical calculations for computers.
 *  Solution: Stack based calculator (Last In First Out)
 *
 *  From the example above, we can write this equation as 4 6 2 x + (Reverse Polish Notation) 
 *  First: Take 4, 6 and 2;
 *  In stack there are 4 6 2,
 *
 *  Since every mathematical operator is binary (takes two operands) when an operator comes,
 *  take last two elements from stack and do math operation then push result back to stack.
 *
 *  x, 6 x 2 = 12, push 12 to stack, stack is: 4 12
 *  +, 4 + 12 = 16, push 16 to stack, result is 16.
 *
 *  Time complexity: O(n), n refers to size of string vector.
 */

class Solution 
{
public:
    int evalRPN(vector<string>& tokens) 
    {
        // Number of strings
        int n = tokens.size();
        // Stack
        stack<int> calculator;
        // Reading all strings
        for(int i = 0; i < n; i++)
        {
            // If it is operator +
            if(tokens[i][0] == '+')
            {
                // Reading top two numbers from stack
                int a, b;
                b = calculator.top();
                calculator.pop();
                a = calculator.top();
                calculator.pop();
                // Doing operation
                calculator.push(a + b);
            }
            // If it is operator -
            // Note that to not get confused by negative numbers, also looking for size
            // Size would be 1 if it is operator -
            else if(tokens[i][0] == '-' && tokens[i].size() == 1)
            {
                // Reading top two numbers from stack
                int a, b;
                b = calculator.top();
                calculator.pop();
                a = calculator.top();
                calculator.pop();
                // Doing operation
                calculator.push(a - b);
            }
            else if(tokens[i][0] == '*')
            {
                // Reading top two numbers from stack
                int a, b;
                b = calculator.top();
                calculator.pop();
                a = calculator.top();
                calculator.pop();
                // Doing operation
                calculator.push(a * b);
            }
            else if(tokens[i][0] == '/')
            {
                // Reading top two numbers from stack
                int a, b;
                b = calculator.top();
                calculator.pop();
                a = calculator.top();
                calculator.pop();
                // Doing operation
                calculator.push(a / b);
            }
            // If not an operator
            else
            {
                // Convert string into integer and push to stack
                // stoi function is defined in c++, turns string into integer
                calculator.push(stoi(tokens[i]));
            }
        }
        // Question guarantees that given string is a valid operation.
        // If so, as a result there shall be only one integer remaining in the stack.
        return calculator.top();
    }
};
