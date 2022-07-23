// Author: Ahmet Furkan Kavraz
// Question Link: https://leetcode.com/problems/rectangle-area

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {

        return (ay2-ay1)*(ax2-ax1) + // area of first rectangle
            (by2-by1)*(bx2-bx1) -  // area of second rectangle
            // last two line is the intersection of two rectangle, if there exist
            max( min(ay2, by2) - max(ay1, by1), 0) * // the height of intersection
                max( min(ax2, bx2) - max(ax1, bx1), 0); // the width of intersection
            
    }
};