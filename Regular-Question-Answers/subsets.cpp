// Author: Novruz Amirov
// Question Link: https://leetcode.com/problems/subsets/

/*
    Problem Description:
        We are given an array of numbers, 
        which are all unique. There is not any
        duplicate.
        We need to return all possible subsets
        of the array including empty array. The 
        result must not contain duplicates.
        
        Code Explanation:
            We will use Bit Manipulation to generate
            all subsets. First, because the number of 
            subsets is 2^n (n is the size of array),
            shifting the number to left 1 time, is 
            equal to multiplying that number by 2.
            To find all subsets, we will use Bit 
            Manipulation nums.size() time.
            
            Example:
                nums = [1, 2, 3]
                the first 3 subsets are:
                    when k is 0 -> []
                    when k is 1 -> [1]
                    when k is 2 -> [2]
                    when k is 3 -> [1, 2]
                    ...
                    when k is 7 -> [1, 2, 3]
            
            We will store each subset in array, and
            will add it to the answer. 
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // initializing the 2-D result vector
        vector<vector<int>> result;
        
        // to find how many subsets exist (2^n)
        int total = 1 << nums.size();
        
        // finding each subsets from 0 to 2^n - 1. 
        for (int subsetNumber = 0; subsetNumber < total; subsetNumber++){
            vector<int> subset; // initializing subset vector for each subsetNumber
            for (int i = 0; i < nums.size(); i++){
                if (subsetNumber & (1 << i)){ // Bit Manipulation
                    subset.push_back(nums[i]);
                }
            }
            result.push_back(subset);
        }
        
        return result;
        
        /*
            The time complexity of the program is O(2^N*N).
            The space complexity of the program is O(N^2).
            n -> size of nums array.
        */
    }
};
