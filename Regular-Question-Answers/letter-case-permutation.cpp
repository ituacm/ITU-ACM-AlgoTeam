// Author: Ramazan Emre Özkaya
// Question Link: https://leetcode.com/problems/letter-case-permutation/
// Reviewer: Mehmet Fuat Karakaya

// Time Complexity: O(2^N)
// Space Complexity: O(N)

/*
In this question, we need to generate all possible strings with different letter
cases. In order to do that, the best approach to this question is backtracking.
Backtracking ensures that we iterate through every character in a string and generate
permutations of that string, whether the character is a letter or a digit.
*/

class Solution {
public:
    // Creating the backtrack function
    void backtrack(string s, int index, string& current, vector<string>& answer)
    {
        // Base Case: If index is equal to the length, we have looked up in each character
        if (index == s.length())
        {
            // Push the current string to our answer string and return the function
            answer.push_back(current);
            
            return;
        }
        
        // Initializing a char variable to store our current character
        char currentChar = s[index];

        /*
        If our current character is a digit, just push to our current string and
        continue backtracking with the next index.
        */ 
        if (isdigit(currentChar))
        {
            // Push our current character to our current string
            current.push_back(currentChar);

            // Recursively call bactrack with the next index
            backtrack(s, index + 1, current, answer);

            // Pop the last added digit
            current.pop_back();
        }

        /*
        If our current character is not a digit, it means it is a letter (in this 
        question, we know that every character in our input string must be a letter 
        or a digit).
        */
        else
        {
            // Push our current uppercase character to our current string
            current.push_back(toupper(currentChar));

            // Recursively call bactrack with the next index
            backtrack(s, index + 1, current, answer);

            
            // Pop our uppercase letter from the current string 
            current.pop_back();

            // Push our current lowercase character to our current string
            current.push_back(tolower(currentChar));
            
            // Recursively call bactrack with the next index
            backtrack(s, index + 1, current, answer);

            // Pop the last added letter
            current.pop_back();
        }
        return;
    }

    vector<string> letterCasePermutation(string s) {

        // Initialize a vector to store our permutations
        vector<string> ans;

        // Initialize an empty string to store the current permutations
        string curr;

        // Call our backtrack function from the first index
        backtrack(s, 0, curr, ans);

        // Return our answer
        return ans;
    }
};