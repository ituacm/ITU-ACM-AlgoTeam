// Author: Denis Davidoglu
// Question link: https://leetcode.com/problems/maximum-product-of-three-numbers/
// Reviewers: Murat Biberoğlu, Toygun Görmüş

//The below solution is faster than 96.53% submissions
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        /* There are two options we can get the result: 
            1) Multiply the biggest three numbers
            2) Multiply the biggest number and the two smallest numbers, 
            which are negative. In this case the minus sign cancels out. 
        That being said we need to find the maximum three and minimum two numbers. */

        int n = nums.size();
        /* We will store the maximum values in the priority queue 
        pqMin and minimum values in pqMax. */
        priority_queue<int, vector<int>, greater<int>> pqMin;
        priority_queue<int> pqMax;

        // We fill the maximum values heap with first three numbers 
        for (int i = 0; i < 3; i++) {
            int x = nums[i];
            pqMin.push(x);
        }

        for (int i = 3; i < n; i++) {
            int x = nums[i];
            /* If the current value is even bigger than the smallest 
            value in the heap for maximum values, we can discard 
            the smallest value and add the current. It's size of 
            three doesn't change. */
            if(x > pqMin.top()) {
                pqMin.pop();
                pqMin.push(x);
            }
        }

        // We fill the minimum values heap with just two numbers
        for (int i = 0; i < 2; i++) {
            int x = nums[i];
            pqMax.push(x);
        }

        for (int i = 2; i < n; i++) {
            int x = nums[i];
            /* If the current value is less than the biggest 
            value in the heap for minimum values, we can discard 
            the biggest value and add the current. It's size of 
            two doesn't change.*/
            if(x < pqMax.top()) {
                pqMax.pop();
                pqMax.push(x);
            }
        }

        vector<int> pos;
        vector<int> neg;
        while(!pqMin.empty()) {
            pos.push_back(pqMin.top());
            pqMin.pop();
        }
        while(!pqMax.empty()) {
            neg.push_back(pqMax.top());
            pqMax.pop();
        }
        return max(pos[0]*pos[1]*pos[2], neg[0]*neg[1]*pos[2]);
    }     
};
