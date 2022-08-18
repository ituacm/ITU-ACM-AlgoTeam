// Author: Ceren Yaşar
// Reviewer: Ahmet Furkan Kavraz
// Question Link: https://leetcode.com/problems/climbing-stairs/

/*
 * This solution uses a recursive dynamic programming approach with memoization to speed up the calculation.
 * An iterative solution would also be possible considering how the logic behind the question is very much
 * like fibonacci series. 
 * 
 * Time complexity: O(n)
 *
 * Memory complexity: O(n) 
 */

class Solution {
    
    int climb(int n, vector<int> &computed) {
        
        // if we ever reach 0 or 1 with n, we have successfully calculated one valid way of
        // climbing to the top
        if (n==0 || n==1) {
            return 1;
        } 
        // if n is below 0, it means the previous step size was too big therefore does not count
        else if (n<0)
            return 0;
        
        /* this line helps us skip extra work. think of a binary tree representing the values to
         * be computed: to compute climb(n), we need to compute climb(n-1)+climb(n-2). and to
         * get climb(n-1), we need to compute climb(n-2)+climb(n-3). see how it goes? we called
         * climb function twice for the value (n-2). this happens more as the values get lower.
         * keeping our calculations stored saves a lot of time.
         */
        if (computed[n]) return computed[n];
        
        computed[n-1] = climb(n-1,computed);
        computed[n-2] = climb(n-2,computed);
        
        // to reach nth step, we could have climbed 1 or 2 steps at once.
        return computed[n-1]+computed[n-2];
    }
    
public:
    int climbStairs(int n) {

        //1-based indexing
        vector<int> computed(n+1); 
        
        return climb(n,computed);
    }
};
