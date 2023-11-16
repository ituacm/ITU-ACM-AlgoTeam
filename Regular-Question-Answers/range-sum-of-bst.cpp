// Author: Ceren Yaşar
// Question Link: https://leetcode.com/problems/range-sum-of-bst/
// Reviewer: Denis Davidoglu

// Time Comlplexity: O(N)
// Space Complexity: O(logN) --> because of the stack memory used by the recursive function 'dfs'.
// The maximum number of times the function 'dfs' will be called is the depth of the tree.

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

// To add all values in range [low, high], we must iterate over the tree utilizing depth-first search (DFS).
// DFS function is declared below:

class Solution {
    int sum = 0;

    void dfs(TreeNode* cursor, int low, int high) {
        if (cursor == nullptr) return;

        if (cursor->val < low) {
            // If the current node has a value less than the lower bound, there is no need to visit its left children since
            // we know for sure that they will be less than the current node value (because this is a binary search tree).
            // We can call the dfs function only for the right subtree.
            dfs(cursor->right, low, high);
            return;
        }

        if (cursor->val > high) {
            // If the current node has a value larger than the upper bound, there is no need to visit its right children since
            // we know for sure that they will be larger than the current node value (because this is a binary search tree).
            // We can call the dfs function only for the left subtree.
            dfs(cursor->left, low, high);
            return;
        }

        // If we reach this point in the function, current value falls within the range [low, high] and it is safe to check
        // both left and right subtrees of this node.
        sum += cursor->val;
        dfs(cursor->right, low, high);
        dfs(cursor->left, low, high);
    }

   public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        dfs(root, low, high);
        return sum;
    }
};
