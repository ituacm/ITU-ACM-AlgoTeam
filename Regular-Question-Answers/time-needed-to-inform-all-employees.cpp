// Author: Ali Kemal Coşkun
// Question Link: https://leetcode.com/problems/time-needed-to-inform-all-employees/
// Reviewer: Denis Davidoglu

// Time complexity: O(N)
// Space complexity: O(N)

// In this question, it is asked to find the deepest leaf (in terms of 'informTime') of the given tree.
// We can use DFS or BFS. The DFS solution is implemented below.
// Unlike most LeetCode tree questions, we need to construct the tree.
// We can build the tree as an adjacency list (adjList is a good choice for DFS/BFS).

class Solution {
   public:
    // Regular DFS function.
    // The 'result' is sent as a parameter to the function.
    // You can also write the code so that 'res' is updated in the main function.
    void dfs(vector<vector<int>>& adjList, vector<int>& informTime, int node, int time, int* res) {
        if (adjList[node].empty()) {
            *res = max(*res, time);
            return;
        }
        for (int i = 0; i < adjList[node].size(); i++)
            dfs(adjList, informTime, adjList[node][i], time + informTime[node], res);
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adjList(n, vector<int>());

        for (int i = 0; i < n; i++) {
            // 'head' has no manager.
            if (i == headID) continue;
            adjList[manager[i]].push_back(i);
        }
        int res = 0;
        dfs(adjList, informTime, headID, 0, &res);

        return res;
    }
};
