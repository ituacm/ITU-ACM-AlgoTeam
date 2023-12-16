/*
 * Author: Ceren Yaşar
 * Question Link: https://leetcode.com/problems/queue-reconstruction-by-height/description/
 * Reviewer: Denis Davidoglu
 *
 * First, let's break down the problem and analyze to really understand what we need to do:
 *
 * Notice that each person in the queue only counts the number of taller people in front of them.
 * This means that short people are overlooked and not counted. So, if we placed everyone to their
 * place except the shortest one with height i and j people ahead, we would be able to start counting
 * from the start and iterate until we reached the number j, which would point to the index where we
 * need to insert the shortest person found so far.
 *
 * Using this detection, we will start placing taller people first and then insert shorter ones in between.
 *
 * Time Complexity: O(N^2)
 * Memory complexity: O(N)
 */

class Solution {
    // Custom comparator to sort the vector according to the following properties:
    // 1) Tallest one comes first.
    // 2) People with the same height are sorted according to their j values in increasing order.
    static bool comparator(vector<int>& v1, vector<int>& v2) {
        if (v1[0] != v2[0]) return v1[0] > v2[0];
        return v1[1] < v2[1];
    }

public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), comparator);
        vector<vector<int>> res;

        for (int i = 0; i < people.size(); i++) {
            // res.begin() + people[i][1] points to the index where the shortest person so far (people[i]) is supposed to be placed
            res.insert(res.begin() + people[i][1], people[i]);
        }
        return res;
    }
};
