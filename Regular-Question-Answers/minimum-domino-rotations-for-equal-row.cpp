// Author: Denis Davidoglu
// Question Link: https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/

/* If there exists a number which can fill a whole row, it will be present at the zeroth index as well.	*
 * We can take as a target the zeroth element of the tops array and check if a full row can be created. *
 * While doing this, it is important to keep track of how many swaps are needed to arrange that value on*
 * both top and bottom side. If we can get to the end of array, we return the minimum number of swaps.	*
 * The same procedure is done again for target set to be equal to the zeroth element of the bottoms	*
 * array. Note that if in the first loop an answer is found, there is no need to execute the second	*
 * loop. The only case when the both loops give an answer is when there is the same domino repeated,	*
 * rotated differently. Even in this case, either loop gives the same answer.				*/

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size(), counterTop, counterBottom, target;

        target = tops[0];
        counterTop = counterBottom = 0;
        for (int i = 0; i < n && (tops[i] == target || bottoms[i] == target); i++) {
            counterTop += (target != tops[i]);
            counterBottom += (target != bottoms[i]);
            if (i == n - 1) return min(counterTop, counterBottom);
        }

        target = bottoms[0];
        counterTop = counterBottom = 0;
        for (int i = 0; i < n && (tops[i] == target || bottoms[i] == target); i++) {
            counterTop += (target != tops[i]);
            counterBottom += (target != bottoms[i]);
            if (i == n - 1) return min(counterTop, counterBottom);
        }
        return -1;
    }
};
