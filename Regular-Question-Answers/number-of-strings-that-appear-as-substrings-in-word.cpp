// Author: Emre Çelik
// Reviewer: 
// Question Link: https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/

/*
 * The goal of this algorithm is to count the number of strings from the given vector
 * 'patterns' that appear as substrings in the input string 'word'.
 *
 * The algorithm iterates through each pattern in the 'patterns' vector and checks
 * if it is a substring of the input 'word' using the std::string::find() function.
 * If a pattern is found in 'word', the result counter is incremented.
 *
 * Time complexity: O(n*m)
 * Memory complexity: O(1)
 */

class Solution {
public:
    // Function to count the number of strings from 'patterns' that appear as substrings in 'word'
    int numOfStrings(vector<string>& patterns, string word) {
        // Counter to store the final result
        int result = 0;
        // Number of patterns in the vector 'patterns'
        int n = patterns.size(); 

        // Iterate through each pattern
        for(int i = 0; i < n; i++){
            // Check if the current pattern is a substring of 'word'
            if(word.find(patterns[i]) != string::npos)
                // Increment the counter if the pattern is found
                result = result + 1; 
        }
        
        // Return the final count of matching substrings 
        return result; 
    }
};
