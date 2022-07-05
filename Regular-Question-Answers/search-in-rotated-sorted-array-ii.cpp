// Author: Ahmet Furkan Kavraz
// Question Link: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

class Solution {
public:
    bool searchArr(vector<int>& arr, int l, int r, int target){
        
        // check the bounds
        if (l > r || l < 0 || r >= arr.size())
            return false;
        
        // middle index
        int mid = (l + r) / 2;
        
        // the "true" condition
        if (target == arr[mid]){
            return true;
        }

        bool res1 = false, res2 = false;
                
        // if the target can be in the left side of array
        if (arr[l] <= target || target <= arr[mid] ){
            res1 = searchArr(arr, l, mid - 1, target);
        }
        
        // if the target can be in the right side of array
        if (arr[mid] <= target || target <= arr[r] ) {
            res2 = searchArr(arr, mid + 1, r, target);
        }
        return res1 || res2;
    }
    
    
    bool search(vector<int>& arr, int target) {
        return searchArr(arr, 0 , arr.size() - 1, target);
    }
};