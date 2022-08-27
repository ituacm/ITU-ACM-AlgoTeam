// Author: Bilgenur Çelik
// Question Link: https://leetcode.com/problems/minimum-absolute-difference-in-bst/

class Solution {
public:
    // as provided by constraints a value can't be negative, thus initialize the previous value with -1
    int prev_val = -1;
    // minimum difference
    int min_diff = INT_MAX;


    // this is an inorder traversal alike function
    // to achieve min_diff, min_diff will be compared to the difference between
    // value at that position and the previous value
    void inorder(TreeNode* node) {
        // if we are below leaf nodes return
        if(node == NULL)
            return;

        // recurse through left
        inorder(node->left);

        // min_dif will be updated only if prev_val is already set
        if(prev_val > -1)
            min_diff = min(min_diff, node->val - prev_val);

        // prev_val will be updated each step
        prev_val = node->val;

        // recurse through left
        inorder(node->right);
    }

    int getMinimumDifference(TreeNode *root) {
        // send root to recursive function and return the updated minimum difference
        inorder(root);
        return min_diff;
    }
};

// Time comp.-> O(N)
// Space comp.-> O(1)

