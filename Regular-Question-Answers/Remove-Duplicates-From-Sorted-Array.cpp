// Author: Feyza Sarı
// Reviewer: 
// Question Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:

/*for moving the diffrent values to the begining the array we have to compare elements. 
Lets consider the 1-1-2 array. Compare first element with the next one, they are same. 
Next step should be compering the first element with the third one. 
If they are diffrent from each other third element should be next element of the first element. 
So our array will be 1-2-2. If we continue this steps with compering the second element
(last element of the expected array) with the checking element(traverse all the array) 
we can get the expected array.*/
    
    int removeDuplicates(vector<int>& nums) {
        //current is the last elements index of expected array.
        //compare is for traversing the array and check if there is a diffrent value.
        int current=0, compare=1;
        
        //while we are in the array range
        while(compare<nums.size()){
            //if the last elements of expected array is diffrent from the compare one there is a diffrent element in array
            //move this element to the end of the expected array (current+1 index)
            if(nums[current]!=nums[compare]){
                nums[++current]=nums[compare];//++current is first increase the number then do the operation
            }
            
            //continue to the comparing with the next element of given array
            compare++;
        }
        //return current + 1 (0 based array)
        return current+1;
    }
};