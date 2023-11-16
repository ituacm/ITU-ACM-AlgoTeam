// Author: Bilgenur Çelik
// Question Link: https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/
// Reviewers: Novruz Amirov, Ömer Faruk Erdem, Denis Davidoglu

// Time comp. -> O(n) (n = plank's length)
// Space comp. -> O(1)

class Solution {
   public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        /* Answer is the max distance for one ant to reach the end of the plank
        * in the facing direction. But when two ants meet at some point,
        * they change their directions and continue moving again in constant time.
        * So what is the difference between changing the directions and
        * continuing without any interactions? After all, ants are the same.
        * Thus, let's assume they don't change direction.

        * Calculate the maximum time needed that an ant can achieve to an edge.
        * (n = plank's length)
        */
        int time = 0;

        // if they're going left they have i units
        for (int i : left) time = max(time, i);

        // if they're going right they have n-i units
        for (int i : right) time = max(time, n - i);

        return time;
    }
};
