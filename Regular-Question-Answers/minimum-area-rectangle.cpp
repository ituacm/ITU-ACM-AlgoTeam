// Author: Murat Biberoğlu
// Reviewer: Ahmet Furkan Kavraz
// Question Link: https://leetcode.com/problems/minimum-area-rectangle/

class Solution {
public:
    /**
     * the idea is checking all pairs of points on the diagonal and form a
     * rectangle let these two points are P1 = (x1, y1) and P2 = (x2, y2)
     *
     * first, we are checking that if they are on the same line like x = c or y
     * = c (c is constant) if true, then we cannot form a rectangle from these
     * two points if false, then we are checking the existince of other two
     * points (x1, y2) and (x2, y1) to do this we are using a map, keys are x
     * values of all points and values are set of y values that point (x, y)
     * exist in points
     */
    int minAreaRect(vector<vector<int>> &points) {
        int length = points.size();

        unordered_map<int, unordered_set<int>> pointCoordinatesSets;
        for (int i = 0; i < length; i++) {
            pointCoordinatesSets[points[i][0]].insert(points[i][1]);
        }

        int minArea = INT_MAX;

        for (int i = 0; i < length - 1; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];

            for (int j = i + 1; j < length; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];

                if (x1 != x2 && y1 != y2 &&
                    pointCoordinatesSets[x1].find(y2) != pointCoordinatesSets[x1].end() &&
                    pointCoordinatesSets[x2].find(y1) != pointCoordinatesSets[x2].end()) {
                    minArea = min(minArea, abs((x1 - x2) * (y1 - y2)));
                }
            }
        }
        return minArea == INT_MAX ? 0 : minArea;
    }
};