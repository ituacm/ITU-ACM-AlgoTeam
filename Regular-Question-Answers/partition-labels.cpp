// Author: Novruz Amirov
// ITU ACM AlgoTeam
// Question link: https://leetcode.com/problems/partition-labels/

class Solution {
public:
    /*
        Greedy algorithm question.
        1. Find last index of each character and store it (map)
        2. Loop through given string by checking if index is equal to end.
        
        Note: variable 'end' is the index of furthest character in substring.

        If 'end' is equal to where the pointer is in while looping, then cut it off.
    */

    vector<int> partitionLabels(string s) {
        // creating unordered map to store the last index of each character.
        unordered_map<char, int> lastIndex;
        for (int i = 0; i < s.length(); i++) {
            lastIndex[s[i]] = i;
        }

        // the vector to return the size of each substring
        vector<int> partitionLengths;

        // 'start' is for the starting pointer of substring
        // 'end' furthest char in substring
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++) {
            end = max(end, lastIndex[s[i]]);
            if (i == end) {
                partitionLengths.push_back(end - start + 1);
                start = end + 1;
            }
        }

        return partitionLengths; // return the result
        /*
            Overall Time Complexity: O(N + N) = O(N)
            Space Complexity: O(1)
        */
    }
};