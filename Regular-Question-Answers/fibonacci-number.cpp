	// Author: Ali Davut Eskiocak
	//Question link: https://leetcode.com/problems/fibonacci-number/
	// Time complexity : O(n)
    // Space complexity : O(n)
	class Solution {
	public:
    // we are going to solve this problem with using dynamic programming approach
    //we will create an array and store the values inside of it to avoid too many calculations
   
	
		int fib(int n) {
    
		//initialize exceptional cases	
    	 if(n == 1) return 1;
        if(n == 0) return 0;
   		
		//creating an array
        int arr[n+1];
        
		arr[0] = 0;
        arr[1] = 1;
		// we arrange every value as a sum of last two values
        for (int i = 2; i <= n; i++) {
            arr[i] = arr[i-1] + arr[i-2];
        }
        //the answer is n. value in the array
		return arr[n];    
    	}
	};
