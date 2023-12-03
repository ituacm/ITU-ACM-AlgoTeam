// Author: Rojen Arda Şeşen
// Question Link: https://leetcode.com/problems/network-delay-time/
// Reviewer: Denis Davidoglu

// This problem is basically a shortest path problem.
// We will use Dijkstra's Shortest Path algorithm to find the shortest
// paths to all nodes. Then, we will return the largest number or -1 if
// not all nodes are reachable.
// We will first transform the given edge list into an adjacency list.
// We will create a priority queue that stores the unvisited nodes sorted
// by their distances to the source node in ascending order.
// While traversing, we will push all the unvisited adjacent nodes to the queue.
// At each step, we will pop one node from the queue and repeat the process
// until no more nodes are left in the queue.
// After traversing, we will check the found distances and return the largest
// If a node is left unvisited, we will return -1 instead.

// Time Complexity: O(n^2) where n is the number of nodes.
// Space Complexity: O(n + e); n: number of nodes, e: number of edges.

class Solution {
public:
    // Custom comparator object to use priority queue as a min heap.
    struct customComparator {
        bool operator()(pair<int, long> const& p1, pair<int, long> const& p2) {
            return p1.second > p2.second;
        }
    };
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<long> dist(n + 1, LONG_MAX);
        vector<vector<pair<int, int>>> aList(n + 1);
        priority_queue<pair<int, long>, vector<pair<int, long>>, customComparator> closestNode;
        vector<bool> visited(n + 1, false);
        long currentDistance;
        int currentNode;
        // A node's distance to itself is 0.
        dist[k] = 0;
        // Fill the adjacency list.
        for (auto& v : times)
            aList[v[0]].push_back({v[1], v[2]});

        // Push the starting node to the priority queue and initialize Dijkstra.
        closestNode.push({k, 0L});
        while (!closestNode.empty()) {
            currentNode = closestNode.top().first;
            closestNode.pop();

            if (visited[currentNode]) continue;

            visited[currentNode] = true;

            for (auto& v : aList[currentNode]) {
                if (v.first == currentNode) continue;

                if (dist[v.first] > dist[currentNode] + v.second) {
                    dist[v.first] = dist[currentNode] + v.second;
                    closestNode.push({v.first, dist[v.first]});
                }
            }
        }

        long maxDist = 0;
        for (int i = 1; i < n + 1; i++) {
            if (dist[i] == LONG_MAX) return -1;
            if (dist[i] > maxDist) maxDist = dist[i];
        }

        return maxDist;
    }
};

// Edsger W. Dijkstra: Dutch mathematician and computer scientist.
