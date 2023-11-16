// Author: Ayşe Sarı
// Question Link: https://leetcode.com/problems/reverse-string/
// Reviewer: Ömer
/* Problem is reversing the letters in a string
 * I used a two-pointer approach because it allows for an in-place reversal without extra space.
 * I initialized 'left' to the start and 'right' to the end, then iteratively swapped them.
 * Time complexity is O(n) and space complexity is O(1).
 */

#include <stack>
#include <vector>

class Solution {
   public:
    void reverseString(std::vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            // Swap characters at left and right pointers
            std::swap(s[left], s[right]);
            ++left;
            --right;
        }
    }
};
