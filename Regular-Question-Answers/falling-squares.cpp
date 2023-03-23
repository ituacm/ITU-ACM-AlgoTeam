// Author: Murat Biberoğlu
// Question Link: https://leetcode.com/problems/falling-squares/

// When a square falls we need to update heights of the points that in the range.
// However we need to do that in a fast way therefore we are going to use Segment Tree with Lazy Propagation.

// The range of numbers is [0, 10^8] and each opearation on Segment Tree is
// O(n*log n), therefore just using Segment Tree is not sufficient.
// To overcome this problem we are going to compress numbers in a smaller range without losing order of numbers.
class Solution {
   public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        compress(positions);

        vector<int> ans;
        for (int i = 0; i < positions.size(); i++) {
            int start = compressed[positions[i][0]];                        // Include start
            int end = compressed[positions[i][0] + positions[i][1]] - 1;    // Exclude end
            int h = positions[i][1];

            int initialHeight = getMax(0, 0, counter - 1, start, end);  // Height of the square

            // set height of the range to the initialHeight + h
            updateRange(0, 0, counter - 1, start, end, initialHeight + h);

            ans.push_back(getMax(0, 0, counter - 1, 0, counter - 1));
        }

        return ans;
    }

   private:
    unordered_map<int, int> compressed;
    vector<int> tree;
    vector<int> lazy;
    int counter;

    // regular compress function
    void compress(vector<vector<int>>& positions) {
        set<int> s;
        for (int i = 0; i < positions.size(); i++) {
            s.emplace(positions[i][0]);
            s.emplace(positions[i][0] + positions[i][1]);
        }

        counter = 0;
        for (auto it = s.begin(); it != s.end(); it++) {
            compressed[*it] = counter++;
        }

        tree = vector<int>(4 * counter, 0);
        lazy = vector<int>(4 * counter, 0);
    }

    // regular update range function
    void updateRange(int index, int st_l, int st_r, int q_l, int q_r, int newValue) {
        if (lazy[index] != 0) {
            tree[index] = lazy[index];
            if (st_l != st_r) {
                lazy[index * 2 + 1] = lazy[index];
                lazy[index * 2 + 2] = lazy[index];
            }
            lazy[index] = 0;
        }

        if (st_l > st_r || st_l > q_r || st_r < q_l)
            return;

        if (st_l >= q_l && st_r <= q_r) {
            tree[index] = newValue;
            if (st_l != st_r) {
                lazy[index * 2 + 1] = newValue;
                lazy[index * 2 + 2] = newValue;
            }
            return;
        }

        int mid = (st_l + st_r) / 2;
        updateRange(index * 2 + 1, st_l, mid, q_l, q_r, newValue);
        updateRange(index * 2 + 2, mid + 1, st_r, q_l, q_r, newValue);

        tree[index] = max(tree[index * 2 + 1], tree[index * 2 + 2]);
    }

    // regular get max function
    int getMax(int index, int st_l, int st_r, int q_l, int q_r) {
        if (lazy[index] != 0) {
            tree[index] = lazy[index];

            if (st_l != st_r) {
                lazy[index * 2 + 1] = lazy[index];
                lazy[index * 2 + 2] = lazy[index];
            }

            lazy[index] = 0;
        }

        if (st_l > st_r || st_l > q_r || st_r < q_l)
            return 0;

        if (st_l >= q_l && st_r <= q_r)
            return tree[index];

        int mid = (st_l + st_r) / 2;
        return max(getMax(2 * index + 1, st_l, mid, q_l, q_r),
                   getMax(2 * index + 2, mid + 1, st_r, q_l, q_r));
    }
};
