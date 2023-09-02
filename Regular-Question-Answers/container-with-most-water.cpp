//Author: Semih Gençten
//Question link: https://leetcode.com/problems/container-with-most-water/

#include <bits/stdc++.h>
using namespace std;
/*
    I implemented the two pointer technique for the solution.
    Time complexity: O(n)
    Space Complexity: O(1) 
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int leftPointer = 0, rightPointer = height.size() - 1; //pointers are inialized
        int maxArea = 0; 
        
        while(leftPointer != rightPointer)
        {
            int shortLine = min(height[leftPointer], height[rightPointer]); //Since the shorter line will determine the amount of water, we take the short line's height
            int area = (rightPointer - leftPointer) * shortLine; //Calculate the area for current iteration
            maxArea = max(maxArea, area); //compare and determine the new maximum area
            //this part arranges the pointers for the next iteration
            if(shortLine == height[leftPointer])
            {
                leftPointer++;
            }
            else{
                rightPointer--;
            }
        }
        return maxArea;
    }
};
