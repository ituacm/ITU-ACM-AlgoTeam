// Author: Rojen Arda Şeşen
// Question Link: https://leetcode.com/problems/most-beautiful-item-for-each-query/
// Reviewer: Denis Davidoglu


class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // Sorting items in ascending order according to their prices.
        sort(items.begin(), items.end());

        // Creating a new vector to hold queries with their initial indexes.
        // This will allow us to know what was query's position before sorting.
        vector<pair<int, int>> queryWithIndexes(queries.size());
        for (int i = 0; i < queries.size(); i++)
            queryWithIndexes[i] = {queries[i], i};
        
        // Sorting queries according to their prices, from lowest to highest.
        sort(queryWithIndexes.begin(), queryWithIndexes.end());

        int itemIndex = 0;
        vector<int> maximumBeauties(queries.size()); // Output vector

        // The most beautiful item with a price not higher than the current query will
        // always be on the top of this priority queue.
        priority_queue<int> mostBeautiful;

        for (auto& query: queryWithIndexes) {
            // Pushing next item into the pq if its price is valid.
            while (itemIndex < items.size() && query.first >= items[itemIndex][0]) {
                mostBeautiful.push(items[itemIndex++][1]);
            }

            // Returning the most beautiful item if exists, 0 else.
            maximumBeauties[query.second] = mostBeautiful.empty() ? 0 : mostBeautiful.top();
        }

        return maximumBeauties;
    }
};
