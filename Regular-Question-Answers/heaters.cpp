// Author: Bilgenur Çelik
// Question Link: https://leetcode.com/problems/heaters/
// Reviewer: Denis Davidoglu
// Time Comp.: O(nlog(m)) n = houses.size() m = heaters.size()

class Solution {
   public:
    /* With this helper find the closest heater's distance using binary seach.*/
    int helper(int house, vector<int>& heaters, int begin, int end) {
        int dist = INT_MAX;
        int mid;

        while (begin < end) {
            mid = (begin + end) / 2;
            // check each mid-point's distance.
            dist = min(abs(heaters[mid] - house), dist);

            // if closers are on left:
            if (heaters[mid] > house) end = mid;
            // if closers are on right:
            else
                begin = mid + 1;
        }

        return dist;
    }

    int findRadius(vector<int>& houses, vector<int>& heaters) {
        // sort heaters to apply binary search on this vector
        sort(heaters.begin(), heaters.end());
        // minimum radius will be the most comprehensive radius
        int minRadius = INT_MIN;

        // find the closest heater's distance for each house
        for (int i : houses)
            minRadius = max(minRadius, helper(i, heaters, 0, heaters.size()));

        return minRadius;
    }
};
