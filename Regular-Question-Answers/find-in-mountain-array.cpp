/*
Author: Hüseyin Burak Gürdal
Question Link: https://leetcode.com/problems/find-in-mountain-array/

Time Complexity: O(logn)
Space Complexity: O(1)
*/

// Solution:
// The mountain array is a bitonic array in other words it is increasing and then decreasing.
// If we find the peak of the mountain array we can divide the array into two sorted arrays so we can use binary search to find the target.

// First we need to find the peak of the mountain array. We can use binary search to find the peak.
// When searching for the peak we need to check the mid element and its neighbours. If the mid element is greater than its neighbours then it is the peak.
// If the mid element is greater than its left neighbour and smaller than its right neighbour then the peak is on the right side of the mid element.
// If the mid element is smaller than its left neighbour and greater than its right neighbour then the peak is on the left side of the mid element.

// After finding the peak we can divide the array into two sorted arrays. First one is [0, peak] increasing array and the second one is [peak+1, n-1] decreasing array.
// We can use binary search to find the target in both of the arrays.
// We must first look for the target in the increasing array and if we can't find it then we can look for it in the decreasing array because the problem asks for the first occurence of the target.

// When performing binary search on the second array we must be careful that the array is decreasing so the conditions for the binary search is inverse of the increasing array.


/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution 
{
public:
    int findInMountainArray(int target, MountainArray &mountainArr) 
    {
        int n = mountainArr.length();

        // Find the peak of the mountain array
        int peak = -1;
        int l = 1, r = n-2;
        while(l <= r)
        {
            int m = (l+r)/2;
            int a = mountainArr.get(m-1), b = mountainArr.get(m), c = mountainArr.get(m+1);
            if(b > a && b > c) // Peak found
            {
                peak = m;
                break;
            }
            else if(b > a && b < c) l = m+1; // Peak is on the right side
            else r = m-1; // Peak is on the left side
        }

        // Binary search for the target in the increasing array
        l = 0, r = peak;
        while(l <= r)
        {
            int m = (l+r)/2;
            int x = mountainArr.get(m);
            if(x == target) return m; // Target found in the increasing array
            else if(target < x) r = m-1; // Target is on the left side
            else l = m+1; // Target is on the right side
        }

        // Binary search for the target in the decreasing array
        l = peak+1, r = n-1;
        while(l <= r)
        {
            int m = (l+r)/2;
            int x = mountainArr.get(m);
            if(x == target) return m; // Target found in the decreasing array
            else if(target < x) l = m+1; // Target is on the right side
            else r = m-1; // Target is on the left side
        }

        return -1; // Target not found
    }
};
