// Author: Denis Davidoglu
// Question link: https://leetcode.com/problems/spiral-matrix/
// Reviewers: Murat Biberoğlu, Toygun Görmüş

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int i, j, i_direction, j_direction, i_step, j_step;

        // i and j are the coordanates of current cell.
        i = 0;
        j = -1;

        /* i_direction and j_direction indicate by how much i and j
        change  every iteration. Directions vary between -1, 0 and 1.*/
        i_direction = 0;
        j_direction = 1;

        /* i_step and j_step indicate the longest distance accomplishable
        on the given axis. Since we go in a spiral and don't go over the
        same elements, the steps will gradually decrease. */
        i_step = matrix.size() - 1;
        j_step = matrix[0].size();

        // We stop when we have no steps left
        while (i_step >= 0 && j_step >= 0) {
            if (i_direction) {
                for (int k = 0; k < i_step; k++) {
                    i += i_direction;
                    result.push_back(matrix[i][j]);
                }
                i_step--;
                j_direction = -i_direction;
                i_direction = 0;
            } else if (j_direction) {
                for (int k = 0; k < j_step; k++) {
                    j += j_direction;
                    result.push_back(matrix[i][j]);
                }
                j_step--;
                i_direction = j_direction;
                j_direction = 0;
            }
            /* The last two lines in each if statement transform the direction:
              from [0, 1] to [1, 0]
              from [1, 0] to [0, -1]
              from [0, -1] to [-1, 0]
              from [-1, 0] to [0, 1];
              therefore giving a "clock-wise rotation". */
        }
        return result;
    }
};
