// Author: Ahmet Furkan Kavraz
// Question Link: https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/

class Solution {
public:
    // result will be saved in totalCount
    int totalCount = 0;

    int averageOfSubtree(TreeNode* root) {
        // traverse the all nodes
        traverse(root);

        // return the result
        return totalCount;
    }

    pair<int, int> traverse(TreeNode* node) {
        // base case
        if (node == NULL)
            return make_pair(0, 0);

        // traverse the SubTrees
        pair<int, int> leftSubTreeResult = traverse(node->left);
        pair<int, int> rightSubTreeResult = traverse(node->right);

        // calculate the sum and count values
        int sum = leftSubTreeResult.first + rightSubTreeResult.first + node->val;
        int count = leftSubTreeResult.second + rightSubTreeResult.second + 1;

        // if the average equals to the value of current node, increment totalCount
        if (sum / count == node->val)
            totalCount++;

        // return necessary values
        return make_pair(sum, count);
    }
};