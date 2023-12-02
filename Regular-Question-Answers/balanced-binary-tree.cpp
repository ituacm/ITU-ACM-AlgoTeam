// Author: Ömer Kural
// Question Link: https://leetcode.com/problems/balanced-binary-tree/

// Complexity: O(N)

#include <bits/stdc++.h>
using namespace std;

/*
 * A height-balanced binary tree is a binary tree
 * in which the depth of the two subtrees of every node
 * never differs by more than one.
 */

class Solution {
public:
    /*
     * GENERAL IDEA: (bottom up)
     * We travel to the null nodes and start from there
     * and while we are going up (backtracking), we claculate the height of each node we are visiting.
     * height of the current node = 1 + max(heights of the children)
     * And while doing so, we check if the children are balanced or not.
     */

    int DFS(TreeNode* root, int curDepth) {
        // base case -> null node
        // if we are at a null node, the depth is 0
        if (!root) return 0;

        // recursively calculate the depths of left and right subtrees
        int leftSubtree = DFS(root->left, curDepth + 1);
        int rightSubtree = DFS(root->right, curDepth + 1);

        // if either of our subtrees returned -1 while calculating depths,
        // it means that the "abs(l-r) > 1" condition here has triggered for it
        // and that means it is unbalanced.
        // if not, we check if the current subtree is unbalanced
        if (leftSubtree == -1 || rightSubtree == -1 ||
            abs(leftSubtree - rightSubtree) > 1) return -1;

        // calculate the height of current subtree
        return 1 + max(leftSubtree, rightSubtree);
    }

    bool isBalanced(TreeNode* root) {
        // if there is no tree, it's considered to be balanced
        if (!root) return true;

        // if our DFS function returned -1, we know that at some point in the recursion
        // it found a subtree that is unbalanced
        // if not, the whole tree is balanced
        return (DFS(root, 0) != -1);
    }
};