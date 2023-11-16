// Author: Ömer Faruk ERDEM
// Question Link: https://leetcode.com/problems/length-of-last-word/
// Reviewer: Denis Davidoglu

/* In the question we are given a string and asked to find the length of the last word.
 * To solve this problem the algorithm we will use the two pointers technique.
 * We will use these two pointers to point to the start and the end of the words
 * Our first pointer will point to the end of the last word and second will point to the start of the last word.
 * When we subtract these two we will get the length of the last word.
 *
 * Time Complexity  = O(n)
 * Space Complexity = O(1)
 */

class Solution {
   public:
    int lengthOfLastWord(string s) {
        // Here we have two pointers
        // Inititalize pointer2 to s.size()-1 which is the end of the string
        int pointer1;
        int pointer2 = s.size() - 1;

        // Now we have to find the end point of last word
        // To find it we have to go backwards until the current char is not emtpy char (' ').
        while (s[pointer2] == ' ') pointer2--;

        // pointer2 is pointing the end of the last word now
        pointer1 = pointer2;

        // Since we want to find starting point of the word, pointer1 must point the starting point.
        // Then go backwards until find a empty char (' ').
        while (s[pointer1] != ' ') {
            pointer1--;
            // Here we have to put if condition to make sure the loop ends when we reach the string's starting point
            // Otherwise we will get error since there is no such an element like s[-1]
            if (pointer1 < 0) break;
        }

        // Starting point of the word is pointer1 + 1 now since we have gone one more step.
        // It is because loop's ending condition is having empty char as current char.
        int length = pointer2 - (pointer1 + 1) + 1;
        //             ^            ^           ^
        //             |            |           |
        //          end point    start point   add 1 to complete the length of the word

        return length;
    }
};
