// Author: Toygun Görmüş
// Question Link: https://leetcode.com/problems/positions-of-large-groups/
// Reviewers: Bilgenur Çelik, Denis Davidoglu

/* A string problem. The intervals of occurrunces can be calculated by iterating over the string and keeping count.*/

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        // Declaring a vector to store the intervals of large group letters.
        vector<vector<int>> ans;
        // Iterating over the string. The variable "start" keeps track of the start of the interval in case we need it for the vector "ans".
        for (int i = 0; i < s.size(); i++) {
            int start = i;
            // Continue counting while letters are same.
            while (s[i] == s[i + 1]) i++;
            // If the letter makes a large group (Number of occurrunces 3 or more), we store the interval in the vector "ans".
            if ((i - start) >= 2) {
                ans.push_back({start, i});
            }
        }
        return ans;
    }
};
