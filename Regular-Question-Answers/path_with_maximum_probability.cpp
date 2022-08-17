// Author: Novruz Amirov
// Question Link: https://leetcode.com/problems/path-with-maximum-probability/

/*
    Problem Description:
    
        We are given an UNDIRECTED graph of n nodes.
        The nodes are 0-indexed, which means in adjacency
        list we do not need to use 1 additional memory for
        1-index nodes.
        Then, we are given succProb vector, which displays
        us the propability of the edge between 2 nodes.
        Finally, we are given start and end inputs to
        know from which node to start and end.
        
        Note: The probability is calculated by multiplying.
        
        Example:
            The Graph:
                (0) ---> (1), with the weight of 0.8
                (0) ---> (2), weight = 0.6
                (1) ---> (3), weight = 0.1
                (2) ---> (3), weight = 0.9
                
            starting point is 0, ending point is 3.
            Totally there is 2 way of coming to the node 3
            starting from the node 1. 
            First is (0) ---> (1) ---> (3), probability = 0.08
            Second is (0) ---> (2) ---> (3), probability = 0.54
        
            Because 0.54 is bigger than 0.08, we will return 0.54
        
    
    Data types, structurem, and algortihms used for this question:
        We will use Data Types of bool, int, and double.
            bool -> for visited vector to check if the node is visited or not.
            int -> for the node numbers.
            double -> for the probability.
        
        As a Data Structures:
            vector<vector<pair<int, double>>> for adjacency list,
            adjacency list is more efficient than adjacency matrix
            when used in Dijkstra algorithm.
            
            We will also use vectors as a data structure for
            visited and probabilities array, to check if the
            node is visited or not, and to store the probabilities
            of each node,
            
            Priority Queue will be used for Dijkstra algorithm.
        
        As an Algorithm:
            As I mention above, we will use Dijkstra algorithm, 
            normally Dijsktra is used for finding the minimum distance
            or probability, but we will use it reversely for maximum.
        
*/




class Solution {
public:
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        // initializing 0-index adjacency list to use the Graph.
        vector< vector< pair<int, double> > >adjacency_list(n, vector< pair<int, double> >(0)); 
        
        double max_probability = 0; //initializing max_probability.
        
        
        
        for(int i = 0; i < edges.size(); i++){ 
            
            // because it is undirected graph we need to add 
            // the nodes and probabilities to both row(node) in adjacency matrix.
            
            adjacency_list[edges[i][0]].push_back(make_pair(edges[i][1], succProb[i])); 
            // example: if there is edge from 1 to 2 with the
            // probability of 0.5, then there is also an edge from 2 to 1 with the same probability (0.5).
            
            adjacency_list[edges[i][1]].push_back(make_pair(edges[i][0], succProb[i]));
            
        }
        
        
        // From here Dijkstra Algorithm starts.
        
        // initializing probabilities vector to hold the
        // probabilities of going to each node from starting node.
        vector<double> probabilities(n, 1); 
        
        vector<bool> visited(n, false); //initializing visited vector not to visit one node more than once.
        
        priority_queue< pair<double, int> > priorityQueue; // pair of probabily and node number for priority queue
        
        // in order to start from starting point, 
        // starting point is pushed to priority queue
        // with the probability of 0.
        priorityQueue.push({0, start});
        
        while(!priorityQueue.empty()){
            int a = priorityQueue.top().second; // a is the starting node of the any 2 connected nodes.
            priorityQueue.pop();
            
            if(visited[a]){ // if node a is visited skip this loop.
                continue;
            }
            
            visited[a] = true; // make node a true in visited array, in order not to loop through the node a again.
            
            for(auto u : adjacency_list[a]){
                int b = u.first; // b is the ending node of the relation between any 2 connected nodes
                double w = u.second; // to store the probability between a and b.
                
                if(probabilities[b] == 1 || probabilities[b] < probabilities[a] * w){ 
                    // if probability[b] is 1 it means, 
                    // it is the first time we are changing the probabilities[b].
                    // on the other hand we need to change it if a new probability is greater than the old one.
                    
                    probabilities[b] = probabilities[a] * w;
                    
                    priorityQueue.push({probabilities[b], b}); 
                    // to find max probability push probabilities[b].
                    // if we would want to find min probability we would push -distance[b].
                }    
                
            }
            
        }
        
        // if the end node in visited array returns false,
        //it means there is no way of coming end node. Thus probability for that node is 0. 
        if(!visited[end])
            probabilities[end] = 0;
        
        
        // whether visited[end] is false or true
        // we will return the max probability of end node.
        max_probability = probabilities[end]; 
        
        return max_probability;
    }
};
