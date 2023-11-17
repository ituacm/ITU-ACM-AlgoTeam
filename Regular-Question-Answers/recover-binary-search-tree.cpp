// Author       : Fatih Baskın
// Reviewer     : Rojen Arda Şeşen
// Question Link: https://leetcode.com/problems/recover-binary-search-tree/

// Time Complexity : O(nlogn)
// Space Complexity: O(n)

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
private:
    // If you traverse a binary search tree inorder, you would get a sorted array.
    vector<int> numbers;
    // Index for inorderPlacer vector
    int vectorIndex = 0;
    // That is why we will use a inorder traversal function
    void inorderTraversal(TreeNode *root) {
        // Edge case, if function jumps to NULL pointer, terminate
        if (root == nullptr)
            return;
        // First go left
        inorderTraversal(root->left);
        // Then push the value into vector
        numbers.push_back(root->val);
        // Finally go right
        inorderTraversal(root->right);
    }
    // Then we will traverse inorder again and place values correctly.
    void inorderCorrecter(TreeNode *root) {
        // Edge case, if function jumps to NULL pointer, terminate
        if (root == nullptr)
            return;
        // First go left
        inorderCorrecter(root->left);
        // Then place the current pointed value to node and increment pointer
        root->val = numbers[vectorPointer];
        vectorIndex += 1;
        // Finally go right
        inorderCorrecter(root->right);
    }

public:
    void recoverTree(TreeNode *root) {
        // First traverse the tree inorderly
        inorderTraversal(root);
        // Then sort the numbers
        sort(numbers.begin(), numbers.end());
        // Finally place them correctly
        inorderCorrecter(root);
    }
};
