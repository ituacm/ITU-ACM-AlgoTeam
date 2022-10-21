// Author: Novruz Amirov
// Question Link: https://leetcode.com/problems/find-center-of-star-graph/
// Reviewers: Ahmet Furkan Kavraz, Emre Çelik, Denis Davidoglu

/*
    Problem Description:
        This is an UNDIRECTED Graph question.
        We are given 2-D array of edges, where
        edges[i] is [a, b], meaning that there is 
        an edge between node a and node b.
        
        The aim is to find the center node of a 
        star graph. A star graph is a graph that
        has a centered node. A centered node in star
        graph means that the node has edges with all 
        other nodes in graph.
        
        Example: edges -> [[1,2], [2,3], [4,2]]
            1 <--> 2
            2 <--> 3
            4 <--> 2
            There is four nodes. It means we need to
            find the centered node which has 3 edges.
            The node 2 has 3 edges, it means the centered
            node is the node 2. So, return 2.
            
        Code Explanation:
            Because we know that we are given an arrat of edges
            with the size of exactly n-1. This means, to find
            the center of graph, which will have connection
            with all other nodes, the centered node must be in
            every edges. For this it is enough to check first 
            2 connection. The node which is in both 1st connection
            and 2nd connection is the centered node so return it.
*/

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
        // Either first node or second node of the first
        // connection will be the centered node of the graph.
        if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]){
            
            // If the node in both connection is the first node return it.
            return edges[0][0];
        }
        else if (edges[0][1] == edges[1][0] || edges[0][1] == edges[1][1]){
            
             // If the node in both connection is the second node return it.
            return edges[0][1];
        }
        
        return 0; // The program will not come here.
        
        /*
            The time complexity of the program is O(1).
            The space complexity of the program is O(1).
        */
    }
};
