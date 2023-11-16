// Author: Anıl Dervişoğlu
// Question Link: https://leetcode.com/problems/construct-the-rectangle/
// Reviewers: Ahmet Furkan Kavraz

/*
    Problem Description: The problem asks for the dimensions of a rectangle that meets the given area.
    The rectangle's length (L) should be greater than or equal to its width (W) (L >= W),
    and the difference between them should be as small as possible.
    The solution finds the largest possible width by checking divisors from square root of the area down to 1,
    with a time complexity of O(sqrt(n)), where n is the given area.
*/

class Solution {
   public:
    vector<int> constructRectangle(int area) {
        // Iterate from the square root of the area down to 1
        for (int width = sqrt(area); width > 1; width--) {
            // Check if width is a divisor of area
            if (area % width == 0) {
                // If a divisor is found, immediately return the dimensions
                // This ensures the difference between length and width is minimized
                return {area / width, width};
            }
        }

        // Return statement, although the loop should already find a solution
        return {area, 1};  // If no divisor is found, default to [area, 1]
    }
};
