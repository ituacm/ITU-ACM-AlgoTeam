// Author: Feyza Sarı
// Question Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Reviewer: Denis Davidoglu

class Solution {
   public:
    /* To move different values to the beginning of the array we have to compare elements.
    Lets consider the 1-1-2 array. Compare first element with the next one, they are same.
    Next step should be comparing the first element with the third one.
    If they are diffrent from each other third element should be next element of the first element.
    So our array will be 1-2-2. If we continue this steps with comparing the second element
    (last element of the expected array) with the checking element (traverse all the array)
    we can get the expected array.*/

    int removeDuplicates(vector<int>& nums) {
        // current is the last element's index of expected array.
        // compare is for traversing the array and check if there is a diffrent value.
        int current = 0, compare = 1;

        // while we are in the array range
        while (compare < nums.size()) {
            // if the last element of expected array is different from the compare one there is a different element in array
            // move this element to the end of the expected array (current+1 index)
            if (nums[current] != nums[compare]) {
                nums[++current] = nums[compare];  //++current is first increase the number then do the operation
            }

            // continue to the comparing with the next element of given array
            compare++;
        }
        // return current + 1 (0 based array)
        return current + 1;
    }
};
