// Author: Murat Biberoğlu
// Question Link: https://leetcode.com/problems/most-visited-sector-in-a-circular-track/
// Reviewers: Bilgenur Çelik, Denis Davidoglu

// Time Complexity O(n*r), r is the number of rounds
// Space Complexity O(n)

class Solution {
   public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        // holds the count of visiting for each sector
        vector<int> counts(n, 0);
        // number of rounds
        int round = rounds.size() - 1;

        // for each round increment one range [start, finish)
        // finish is not in the range beacuse we want to prevent counting twice
        // a sector. but we need to increment specially finish of the last
        // round.
        for (int r = 0; r < round; r++) {
            int start = rounds[r];
            int end = rounds[r + 1];

            // make sectors 0-indexed
            start--;
            end--;

            // if start < end we won't go over starting sector
            // so increment range [start, end)
            // in the else block, we will go over starting sector
            // so we need to increment range [start, n-1] U [0, end)
            if (start < end) {
                // increment [start, end)
                for (int i = start; i < end; i++) {
                    counts[i]++;
                }
            } else {
                // increment [start, n-1]
                for (int i = start; i < n; i++) {
                    counts[i]++;
                }
                // increment [0, end)
                for (int i = 0; i < end; i++) {
                    counts[i]++;
                }
            }
        }
        // don't forget to increment last round's finish sector
        counts[rounds[round] - 1]++;

        // find the maximum visited sector's value
        int maximum = INT_MIN;
        for (int i = 0; i < n; i++) {
            maximum = max(maximum, counts[i]);
        }

        // find the maximum visited sectors
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (counts[i] == maximum) {
                result.push_back(i + 1);
            }
        }

        // sort the sectors in ascending order
        sort(result.begin(), result.end());
        return result;
    }
};
