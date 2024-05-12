// Author: Bilgenur Çelik
// Problem Link: https://leetcode.com/problems/binary-tree-tilt/description/

/* The tilt of a node is defined as the absolute difference between the sum of all left subtree values and the sum of all right subtree values.
 * The tilt of the whole tree is defined as the sum of all node tilts.
 * To solve the problem, recursion and a helper function can be used.
 * The helper function will calculate the sum of the left and right subtrees of the current node and add the tilt of the current node to the total tilt.
 */

class Solution {
public:
    // store the total tilt
    int tilt = 0;

    // helper function to calculate the tilt of the tree
    int traverse(TreeNode* root) {
        if (root == NULL) return 0;

        // recursively calculate the sum of left and right subtrees
        int left_sum = traverse(root->left);
        int right_sum = traverse(root->right);

        // add the tilt of the current node to the total tilt
        tilt += abs(left_sum - right_sum);
        // return the sum of the current subtree
        return root->val + left_sum + right_sum;
    }

    int findTilt(TreeNode* root) {
        // call the helper function
        traverse(root);
        return tilt;
    }
};
