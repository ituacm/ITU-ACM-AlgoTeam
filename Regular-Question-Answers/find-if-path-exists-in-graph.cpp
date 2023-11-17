// Author: Hacer Akıncı
// Reviewer: Ahmet Furkan Kavraz
// Question Link: https://leetcode.com/problems/find-if-path-exists-in-graph/

class Solution {
public:
    int findRoot(vector<int>& parent, int node) {
        // If there is no parent of the node, then node itself is root
        if (parent[node] == -1) {
            return node;
        }

        // else if the node has a parent, return until find the root
        // same time we assign root index to its child for saving time complexity
        return parent[node] = findRoot(parent, parent[node]);
    }

    void uniteSets(vector<int>& parent, int u, int v) {
        int x = findRoot(parent, u);  // root of u node
        int y = findRoot(parent, v);  // root of v node

        // if roots are same then the graph is already connected there is no need to connect
        if (x == y)
            return;

        // making the second node parent to the root of the first node
        // So, two node are connected with one root
        parent[x] = v;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // if source is equal destination then there is a path to itself
        if (source == destination)
            return true;

        // store root indexes of nodes
        // for determining if the node is root or not, if it is root its equal to -1
        // initally all nodes are unconnected each other, so each node is root itself
        vector<int> parent(n, -1);

        for (vector<int>& edge : edges) {
            int u = edge[0], v = edge[1];

            // u is first node, v is second there is edge between them, so connect each other
            uniteSets(parent, u, v);

            // if there is a path between two nodes, they are connected and their root are same
            if (findRoot(parent, source) == findRoot(parent, destination))
                return true;
        }

        return false;
    }
};