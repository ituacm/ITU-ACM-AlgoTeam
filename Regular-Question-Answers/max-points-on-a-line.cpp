// Author: Murat Biberoglu
// Question Link: https://leetcode.com/problems/max-points-on-a-line/

// The idea is counting the number of points on each line
// which is described by all point pairs and taking their maximum
class Solution {
   public:
    int maxPoints(vector<vector<int>>& points) {
        int length = points.size();

        // if the number of points less than 3, then there is nothing to control
        if (length < 3) return length;

        int result = 2;
        for (int i = 0; i < length - 1; i++) {
            for (int j = i + 1; j < length; j++) {
                int pointsOnLine = 2;   // line that passes through point i and j
                for (int k = 0; k < length; k++) {
                    if (k == i || k == j) continue; // do not count more than once
                    if (onTheSameLine(points, i, j, k)) pointsOnLine++;
                }
                result = max(result, pointsOnLine);
            }
        }
        return result;
    }

    // returns true if all the points at the same line else returns false
    bool onTheSameLine(vector<vector<int>>& points, int p1, int p2, int p3) {
        int dist_x_1 = points[p1][0] - points[p2][0];
        int dist_y_1 = points[p1][1] - points[p2][1];

        int dist_x_2 = points[p1][0] - points[p3][0];
        int dist_y_2 = points[p1][1] - points[p3][1];

        // if the slopes are equal then the points are on the same line
        return dist_x_1 * dist_y_2 == dist_x_2 * dist_y_1;
    }
};