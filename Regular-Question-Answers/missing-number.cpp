// Author: Ömer Faruk Erdem
// Question Link: https://leetcode.com/problems/missing-number/
// Reviewer: Denis Davidoglu

// Time Complexity :  O(n)
// Space Complexity : O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /*
            To find the missing number, we can use Gauss's summation formula.
            In the vector we are given numbers in the range 0 to n, where n is size.
            By using Gauss's formula we can get the summation of the numbers from 1 to n easily.
            
            If we add up all of the numbers in the vector we will get a total value.
            Then we can get the answer by subtracting that total value from 
            the summation of all numbers in the interval [1 , n]  
        */
        int n = nums.size();
    
        // Calculate the expected summation 
        int expected = (n*(n+1)) / 2 ;
        int real = 0 ;

        // Get the summation of all integers in the vector
        for (int x : nums) real += x;

        return expected - real;
    }
};
