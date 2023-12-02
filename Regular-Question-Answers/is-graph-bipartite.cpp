// Author: Murat Biberoğlu
// Question: https://leetcode.com/problems/is-graph-bipartite/
// Reviewer: Denis Davidoglu

class Solution {
public:
    vector<int> mark;  // holds colors of nodes
    int n;

    // We need to colorize graph with two colors such that there is
    // no pair of adjacents nodes that they have same color.
    // To do so, we need to traverse all nodes with DFS
    // and we need to detect same color for adjacent nodes.
    bool isBipartite(vector<vector<int>>& graph) {
        this->n = graph.size();
        this->mark = vector<int>(n, -1);  // initalize node colors as -1

        // The graph may not be connected so
        // if there is a uncolored node start dfs from that node
        for (int i = 0; i < this->n; i++) {
            if (mark[i] == -1)
                if (dfs(i, 0, graph) == false)
                    return false;
        }
        return true;
    }

    // Recursive DFS
    bool dfs(int node, int state, vector<vector<int>>& graph) {
        // mark the node with given color
        mark[node] = state;

        // for each adjacent node of "node"
        for (auto nextnode : graph[node]) {
            // if "nextnode" has same color with "node" then
            // this graph is not a bipartite graph, return false
            if (state == mark[nextnode]) return false;

            // if "nextnode" is not colored before that means it is not visited
            // visit "nextnode", remember to revert color with (1 - state)
            else if (mark[nextnode] == -1)
                // if result is false return false
                if (dfs(nextnode, 1 - state, graph) == false)
                    return false;
        }

        // if everything until this point is okey return true
        return true;
    }
};
