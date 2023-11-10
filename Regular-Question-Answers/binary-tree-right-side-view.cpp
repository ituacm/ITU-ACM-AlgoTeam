// Author: Ömer Kural
// Question Link: https://leetcode.com/problems/binary-tree-right-side-view/

// Complexity: O(N)


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    /*
    * If we reshape the question, it actually wants us to get the rightmost element of every layer of the tree.
    *
    * GENERAL IDEA:
    * 1 - We traverse the tree layer by layer rather than node by node, we use breadth first search to do it.
    * 
    * 2 - Queue is a FIFO data structure, we can make use of this feature when we are solving this problem.
    *     While we are pushing the current layer to the queue, we start from the rightmost element.
    *     We do this to produce a queue that contains the layer nodes right to left.
    * 
    * 3 - We need the rightmost element of each layer of the tree.
    *     We can easily push the front element of the queue at each iteration to our answer vector.
    */

    vector<int> rightSideView(TreeNode* root) {
        // If tree is empty we return an empty array.
        if (!root) return {};

        // This is our answer vector.
        vector<int> rightSide;

        // We will be using breadth first search.
        queue<TreeNode*> bfs;
        bfs.push(root);

        while (!bfs.empty())
        {
            // We know that the front element is the rightmost element of our layer because of the way we are pushing the nodes to our queue.
            rightSide.push_back(bfs.front()->val);

            // We are getting the layer length and starting to traverse the queue "layerLength" times. This is our current layer.
            int layerLength = bfs.size();
            for (int i = 0; i < layerLength; i++)
            {
                TreeNode* curNode = bfs.front();
                bfs.pop();

                // The order here is very important, we are pushing the right node first 
                // to later get the rightmost element from the layer easily. If we were to do it in
                // a reversed manner, we would have the "left view" of our tree in the end.
                if (curNode->right) bfs.push(curNode->right);
                if (curNode->left) bfs.push(curNode->left);
            }
        }
        return rightSide;
    }
};