// Author: Fatih Baskın
// Question Link: https://leetcode.com/problems/validate-binary-search-tree/
// Reviewer: Denis Davidoglu & Ceren Yaşar

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

/**
 * Solution by using inorder traversal.
 * If you traverse a binary search tree using inorder traversal, you would get a sorted list.
 * With this logic, first traverse the tree using recursive function then check whether the list is it sorted.
 * If it is sorted, then we can claim that tree is a valid binary search tree.
 *
 * Time Complexity: O(n), n refers to number of nodes
 * Space Complexity: O(n), n refers to number of nodes
 */

class Solution {
   public:
    // Storing the result of the traversal in this vector
    vector<int> traversal;
    // Solution fuction
    bool isValidBST(TreeNode* root) {
        // Calling the recursive traversal function
        inorder(root);
        // Then checking whether sorted
        // Since left node is smaller than the right node, by doing inorder traversal
        // we can expect this vector to be strictly increasing.
        for (int i = 1; i < traversal.size(); i++) {
            // If current value is smaller than the previous value, return false
            if (traversal[i] <= traversal[i - 1]) {
                return false;
            }
        }
        // If the traversal generated is sorted, then return true
        return true;
    }
    // Traversal Function
    void inorder(TreeNode* root) {
        // If current node is NULL, return current function (break recursion from here)
        if (root == NULL) return;
        // First check left node
        inorder(root->left);
        // Store current value
        traversal.push_back(root->val);
        // Then check right node
        inorder(root->right);
    }
};
