// Author: Abdulsamet Ekinci
// Reviewer: 
// Question: https://leetcode.com/problems/subarray-sum-equals-k/

/* 
* Description:
* Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
* A subarray is a contiguous non-empty sequence of elements within an array.

*/

/*

 Solution I: Brute-Force 

* Time complexity: O(n^2)
* Space complexity: O(1)

* In this solution, we start from first index of array and try every possible subarrays which sum is equal to k.

* Since we check all the elements and the subarrays that start with that element. We do n*n operation.
* We don't use any extra space so its O(1).

*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int n = nums.size(); // size of array
        int ans = 0;	// total number of subarray this will be our counter int.

        for(int i = 0; i < n; i++){

            int sum = nums[i]; // first number of any non-empty subarray
          
            if(sum == k) // check if the first number of subarray is equal to k.
            ans++;

            for(int j = i+1; j < n; j++){ // check for every subarray which is starting with i
                sum += nums[i]; // add to sum
                if(sum == k) // check if sum equals k after adding the number.
                ans++;
            }

        }

        return ans; // return total number of subarray

    }
};

/*

 Solution II: Hash Table and Prefix Sum 

* Time complexity: O(n)
* Space complexity: O(n)

* In this solution, we do prefix sum first and then use hash map to check if we find solution. Here how its work:
* Assume that we have an array of [1, 2, 3, 4] and k = 5.
* Our prefix sum will be [1, 3, 6, 10]. We start from first index and if it equals k increase the ans.
* Next step is checking (prefix[i] - k) present in map or not. For example, we are checking prefix[2]. It is nums[0]+nums[1]+nums[2]
* prefix[2] - 5 = 1. Which is first element of prefix sum. Thus, we can say that prefix[2] - nums[0] = nums[1] + nums[2] = 5.

* Since we have done n operation during prefix sum and n operation during for loops. Time complexity is O(n). 
* Reminder: find operation for hash map takes constant time o(1).
* We have used prefix sum array and hash map. 
* In the worst case, the hash map could store all unique cumulative sums so that O(n) space complexity. 
* For prefix sum array its again O(n).

*/
class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size(); // size of the array
        
        int prefix[n]; // make a prefix array to store prefix sum. This causes extra space
        
        prefix[0] = arr[0]; // define at index zero
        
        // prefix sum
        for(int i = 1; i < n; i++)
        {
            prefix[i] = arr[i] + prefix[i - 1];
        }
        
        unordered_map<int,int> mp; // hash map and also causes extra space
        
        int ans = 0; // total number of subarray that equals k this will be our counter int
        
        for(int i = 0; i < n; i++) 
        {
            if(prefix[i] == k) // if it already becomes equal to k, then increment ans
                ans++;
            
            // find whether (prefix[i] - k) present in map or not
            if(mp.find(prefix[i] - k) != mp.end())
            {
                ans += mp[prefix[i] - k]; 
            }
            
            mp[prefix[i]]++; // put prefix sum into map
        }
        
        return ans; // return total number of subarray
    }
};

/* 

For Solution II we don't even need an extra array to store prefix sum. It can be only hash map and integer sum. 

*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        
        int sum = 0, result = 0;
        map[sum] = 1;
        
        for (int n : nums) {
            sum += n;
            result += map[sum - k];
            map[sum]++;
        }
        
        return result;
    }
};
