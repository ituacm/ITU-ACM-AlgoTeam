// Author: Emre ÇELİK
// Question Link: https://leetcode.com/problems/repeated-string-match/
// Reviewers:

// Time Complexity : O(n*m)
// Space Complexity : O(1)

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int count; // We are declaring our answer attribute.
        
        // Checking for special case and return answer.
        if (b.empty()) {
            return 1;
        }
        
        for (int i = 0; i < a.size(); i++) {
            // Catching a string in b string with while loop.
            while (i < a.size() && a[i] != b[0]) i++;
           
            int j = 0;
            int k = i; // Assign our i value to k for protect i value.
            count = 1; // Reassigning in every loop if there is separation.
            while (a[k++] == b[j++]) { // Check a and b string are equal in loop.
                // If we reached last element of b string then return answer.
                if (j == b.size()) {
                    return count;
                } 
                // If they are equal and a string is done make k is 0 and decrease count by 1.    
                if (k == a.size()) {
                    k = 0; 
                    count++;
                }
            }
            if (j > b.size()) break;
        }
        
        // If we can't reach last element of b string with equality, return -1.
        return -1;
    }
};
