// Author: Bilgenur Çelik
// Question Link: https://leetcode.com/problems/minimum-absolute-difference-in-bst/
// Reviewer: Hacer Akıncı

/*
 * The question premise is the input will be a valid binary search tree.
 * Recall that it is a binary tree with these properties:
 * - The value in each node must be greater than (or equal to) any values stored in its left subtree.
 * - The value in each node must be less than (or equal to) any values stored in its right subtree.
 *
 * example binary search tree: [23, 10, 70, null, 22, 25, 91]
 * tree form:
 *               23
 *       10              70
 *          22        25    91
 *
 * It is asked to find the minimum difference between any two nodes.
 * Because of bst properties, its inorder traversal form is sorted.
 * inorder form: 10 22 23 25 70 91
 * Thus, we can keep the previous value and find the difference between it and the current value.
 */

class Solution {
public:
    // as provided by constraints a value can't be negative, thus initialize the previous value with -1
    int previous = -1;
    // minimum difference
    int minDiff = INT_MAX;

    // this is an inorder traversal alike function
    // to achieve minDiff, minDiff will be compared to the difference between
    // value at that position and the previous value
    void inorder(TreeNode* node) {
        // if we are below leaf nodes return
        if (node == NULL)
            return;

        // recurse through left
        inorder(node->left);

        // min_dif will be updated only if previous is already set
        if (previous > -1)
            minDiff = min(minDiff, node->val - previous);

        // previous will be updated each step
        previous = node->val;

        // recurse through right
        inorder(node->right);
    }

    int getMinimumDifference(TreeNode* root) {
        // send root to recursive function and return the updated minimum difference
        inorder(root);
        return minDiff;
    }
};

// Time comp.-> O(N)
// Space comp.-> O(1)
