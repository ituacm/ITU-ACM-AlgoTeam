// Author: Ceren Yaşar
// Question Link: https://leetcode.com/problems/merge-two-binary-trees/description/
// Reviewer: Denis Davidoglu

// Time Complexity: O(min(m, n))
// m, n denote the number of nodes in the trees
// Space Complexity: O(min(m, n)) --> number of times the recursive function is called in stack

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

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // If one of the roots are null, return the other.
        if (!root1) return root2;
        if (!root2) return root1;

        // At this point of the program we know for sure that neither of the nodes are null so we can safely operate on their values.
        // Make all operations on root1 because that is the tree we decided to return.
        root1->val += root2->val;

        root1->right = mergeTrees(root1->right, root2->right);
        root1->left = mergeTrees(root1->left, root2->left);

        return root1;
    }
};
