// Author: Ömer Faruk Erdem
// Reviewer: Ahmet Furkan Kavraz
// Question Link: https://leetcode.com/problems/sort-colors/

class Solution {
   public:
    /* We are given three different integers 0,1 and 2 as representative number of colors red,white and blue respectively.
     * And we are asked the sort them in the given order.
     * Since we will sort this 3 integers we can sort them without using any sorting algorithm .
     * If we keep three different index ;
     * -One for point the end of the array
     * -One for point the start of the array
     * -One for point the index that we are currently processing
     * Then we can sort out that array easily by just swapping since there is only 3 different integers to sort
     * Zeros will be at the beginning of the array ,Ones will be at the middle,and twos will be at the end.
     */
    // Time complexity O(n)
    // Space complexity O(1)
    void sortColors(vector<int>& nums) {
        int startIndex = 0;

        int endIndex = nums.size() - 1;

        // This is the index that we are currentlty working on
        int currentIndex = 0;

        // The main idea here is if we see a 0 send it to the starting point and increment start
        // if we see a 1 then pass it since it will be at the middle of the array
        // if we see a 2 then send it to the end of the array and decrease end index

        while (currentIndex <= endIndex) {  // loop stops when current index is more than end index

            // Here if the number in the current index is zero then it will be at the beginning of the array as we are told.
            if (nums[currentIndex] == 0) {
                // swap the current number with starting number of the array
                swap(nums[startIndex], nums[currentIndex]);

                // increment both starting and current indexs
                startIndex++;
                currentIndex++;
            }

            // if the current number is 1 then dont change start and end index
            // since it will be at the middle just pass it and increment current index
            else if (nums[currentIndex] == 1) {
                currentIndex++;
            }

            // if the current number is 2 then send it to the end of the array since it will be at the end of the array
            // since 2 is at its right place and there will be other twos to sort then decrease end index to send other twos near of it
            else {
                swap(nums[currentIndex], nums[endIndex]);
                endIndex--;
                // We dont change current index here beacuse we dont know what we got from at the end of the array  by swapping
                // So ,we will consider current index again
            }
        }
    }
};