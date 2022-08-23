// Author: Murat Biberoğlu
// Question Link: https://leetcode.com/problems/n-ary-tree-level-order-traversal/

class Solution {
   public:
    // we are going to us breadth first search algorithm (bfs) to solve this
    // question, because we need to get nodes consecutive that have the same level.
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> levels;
        // if there is no node, then return empty vector
        if (!root) {
            return levels;
        }

        // Basic Iterative BFS
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            // get the size of the queue before adding new childs.
            // in that state queue has nodes that have same level.
            int levelSize = q.size();
            // create a vector with size as current level's node count
            vector<int> levelValues(levelSize);
            for (int i = 0; i < levelSize; i++) {
                Node* node = q.front();
                q.pop();
                levelValues[i] = node->val;

                // traverse the children and add to queue
                for (Node* child : node->children) {
                    q.push(child);
                }
            }
            levels.push_back(levelValues);
        }
        return levels;
    }
};
