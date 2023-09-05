// Author: Kemal Tahir Bıcılıoğlu
// Question Link: https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/

/*
    Common algorithm to find the single path from one node to another node with the smallest weight Dijkstra's algorithm does not work here.
    The reason why it does not work is simply we are asked to find any path from 1 to n and minimum weighted edge on this path.
    The fact that graph is not necessarily connected is not a big problem since we already guaranteed to have a path from 1 to n.
    So we can just apply bfs or dfs to explore the graph starting from 1 which is guaranteed to be the connected component having edges 1 and n nodes,
    and then just finding the minimum weighted edge will be the answer since we can pass an edge multiple times. 
    In summary, apply bfs starting from 1 and find the minimium weighted edge.
*/

// Time Complexity: O(V+E), V = number of vertices, E = number of edges.
// Space Complexity: O(V).

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        // first create adjacency list from the given weighted edges.
        vector<vector<pair<int, int>>> adjacencyList(n + 1); 
        for(auto &edge : roads){ // time complexity of O(E).
            adjacencyList[edge[0]].push_back({edge[1], edge[2]}); // edge[1] is neighbour for edge[0]
            adjacencyList[edge[1]].push_back({edge[0], edge[2]}); 
            // since bidirectional edge[0] is neighbour for edge[1].
        }

        queue<int> bfs;
        vector<bool> visited(n + 1, false); // correct size is n+1 since we are using 1 based indexing.
        bfs.push(1); // start bfs from first node.
        visited[1] = true; 

        int minScore = 1e5;  // initialize it with large value that any weight of edges cannot be.
        while(!bfs.empty()){ // simply apply bfs. time complexity of O(V) since each vertex processed exactly once.
            int currentNode = bfs.front();
            for(auto &neighbour : adjacencyList[currentNode]){
                int currentScore = neighbour.second;
                minScore = min(currentScore, minScore);  // check if new weight is smaller or not.
                if(!visited[neighbour.first]){
                    bfs.push(neighbour.first);
                    visited[neighbour.first] = true;
                }
            }
            bfs.pop();
        }

        return minScore;
    }
};