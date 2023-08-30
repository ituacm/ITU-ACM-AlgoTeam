// Author: Ayşe Sarı
// Question Link: https://leetcode.com/problems/reverse-string/
// Reviewer: Ömer
/* Problem is reversing the letters in a string
* I used Stack because its FILO 
* I iteratively pushed them into stack and rewrite then popped .
* Time and space complexity is O(n)
*/

#include <vector>
#include <stack>

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        std::stack<char> stack;
        
        // Push all characters onto the stack
        for (char c : s) {
            stack.push(c);
        }
        
        // Pop characters from the stack and overwrite the original array
        for (int i = 0; i < s.size(); ++i) {
            s[i] = stack.top();
            stack.pop();
        }
    }
};
