// Author: Murat Biberoğlu
// Reviewer: Ahmet Furkan Kavraz
// Question Link: https://leetcode.com/problems/minimum-depth-of-binary-tree/

// to solve this problem we need to get levels of each leaf node
// and compare it with a variable which holds current minimum depth of tree
// to do so we are going to use preorder tree traversal
class Solution {
   public:
    int minDepth = INT_MAX;  // variable that holds minimum depth
    int level;               // variable that holds current level

    int minDepth(TreeNode *root) {
        if (root) {
            level = 1;  // initialize root level as 1
            preOrder(root);
            return minDepth;
        }
        return 0;
    }

    void preOrder(TreeNode *node) {
        // if null exit
        if (node == nullptr) {
            return;
        }

        // leaf condition: right and left childs must be null
        // if it is a leaf node compare with minDepth
        if (node->right == nullptr && node->left == nullptr) {
            minDepth = min(minDepth, level);
        }

        level++;  // increment level beacuse we are going to childs
        preOrder(node->left);
        preOrder(node->right);
        level--;  // decrement level beacuse we are returning to parent
    }
};