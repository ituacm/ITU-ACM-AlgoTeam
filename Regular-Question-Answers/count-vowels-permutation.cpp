// Author: Hacer Akıncı
// Question Link: https://leetcode.com/problems/count-vowels-permutation/ 
// Reviewer: Denis Davidoglu

// Time complexity: O(n)
// Space complexity: O(n)

class Solution {
/* 
    In the question, n is given as the length of a string, and we are asked to find the number of permutations considering the given rules.

    We can start with one of five different letter {a, e, i, o, u}.
    The description states which letters can be followed by each letter: 
        a -> e
        e -> a, i
        i -> a, e, o, u
        o -> i, u
        u -> a

    Let's assume that we have a string of length 5. If we start with 'a', we need to find all permutations of a 5-length string starting with 'a'.
    'a' should be followed only by 'e'. Now we just need to find all permutations of a 4-character string starting with 'e'.
    'e' should be followed by 'a' or 'i'. Now we need to find all permutations of a 3-character string starting with 'a' or 'i'.
    And so on.

    This problem can be solved using Dynamic Programming. I solved it using Bottom-Up approach.
    We store number of permutations for each letter starting with a single-character string.
    Then for 2-character strings, we add the permutation count of the single-character to the possible letters. 
    By doing this iteratively up to n, we can reach to the n-character string for each letter.
    The result is equal to the sum of the permutation counts of the n-character strings for each letter.

*/

public:
    long long MOD = 1e9 +7;
    
    int countVowelPermutation(int n) {
        
        // indexes of letters used in vectors below: { 0 = 'a', 1 = 'e', 2 = 'i', 3 = ''o', 4 = 'u' }

        // Store the permutations counts of each letter for 1...n character strings.
        // permutation[0][3] = 7. The permutation count of a 3-character string starting with 'a'. 
        vector<vector<int>> permutation(5, vector<int> (n+1));

        // Fill for single-character string
        for (int i = 0; i < 5; i++) {
            permutation[i][1] = 1;
        }

        // Indeces of possible subsequent letters for each letter.
        vector<vector<int>> second_letters;
        
        second_letters.push_back({1}); // a -> e 
        second_letters.push_back({0, 2}); // e -> a, i
        second_letters.push_back({0, 1, 3, 4}); // i -> a, e, o, u
        second_letters.push_back({2, 4}); // o -> i, u
        second_letters.push_back({0}); // u -> a

        // Iterate over length of strings
        for (int i = 2; i <= n; i++) {
            // Iterate over letters
            for (int j = 0; j < 5; j++) {
                // Iterate over possible subsequent letters and add permutation count to them 
                for (int letter: second_letters[j]) {
                   permutation[letter][i] +=  permutation[j][i - 1] % MOD;
                   permutation[letter][i] %= MOD;
                }
            }
        }

        long long result = 0;
        for (int i = 0; i < 5; i++) {
            result = (result + permutation[i][n])%MOD;
        }

        return result;
    }
};
