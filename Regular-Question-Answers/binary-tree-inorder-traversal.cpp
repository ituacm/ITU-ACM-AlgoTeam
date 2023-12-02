// Author: Fatih Baskın
// Reviewer: Ahmet Furkan Kavraz
// Question Link: https://leetcode.com/problems/binary-tree-inorder-traversal/

// Complexity: O(n), n refers to nodes.

/**
 * Inorder traversal means say left, middle, right.
 * Ex:
 *       1
 *      / \
 *     2   3
 *    / \   \
 *   4   5   6
 *
 * Inorder traversal: 4 2 5 1 3 6
 */

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // Storage vector.
        vector<int> result;

        // Will use inorder recursive traversal to store values.
        recursiveTraversal(root, result);

        // Result.
        return result;
    }

    void recursiveTraversal(TreeNode* node, vector<int>& result) {
        // First, if current node is NULL, break the function (return)
        if (node == NULL) {
            return;
        }

        // Then, it will call itself for left node,
        recursiveTraversal(node->left, result);

        // After that, it will save its current value into result vector.
        // We want to be able to modify this vector from our recursive calls, this is why we have passed by reference. (&)
        result.push_back(node->val);

        // And finally, it will call itself for right node. This way we have done inorder traversal: left, middle, right.
        recursiveTraversal(node->right, result);
    }
};
