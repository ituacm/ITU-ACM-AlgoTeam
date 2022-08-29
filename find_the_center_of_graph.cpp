// Author: Novruz Amirov
// Question Link: https://leetcode.com/problems/find-center-of-star-graph/

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
            To represent the graph, we will use adjacency
            list due to less complexity of adding node
            in comparison to adjacency matrix.
            The, we will check the number of edges
            for each node. If the node has number of
            edges of the size of edges array (because the number
            of edges in edges array is already equal to the number of
            nodes - 1), then this is the centere node, and we return it.
*/

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        
        // initializing adjacency list with the size of edges plus
        // 2, because of 1 for 1-index representation and 1 for
        // the number of nodes is 1 more than the number of edges.
        vector<vector<int>>adjacencyList(edges.size() + 2, vector<int>(0));    
        
        for (int edge = 0; edge < edges.size(); edge++){
            // because it is undirected graph, we need to add 
            // the edge of nodes to both node in adjacency list.
            adjacencyList[edges[edge][0]].push_back(edges[edge][1]);
            
            // Example: if there is an edge between 1 and 2, the edge
            // must be added to both node in adjacency list.
            adjacencyList[edges[edge][1]].push_back(edges[edge][0]);
        }
        
        // finding the star node.
        for (int node = 1; node < adjacencyList.size(); node++){
            // because the size of edges is already 1 less than
            // the number of nodes, if the number of edges of the 
            // node is equal to the size of edges, return the node.
            if (adjacencyList[node].size() == edges.size())
                return node;
        }
        
        return 0;
        /*
            The complexity of the code is O(n).
            n is the number of nodes.
        */
    }
};
