// Author : Ömer Faruk Erdem
// Question Link: https://leetcode.com/problems/minimum-score-by-changing-two-elements/

// Time Complexity :  O(nlogn)
// Space Complexity : O(1)

/*
    * We are given three definitions. We need to understand them clearly to solve the question.
    * Low score is the minimum difference between any pair of  element in the array.
    * High score is the maximum difference between any pair of  element in the array.
    * In the other words, if we sort the array, high score is the substraction of last element from first element.
    * And score is the summation of low and high score.
*/
class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size() ;
        /* 
            If we sort the array and put these numbers on the number line 
            
                0--------nums[0]---nums[1]--nums[2]---------------nums[3]----nums[4]--------nums[n-1]
            
            we will have something like that

            Main idea here is to putting the elements of the array in a as small range as possible by changing only two elements  
            So that high score will be minimized.
            And low score will be minimized also. By making it 0.
            If we make one of the two elements equal to another element in the array, low score will be '0'
            

            To put the elements in a small range by changing only two elements we have only three options.
            These are :
            1 -) Remove last two elements and put them into other interval.  ---> [nums[0] , nums[n-3] ]
            2 -) Remove last two elements and put them into other interval.  ---> [nums[2] , nums[n-1]]
            3 -) Remove first and last elements and put them into the middle interval. ---> [nums[1]  , nums[n-2] ]

            Smaller range of numbers will give us smaller score. 
        */

        // Sort the array
        sort(nums.begin(),nums.end() );
        
        // Calculate the values of high score by the intervals.
        int n1 = nums[n-3]-nums[0];
        int n2 = nums[n-1]-nums[2];
        int n3 = nums[n-2]-nums[1];
        
        // Return the minimum high score among these three.
        // Low range can be 0 because we can make one of the removed numbers equal to the another number in the range.
        return min( n1 , min (n2, n3) );
    }
};
