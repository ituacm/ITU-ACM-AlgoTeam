// Author: Emre ÇELİK
// Question Link: https://leetcode.com/problems/repeated-string-match/
// Reviewer: Denis Davidoglu

// Time Complexity : O(n*m)
// Space Complexity : O(1)

class Solution {
   public:
    int repeatedStringMatch(string a, string b) {
        // We declare our answer attribute.
        int count;

        // Checking for special case and return answer.
        if (b.empty()) return 1;

        for (int i = 0; i < a.size(); i++) {
            // Catching string a in string b with while loop.
            while (i < a.size() && a[i] != b[0]) i++;

            int j = 0;
            int k = i;                  // This assignment saves i's value.
            count = 1;                  // Reassigning in every loop if there is separation.
            while (a[k++] == b[j++]) {  // Check if strings a and b are equal in loop.
                // If we reached last element of string b then return answer.
                if (j == b.size()) return count;

                // If they are equal and string a is done, make k 0 and decrease count by 1.
                if (k == a.size()) {
                    k = 0;
                    count++;
                }
            }
            if (j > b.size()) break;
        }

        // If we can't reach last element of string b with equality, return -1.
        return -1;
    }
};
