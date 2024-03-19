// Author: Ali Kemal Coşkun
// Question Link: https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/

// Time Complexity: O(m*n*log(m*n)) m*n is the size of the grid
// Space Complexity: O(m*n) m*n is the size of the grid

/*
 * The question asks us to pass through the least number of obstacles and reach the end of the grid.
 * We can think of the grid as a graph and traverse the grid with DFS or BFS.
 * It may be a good method to use BFS and keep the number of obstacles required to reach that node for each node.
 * But the BFS traverse does not always guarantee us the lowest number of obstacles.
 * Can we create an algorithm that will give us the right result if we choose the node with
 * the lowest number of obstacles in each BFS iteration (similar to greedy algorithms)?
 *
 * Let's think about it: at any time T we choose the node with the lowest number of obstacles,
 * but a path with more obstacles at that time T will have fewer obstacles at the end of the algorithm.
 * Can we get the right result in this case? Actually... yes. Because at time T'>T,
 * the path we chose at time T will not have the lowest number of obstacles(otherwise that would be the answer :) )
 * and will fall back in the queue. So we can reach the correct result by updating the queue every iteration
 * and selecting the node with the least number of obstacles.
 *
 * To get a queue that will update itself every iteration, we can use our old friend priority queue.
 * Since we need to keep x and y values as well as the number of obstacles, we need to write a custom comparator.
 *
 * We need to update the queue every iteration, so the time complexity of the algorithm will be O(m*n*log(m*n))
 * where m*n is the size of the grid.
 *
 *
 * BFS on a matrix: https://www.geeksforgeeks.org/breadth-first-traversal-bfs-on-a-2d-array/
 * Custom comparator for priority queue: https://www.geeksforgeeks.org/custom-comparator-in-priority_queue-in-cpp-stl/
 * Dijkstra's algorithm: https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
 */

// Custom comparator for the priority queue.
struct pairPairCompare {
    bool operator()(
        pair<int, pair<int, int>> &a,
        pair<int, pair<int, int>> &b) {
        // pair<int, pair<int, int>> : number of obstacles, x, y. We want to sort the priority queue by the number of obstacles.
        return (a.first > b.first);
    }
};

class Solution {
public:
    // A helper function to check if the given x and y values are inside the grid.
    bool isInside(int x, int y, int m, int n) {
        if (x < 0 || x >= m || y < 0 || y >= n)
            return false;
        return true;
    }

    int minimumObstacles(vector<vector<int>> &grid) {
        // Directions to move in the grid.
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int m = grid.size();
        int n = grid[0].size();
        int x, y;

        // Is there an obstacle in the starting node(cell)?
        int numOfObstacles = grid[0][0];

        // Keep the minimum number of obstacles required to reach the current cell.
        vector<vector<int>> minObstacles(m, vector<int>(n, INT_MAX));

        // A priority queue to keep the nodes with the least number of obstacles. pairPairCompare is our custom comparator.
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, pairPairCompare> pq;
        // We start from the first cell.
        pq.push({numOfObstacles, {0, 0}});

        while (!pq.empty()) {
            numOfObstacles = pq.top().first;
            x = pq.top().second.first;
            y = pq.top().second.second;
            pq.pop();

            // If there is an obstacle in the current cell, we increment the number of obstacles.
            numOfObstacles += grid[x][y];

            // If we reach the end of the grid, we return the result.
            if (x == m - 1 && y == n - 1)
                return numOfObstacles;

            for (auto dir : directions) {
                if (!isInside(x + dir.first, y + dir.second, m, n))
                    continue;

                // Optimization: If we have already found a path with fewer obstacles to reach the current cell
                // we do not need to update the queue.
                if (numOfObstacles >= minObstacles[x + dir.first][y + dir.second])
                    continue;

                // Update minimum number of obstacles required to reach the current cell.
                minObstacles[x + dir.first][y + dir.second] = numOfObstacles;
                pq.push({numOfObstacles, {x + dir.first, y + dir.second}});
            }
        }
        return -1;
    }
};