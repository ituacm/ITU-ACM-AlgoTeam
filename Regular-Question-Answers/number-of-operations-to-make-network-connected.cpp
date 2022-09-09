// Author: Denis Davidoglu
// Question Link: https://leetcode.com/problems/number-of-operations-to-make-network-connected/
// Reviewers: Murat Biberoğlu, Toygun Görmüş

class Solution {
public:
    vector<bool> visited;
    vector<list<int>> graph;
    int disjointCount;

    // Regular Depth First Search algorithm
    void dfs(int node){
        visited[node] = true;
        for (auto neighbour:graph[node])
            if (!visited[neighbour])
                dfs(neighbour);
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        /* In order for a graph with n nodes to be connected, it must have 
        at least n-1 connections. Otherwise no matter how we change the edges 
        it would be impossible to solve the problem. */
        if (connections.size()+1 < n) return -1;

        for (int i = 0; i < n; i++) visited.push_back(false);
        
        /* Translating the graph data into a more convinient structure. 
        Each graph[i] represents an array containing the neighbours of i.*/
        graph.resize(n);
        for (auto c:connections) {
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }

        /* Here we count the number of disjoint subgraphs. For loop gives 
        us access to any remote node while dfs explores the subgraph and 
        marks it as visited. */
        disjointCount = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                disjointCount++;
                dfs(i);
            }
        }

        /* The answer is the minimum number of edges required to connect 
        all the subgraphs.*/
        return disjointCount-1;
    }
};