// Author: İrem Taze
// Question Link: https://leetcode.com/problems/maximum-depth-of-binary-tree
// Time Complexity : O(n) n= number of nodes, because we visit every node
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// finding maximum number function
int max(int a, int b) {
    return (a > b) ? a : b;
}

class Solution {
public:
    // Calculates the maximum depth of a binary tree.
    int maxDepth(TreeNode* root) {
        // if root is null pointer, terminate the program
        if (root == nullptr) return 0;

        // apply recursive approach, substitute to subtrees
        int max_left = maxDepth(root->left);
        int max_right = maxDepth(root->right);

        // choose the maximum depth
        int max_depth = max(max_left, max_right);

        // add the current node
        return max_depth + 1;
    }
};
