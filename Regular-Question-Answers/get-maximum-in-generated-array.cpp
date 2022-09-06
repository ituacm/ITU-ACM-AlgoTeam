// Author: Ömer Faruk ERDEM
// Question Link: https://leetcode.com/problems/get-maximum-in-generated-array/

class Solution {
public:
   /* In the question, we are given an integer n and we are asked to create an array of size n+1 as written in the question.
    * And we will return the maximum element in the array.
    */
    int getMaximumGenerated(int n) {
        //if the input is zero then we will return 0 since 0+1 sized array's maximum element is 0.
        if (n==0) return 0;

        // Creating n+1 sized vector and initialize all of them with 0.
        vector<int> nums(n+1,0);

        // Creating a maximum element and initialize it with 1.
        int maximumElement = 1;
    
        // Assigning 0 and 1 indexed elements 0 and 1 relatively since they are essential for creating our array.
        nums[0] = 0;
        nums[1] = 1;

        //Now it is time to create our array.
        //First create a loop from 1 to n/2.
        for (int i = 1 ; i <= n/2 ; i++){
            
            // And check the conditions that we are given in the question.
            if ( 2<= 2*i and 2*i<=n ){
                nums[2*i] = nums[i];

                // And check if new created element is greater then our current max.
                // Assign maximum element to maximum of current maximum element's value and new created element.
                maximumElement = max(nums[2*i],maximumElement);
            }
            if ( 2<= 2*i+1 and 2*i+1<=n  ){
                nums[2*i+1] = nums[i]+nums[i+1];

                // And again, assign maximum element to maximum of current maximum element's value and new created element.
                maximumElement = max(nums[2*i+1],maximumElement);
            }
        }
        return maximumElement; 
    }
};
