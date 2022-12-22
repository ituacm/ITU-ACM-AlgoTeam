// Author: Ömer Faruk ERDEM
// Question Link: https://leetcode.com/problems/reverse-words-in-a-string/
// Reviewer: Denis Davidoglu

/* In this problem we want to reverse the order of words with given format:
*  First word in the string will be last and last string will be first
*  In other words First In Last Out 
*  We need to use compatible data structure to solve this problem
*  Stack will help us here 
*  In the algorithm we will iterate through the string 
*  Pick the words and push them into stack
*  Then pop them out of the stack and store them in a string again 
*  Finally we will have a string whose order of the words reversed
*
*  Time Complexity  = O(n)
*  Space Complexity = O(n)
*/


class Solution {
public:
    string reverseWords(string &s) {
        if (s.size() == 0) return s;
        
        // Create  the stack
        stack<string> stack;
        
        // Iterating through the string 
        for (int i = 0; i < s.size(); i++) {
            // If a char is empty then skip this char since extra spaces are not wanted in the problem
            if (s[i] == ' ') continue;

            // If a nonempty char is found it is the starting point of one of the words
            // From start to end of the word, we iterate through it and store it into another string "word"  
            string word;
            
            // We keep adding chars into word until we find empty char which is the end of the word
            while (s[i] != ' ' && i < s.size()) {
                word += s[i];
                i++;
            }
            // Push the word into the stack
            stack.push(word);
        }
        // Now we have pushed all of the words into stack
        // So I can remove all of the things in string s since we will not use the words in it

        // Resize function destroys all elements except first n element which is given as parameter
        s.resize(0);

        // Pop all of the words and add them into the string s
        while (!stack.empty()) {
            s += stack.top();
            stack.pop();

            // Checking if the words runned out, since there is a space needed between every words 
            // and we dont want to put empty space at the end of the string
            if (!stack.empty()) s+=" ";
        }

        return s;
    }
};

