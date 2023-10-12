// Author: Murat Biberoğlu
// Reviewer: Ahmet Furkan Kavraz
// Question Link: https://leetcode.com/problems/count-number-of-teams/


class Solution {
   public:
    // The idea is checking all the pair of indexes (i, j)
    // such that 0 <= i < j < n - 1
    //
    // if rating[i] > rating[j] we need to get number of elements in range
    // (j, n-1] such that j < k (index) and rating[j] > rating[k]
    //
    // if rating[i] < rating[j] we need to get number of elements in range
    // (j, n-1] such that j < k (index) and rating[j] < rating[k]
    //
    // to get these values faster, we are going to calculate number of greater
    // and smaller elements for each element and save it to vectors.
    // this is a dynamic programming technique and it decreases the time
    // complexity to O(n^2). If we don't use that and calculate these values
    // every time, algorithm's time complexity will be approximately O(n^3)
    int numTeams(vector<int>& rating) {

        int n = rating.size();
        int result = 0;

        // Create a vector with n elements with 0 initial value
        vector<int> greaterElementCountAfterThis(n, 0);
        vector<int> smallerElementCountAfterThis(n, 0);

        // for each index in range [0, n-1)
        for (int i = 0; i < n - 1; i++) {

            // check indexes in range [i+1, n)
            for (int j = i + 1; j < n; j++) {

                // if next element is greater
                if (rating[j] > rating[i])
                    greaterElementCountAfterThis[i]++;  // increment greater for i

                // if next element is smaller
                else
                    smallerElementCountAfterThis[i]++;  // increment smaller for i

            }

        }

        // checking all the pairs of indexes (i, j) such that 0 <= i < j < n - 1
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {

                // if second rating is greater than first one
                if (rating[j] > rating[i])
                    // third rating must be greater than second rating too
                    result += greaterElementCountAfterThis[j];

                // if second rating is smaller than first one
                else
                    // third rating must be smaller than second rating too
                    result += smallerElementCountAfterThis[j];
            }
        }

        return result;
    }
};