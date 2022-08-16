// Author: Novruz Amirov.
// Question Link: https://leetcode.com/problems/path-with-maximum-probability/

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector< vector< pair<int, double> > >adjacency_list(n, vector< pair<int, double> >(0)); 
        // initializing 1-index adjacency matrix 
        // containing n vectors of pairs of double (probability) and int (node number). 
        
        double max_probability = 0; //initializing max_probability.
        
        for(int i = 0; i < edges.size(); i++){ // because it is undirected graph we need to add 
        // the nodes and probabilities to both row(node) in adjacency matrix.
            
            adjacency_list[edges[i][0]].push_back(make_pair(edges[i][1], succProb[i])); 
            //example: if there is edge from 1 to 2 with the
            // probability of 0.5, then there is also an edge from 2 to 1 with the same probability (0.5).
            
            adjacency_list[edges[i][1]].push_back(make_pair(edges[i][0], succProb[i]));
        }
        
        vector<double> probabilities(n, 1); //initializing probabilities vector to hold the
        // probabilities of going to each node from starting node.
        
        vector<bool> visited(n, false); //initializing visited vector not to visit one node more than one.
        priority_queue< pair<double, int> > pq; // using priority queue for implementing Dijkstra algorithm.
        pq.push({0, start}); // in order to start from starting point, starting point is pushed to priority queue.
        
        while(!pq.empty()){
            int a = pq.top().second; // a is the starting node of the any 2 connected nodes.
            pq.pop();
            
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
                    
                    pq.push({probabilities[b], b}); 
                    // to find max probability push probabilities[b].
                    // if we would want to find min probability we would push -distance[b].
                }    
                
            }
            
        }
        
        if(!visited[end]){ // if the end node in visited array returns false,
            //it means there is no way of coming end node. Thus probability for that node is 0. 
            
            probabilities[end] = 0;
        }
        
        max_probability = probabilities[end]; // whether visited[end] is false or true
        // we will return the max probability of end node.
        
        return max_probability;
    }
};